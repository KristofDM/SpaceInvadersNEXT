/*
 * Game.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: kristof
 */

#include "Game.h"

namespace game {

Game::Game(unsigned int width, unsigned int height, sf::RenderWindow& window)
	: width_(width),
	  height_(height),
	  window_(window),
	  gameOver_(false),
	  levelMultiplier_(1)
{}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::setUp() {

	/**
	 * Parse a game xml file and determine what models need to be made.
	 * Iterate over models, setupModel(), setupView() and setupController() will take care of 1 each and will be added in our triplets.
	 */

	factories::GameParser gameP;
	gameP.parseGame("Data/game1.xml");

	levelMultiplier_ = gameP.getSpeedMult();

	//Setup triples.
    setupTriples(gameP);
    determineShooters();
}

void Game::cycle() {
	std::get<2>(*HUD_)->draw();
	if (!this->endGame()) {

		unsigned int size = mvcTriples_.size();
		for (unsigned int i = 0; i < size; i++) {
			std::get<2>(*mvcTriples_[i])->gameInput(mvcTriples_, width_, height_);
		}

		// Collision detection.
		for (unsigned int i = 0; i < mvcTriples_.size(); i++) {
			for (unsigned int j = i; j < mvcTriples_.size(); j++) {
				if (mvcTriples_.at(i) == mvcTriples_.at(j)) {
					// Same object, no point in checking for collision.
					continue;
				}
				else {
					// Check for collision.
					if (std::get<2>(*mvcTriples_.at(i))->checkCollision(std::get<0>(*mvcTriples_.at(j)))) {
						// Handle collision.
						if (std::get<2>(*mvcTriples_.at(i))->collided(std::get<0>(*mvcTriples_.at(j)))) {
							// Mark for deletion.
							std::get<2>(*mvcTriples_.at(i))->markDeleted();
						}
						if (std::get<2>(*mvcTriples_.at(j))->collided(std::get<0>(*mvcTriples_.at(i)))) {
							// Mark for deletion.
							std::get<2>(*mvcTriples_.at(j))->markDeleted();
						}
					}
				}
			}
		}

		for (unsigned int i = 0; i < enemies_.size(); i++) {
			for (unsigned int j = 0; j < enemies_.at(i).size(); j++) {
				std::shared_ptr<mvcTriple> test = enemies_.at(i).at(j);
				if (test != nullptr) {
					modelPtr model = std::get<0>(*test);
					std::shared_ptr<models::EnemyShip> ship = std::dynamic_pointer_cast<models::EnemyShip>(model);
					if (ship->getFatalCollision()) {
						gameOver_ = true;
					}

					if (!std::get<2>(*test)->checkRelevant(width_, height_)) {
						std::shared_ptr<controllers::HUDController> HUDC = std::dynamic_pointer_cast<controllers::HUDController>(std::get<2>(*HUD_));
						HUDC->changePoints(ship->getPoints());
					}
				}
			}
		}

		// Check if our spaceShip is dead.
		for (auto triple : mvcTriples_) {
			modelPtr obj = std::get<0>(*triple);
			std::shared_ptr<models::SpaceShip> spaceShip = std::dynamic_pointer_cast<models::SpaceShip>(obj);
			if (spaceShip != nullptr && spaceShip->getLives() <= 0) {
				gameOver_ = true;
			}
		}

		// Get rid of objects that are outside of the window.
		bool change = true;
		while (change) {
			change = false;
			for (unsigned int i = 0; i < mvcTriples_.size(); i++) {
				if (!std::get<2>(*mvcTriples_.at(i))->checkRelevant(width_, height_)) {
					mvcTriples_.erase(mvcTriples_.begin()+i);
					change = true;
					break;
				}
			}

			for (unsigned int i = 0; i < enemies_.size(); i++) {
				for (unsigned int j = 0; j < enemies_.at(i).size(); j++) {
					if (enemies_.at(i).at(j) != nullptr && !std::get<2>(*enemies_.at(i).at(j))->checkRelevant(width_, height_)) {
						enemies_[i][j] = nullptr;
						change = true;
						break;
					}
				}
			}
			determineShooters();
		}

		if (this->checkForNextLevel()) {
			this->nextLevel();
		}
	}
	else {
		// Prompt for user input on what to do next. Restart or quit?

		std::shared_ptr<controllers::HUDController> HUDC = std::dynamic_pointer_cast<controllers::HUDController>(std::get<2>(*HUD_));
		HUDC->drawEnd();
	}
}

void Game::determineShooters() {
	// Determine what enemies are allowed to shoot.
	for (unsigned int column = 0; column < enemies_.at(0).size(); column++) {
		// Check highest column index.
		int highest = -1;
		for (int j = 0; j < enemies_.size(); j++) {
			if (enemies_.at(j).at(column) != 0 && j > highest) {
				highest = j;
			}
		}
		// Set the shooting flag to true unless there was no enemy left on that column.
		if (highest != -1) {
			std::get<2>(*enemies_.at(highest).at(column))->setFlags(false, true);
		}
	}
}

void Game::render() {
	for (auto triple : mvcTriples_) {
		std::get<2>(*triple)->draw();
	}
}

void Game::setupTriples(factories::GameParser game) {

	// Make our factory.
	std::shared_ptr<factories::MainFactory> factory = std::make_shared<factories::Factory>();

	std::shared_ptr<mvcTriple> triple = factory->createSpaceShip(game.getSpaceShipXML(), window_);
	mvcTriples_.push_back(triple);

	// Set up HUD
    HUD_ = factory->createHUD(game.getSpaceShipXML(), window_, std::get<0>(*triple));

    /* --- */

	// Setup shields
	infoTuple shieldInfo = game.getShieldInfo();
	int amount = std::get<0>(shieldInfo);
	int space_amount = std::get<1>(shieldInfo);
	std::string file = std::get<2>(shieldInfo);
	int space = 0;

	for (int i = 0; i < amount; i++) {
		triple = factory->createShield(file, space, window_);
		mvcTriples_.push_back(triple);
		space += space_amount;
	}

	this->setupEnemies(game);

}

void Game::setupEnemies(factories::GameParser game) {
	std::shared_ptr<mvcTriple> triple;
	std::shared_ptr<factories::MainFactory> factory = std::make_shared<factories::Factory>();
	int space = 0;
	try {
		std::vector<infoTuple> enemyInfo = game.getEnemyInfo();
		for (unsigned int i = 0; i < enemyInfo.size(); i++) {
			int amount = std::get<0>(enemyInfo.at(i));
			int space_amount = std::get<1>(enemyInfo.at(i));
			std::string file = std::get<2>(enemyInfo.at(i));
			std::string order = std::get<3>(enemyInfo.at(i));
			int moveAmount = std::get<4>(enemyInfo.at(i));
			double speed = std::get<5>(enemyInfo.at(i));

			std::vector<std::shared_ptr<mvcTriple> > row;
			if (order.size() != amount) {
				throw Exception("Every row order should have the same amount of characters as the maxSize of all the enemy rows.");
			}
				for (auto c : order) {
					if (c == 'x') {
						triple = factory->createEnemyShip(file, space, moveAmount, window_, speed);
						row.push_back(triple);
						mvcTriples_.push_back(triple);
						space += space_amount;
					}
					else if (c == ' ') {
						row.push_back(nullptr);
						space += space_amount;
					}
					else {
						throw Exception("Invalid symbol in a row order. You can only use spaces and x'es for the order.");
					}
				}
			space = 0;
			enemies_.push_back(row);
		}
	}
	catch(Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

bool Game::endGame() {
	return gameOver_;
}

Game& Game::operator=(const Game rhs)
{
	width_ = rhs.width_;
	height_ = rhs.height_;
	gameOver_ = rhs.gameOver_;
	spaceShipController_ = rhs.spaceShipController_;
	mvcTriples_ = rhs.mvcTriples_;
	enemies_ = rhs.enemies_;
	HUD_ = rhs.HUD_;
	levelMultiplier_ = rhs.levelMultiplier_;
	return *this;
}

void Game::nextLevel() {
	static int level = 1;
	std::shared_ptr<controllers::HUDController> HUDC = std::dynamic_pointer_cast<controllers::HUDController>(std::get<2>(*HUD_));
	HUDC->addLevel(1);

	enemies_.clear();
	factories::GameParser gameP;
	gameP.parseGame("Data/game1.xml");
	this->setupEnemies(gameP);

//	// Increase their speed.
	for (unsigned int i = 0; i < enemies_.size(); i++) {
		for (unsigned int j = 0; j < enemies_.at(i).size(); j++) {
			if (enemies_.at(i).at(j) != nullptr) {
				std::shared_ptr<controllers::MovingObjectController> movC = std::dynamic_pointer_cast<controllers::MovingObjectController>(std::get<2>(*enemies_.at(i).at(j)));
				movC->changeSpeed(levelMultiplier_ * level);
			}
		}
	}
	level++;
}

bool Game::checkForNextLevel() {
	for (unsigned int i = 0; i < enemies_.size(); i++) {
		for (unsigned int j = 0; j < enemies_.at(i).size(); j++) {
			if (enemies_.at(i).at(j) != nullptr) {
				return false;
			}
		}
	}
	return true;
}



} /* namespace game */
