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
	  levelMultiplier_(1),
	  level_(1)
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
//    setupTriples(gameP);
    setupControllers(gameP);
    determineShooters();
}

void Game::cycle() {
	HUD_->draw();
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
						HUD_->changePoints(ship->getPoints());
					}
				}
			}
		}

		// Check if our spaceShip is dead.
		for (auto triple : entityControllers_) {
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
				if (->checkRelevant(width_, height_)) {
					mvcTriples_.erase(mvcTriples_.begin()+i);
					change = true;
					break;
				}
			}

			for (unsigned int i = 0; i < enemies_.size(); i++) {
				for (unsigned int j = 0; j < enemies_.at(i).size(); j++) {
					if (enemies_.at(i).at(j) != nullptr && !(enemies_.at(i).at(j))->checkRelevant(width_, height_)) {
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

		HUD_->drawEnd();
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
			(enemies_.at(highest).at(column))->setFlags(false, true);
		}
	}
}

void Game::render() {
	for (auto controller : entityControllers_) {
		controller->draw();
	}
}

void Game::setupEnemies(factories::GameParser game) {
	std::shared_ptr<factories::AbstractFactory> factory = std::make_shared<factories::EnemyShipFactory>();
	int space = 0;
	try {
		std::vector<infoTuple> enemyInfo = game.getEnemyInfo();
		for (unsigned int i = 0; i < enemyInfo.size(); i++) {
			int amount = std::get<0>(enemyInfo.at(i));
//			int space_amount = std::get<1>(enemyInfo.at(i));
//			std::string file = std::get<2>(enemyInfo.at(i));
			std::string order = std::get<3>(enemyInfo.at(i));
//			int moveAmount = std::get<4>(enemyInfo.at(i));
//			double speed = std::get<5>(enemyInfo.at(i));

			std::vector<std::shared_ptr<controllers::EnemyShipController> > row;
			if (order.size() != amount) {
				throw Exception("Every row order should have the same amount of characters as the maxSize of all the enemy rows.");
			}
				for (auto c : order) {
					if (c == 'x') {
						controllerPtr enemyC = factory->getEntity(game.getFileName(), window_);
//						triple = factory->createEnemyShip(file, space, moveAmount, window_, speed);
//						row.push_back(triple);
//						mvcTriples_.push_back(triple);
						std::shared_ptr<controllers::EnemyShipController> esc = std::dynamic_pointer_cast<controllers::EnemyShipController>(enemyC);
						row.push_back(esc);
						entityControllers_.push_back(enemyC);
//						space += space_amount;
					}
					else if (c == ' ') {
						row.push_back(nullptr);
//						space += space_amount;
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
	enemies_ = rhs.enemies_;
	HUD_ = rhs.HUD_;
	levelMultiplier_ = rhs.levelMultiplier_;
	return *this;
}

void Game::nextLevel() {
	HUD_->addLevel(1);

	enemies_.clear();
	factories::GameParser gameP;
	gameP.parseGame("Data/game1.xml");
	this->setupEnemies(gameP);

//	// Increase their speed.
	for (unsigned int i = 0; i < enemies_.size(); i++) {
		for (unsigned int j = 0; j < enemies_.at(i).size(); j++) {
			if (enemies_.at(i).at(j) != nullptr) {
				std::shared_ptr<controllers::MovingObjectController> movC = std::dynamic_pointer_cast<controllers::MovingObjectController>(enemies_.at(i).at(j));
				movC->changeSpeed(levelMultiplier_ * level_);
			}
		}
	}
	level_++;
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

void Game::setupControllers(factories::GameParser game) {
	// Make our factory.
//	std::shared_ptr<factories::MainFactory> factory = std::make_shared<factories::Factory>();

	std::shared_ptr<factories::AbstractFactory> factory = std::make_shared<factories::SpaceShipFactory>();
	controllerPtr spaceC = factory->getEntity(game.getSpaceShipXML(), window_);
	entityControllers_.push_back(spaceC);
	spaceShipController_ = std::dynamic_pointer_cast<controllers::SpaceShipController>(spaceC);
	// Set up HUD
	factory = std::make_shared<factories::HUDFactory>();
    HUD_ = std::dynamic_pointer_cast<std::shared_ptr<controllers::HUDController> >(factory->getEntity(game.getSpaceShipXML(), spaceShipController_->getSpaceShip(), window_));

    /* --- */

	// Setup shields
    factory = std::make_shared<factories::ShieldFactory>();
	infoTuple shieldInfo = game.getShieldInfo();
	int amount = std::get<0>(shieldInfo);
	int space_amount = std::get<1>(shieldInfo);
	std::string file = std::get<2>(shieldInfo);
	int space = 0;

	for (int i = 0; i < amount; i++) {
		entityControllers_.push_back(factory->getEntity(game.getFileName(), window_));
		// Work with spacing in the factory.
	}

	this->setupEnemies(game);
}




} /* namespace game */
