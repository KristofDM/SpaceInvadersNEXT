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
	/*
	 * Parse the main game file.
	 */
	factories::GameParser gameP;
	gameP.parseGame("Data/game1.xml");

	levelMultiplier_ = gameP.getSpeedMult();

	//Setup triples.
    setupControllers(gameP);
    determineShooters();
}

void Game::cycle() {
	HUD_->draw();
	if (!this->endGame()) {
		for (auto c : entityControllers_) {
			// Gameinput will mainly take care of the shooting and moving of the entities.
			c->gameInput(entityControllers_, width_, height_);
		}

		// Collision detection.
		for (unsigned int i = 0; i < entityControllers_.size(); i++) {
			for (unsigned int j = i; j < entityControllers_.size(); j++) {
				if (entityControllers_.at(i) == entityControllers_.at(j)) {
					// Same object, no point in checking for collision.
					continue;
				}
				else {
					// Check for collision.
					if ((entityControllers_.at(i))->checkCollision(entityControllers_.at(j)->getModel())) {
						// Handle collision.
						if ((entityControllers_.at(i))->collided(entityControllers_.at(j)->getModel())) {
							// Mark for deletion.
							entityControllers_.at(i)->markDeleted();
						}
						if ((entityControllers_.at(j))->collided(entityControllers_.at(i)->getModel())) {
							// Mark for deletion.
							entityControllers_.at(j)->markDeleted();
						}
					}
				}
			}
		}

		// Take care of our points and check if there was a fatal collision.
		for (unsigned int i = 0; i < enemies_.size(); i++) {
			for (unsigned int j = 0; j < enemies_.at(i).size(); j++) {
				std::shared_ptr<controllers::EnemyShipController> c = enemies_.at(i).at(j);
				if (c != nullptr) {
					if (c->getFatalCollision()) {
						gameOver_ = true;
					}

					if (!c->checkRelevant(width_, height_)) {
						HUD_->changePoints(c->getPoints());
					}
				}
			}
		}

		// Check if our spaceShip is dead.
		if (spaceShipController_->checkDead()) {
			gameOver_ = true;
		}

		// Get rid of objects that are outside of the window.
		bool change = true;
		while (change) {
			change = false;
			for (unsigned int i = 0; i < entityControllers_.size(); i++) {
				if (!entityControllers_.at(i)->checkRelevant(width_, height_)) {
					entityControllers_.erase(entityControllers_.begin()+i);
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
		for (int j = 0; j < int(enemies_.size()); j++) {
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

std::vector<controllerPtr> Game::getEntities() {
	return entityControllers_;
}

void Game::setupEnemies(factories::GameParser game) {
	std::shared_ptr<factories::AbstractFactory> factory = std::make_shared<factories::EnemyShipFactory>();
	int space = 0;
	try {
		std::vector<infoTuple> enemyInfo = game.getEnemyInfo();
		for (unsigned int i = 0; i < enemyInfo.size(); i++) {
			unsigned int amount = std::get<0>(enemyInfo.at(i));
			int space_amount = std::get<1>(enemyInfo.at(i));
			std::string order = std::get<3>(enemyInfo.at(i));

			std::vector<std::shared_ptr<controllers::EnemyShipController> > row;
			if (order.size() != amount) {
				throw Exception("Every row order should have the same amount of characters as the maxSize of all the enemy rows.");
			}
				for (auto c : order) {
					if (c == 'x') {
						controllerPtr enemyC = factory->getController(game.getFileName(), i, space, window_);
						std::shared_ptr<controllers::EnemyShipController> esc = std::dynamic_pointer_cast<controllers::EnemyShipController>(enemyC);
						row.push_back(esc);
						entityControllers_.push_back(enemyC);
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
	enemies_ = rhs.enemies_;
	entityControllers_ = rhs.entityControllers_;
	HUD_ = rhs.HUD_;
	levelMultiplier_ = rhs.levelMultiplier_;
	level_ = rhs.level_;
	return *this;
}

void Game::nextLevel() {
	HUD_->addLevel(1);

	enemies_.clear();
	factories::GameParser gameP;
	gameP.parseGame("Data/game1.xml");
	this->setupEnemies(gameP);

	// Increase enemy speed.
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
			// If all enemies are dead it's time for the next level.
			if (enemies_.at(i).at(j) != nullptr) {
				return false;
			}
		}
	}
	return true;
}

void Game::setupControllers(factories::GameParser game) {
	// Make our factory.
	std::shared_ptr<factories::AbstractFactory> factory = std::make_shared<factories::SpaceShipFactory>();
	controllerPtr spaceC = factory->getController(game.getSpaceShipXML(), window_);
	entityControllers_.push_back(spaceC);
	spaceShipController_ = std::dynamic_pointer_cast<controllers::SpaceShipController>(spaceC);

	// Set up HUD
	factory = std::make_shared<factories::HUDFactory>();
	controllerPtr HUD = factory->getController(game.getSpaceShipXML(), spaceShipController_->getSpaceShip(), window_);
    HUD_ = std::dynamic_pointer_cast<controllers::HUDController>(HUD);

	// Setup shields
    factory = std::make_shared<factories::ShieldFactory>();
	infoTuple shieldInfo = game.getShieldInfo();
	int amount = std::get<0>(shieldInfo);
	std::string file = std::get<2>(shieldInfo);

	for (int i = 0; i < amount; i++) {
		entityControllers_.push_back(factory->getController(game.getFileName(), window_));
	}

	this->setupEnemies(game);
}

} /* namespace game */
