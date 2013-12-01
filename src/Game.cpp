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
	  window_(window)
{}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::setUp() {

	/**
	 * Parse a game xml file and determine what models need to be made.
	 * Iterate over models, setupModel(), setupView() and setupController() will take care of 1 each and will be added in our triplets.
	 */

    factories::DataParser data;

    // ITERATE OVER ALL MODELS
    data.parse("Data/SpaceShip.xml");
	setupModels(data);

	setupViews(data);

	setupControllers(data);
}

void Game::cycle() {
	// User actions.
	handleMoveInput();
	handleShooting();

	// AI actions.

	// Movement
	for (auto e : shipControllers_) {
		e->handleMoveInput(width_, height_);
	}

//	 Shooting
	for (auto e : shipControllers_) {
		e->handleShooting(models_, views_, staticControllers_);
	}

	// Bullets travel.
	for (auto bullet : staticControllers_) {
		bullet->handleMoveInput(width_, height_);
	}

	// Collision detection.

	for (unsigned int i = 0; i < models_.size(); i++) {
		for (unsigned int j = i; j < models_.size(); j++) {
			if (models_.at(i) == models_.at(j)) {
				// Same object, no point in checking for collision.
				continue;
			}
			else {
				// Check for collision.
				if (models_.at(i)->checkCollision(models_.at(j))) {
					// Handle collision.
					models_.at(i)->collided(models_.at(j));
					models_.at(j)->collided(models_.at(i));
				}
			}
		}
	}

//	// Get rid of objects that are outside of the window.
//	// Check models position, if it is outside of the window... erase from modelsVec/viewsVec/controllersVec (they are on the same index)
//	for (unsigned int i = 0; i < staticControllers_.size(); i++) {
//		if (!staticControllers_.at(i)->checkRelevant(width_, height_)) {
//			std::cout << "a" << std::endl;
//			staticControllers_.erase(staticControllers_.begin() + i);
//			std::cout << "b" << std::endl;
//		}
//	}
//
//	for (unsigned int i = 0; i < shipControllers_.size(); i++) {
//		if (!shipControllers_.at(i)->checkRelevant(width_, height_)) {
//			std::cout << "f" << std::endl;
//			shipControllers_.erase(shipControllers_.begin() + i);
//			std::cout << "g" << std::endl;
//		}
//	}
//
//	for (unsigned int i = 0; i < models_.size(); i++) {
//		if (!models_.at(i)->checkRelevant(width_, height_)) {
//			// If the object in question is no longer relevant...
//			// Delete it from the models vector.
//			std::cout << models_.size() << " " << views_.size() << std::endl;
//			models_.erase(models_.begin() + i);
//			std::cout << models_.size() << " " << views_.size() << std::endl;
//			views_.erase(views_.begin() + i);
//			std::cout << models_.size() << " " << views_.size() << std::endl;
//		}
//	}
}

void Game::handleMoveInput() {
	spaceShipController_->handleMoveInput(width_, height_);
}

void Game::handleShooting() {
	spaceShipController_->handleShooting(models_, views_, staticControllers_);
}

void Game::render() {
	for (auto view : views_) {
		view->draw();
	}
}

void Game::setupModels(factories::DataParser data) {
	std::shared_ptr<models::Model> model = std::make_shared<models::SpaceShip>(data);
	model->setUp(data);
    models_.push_back(model);

    factories::DataParser data2;
    data2.parse("Data/enemyShip.xml");
    std::shared_ptr<models::Model> model2 = std::make_shared<models::EnemyShip>(data2);
    model2->setUp(data2);
    models_.push_back(model2);
}

void Game::setupViews(factories::DataParser data) {
	for (auto model : models_) {
		views_.push_back(std::make_shared<views::SpaceShipView>(model, data, window_));
	}
}

void Game::setupControllers(factories::DataParser data) {
	spaceShipController_ = std::make_shared<controllers::SpaceShipController>(models_.at(0), views_.at(0), data);
	for (unsigned int i = 0; i < models_.size(); i++) {
		if (i == 0) {
			//shipControllers_.push_back(spaceShipController_);
		}
		else {
			factories::DataParser data2;
			data2.parse("Data/enemyShip.xml");
			shipControllers_.push_back(std::make_shared<controllers::EnemyShipController>(models_.at(i), views_.at(1), data2));
		}
	}
}

} /* namespace game */
