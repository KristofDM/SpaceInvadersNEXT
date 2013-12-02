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

    setupTriples(data);

//	setupModels(data);
//
//	setupViews(data);
//
//	setupControllers(data);
}

void Game::cycle() {
	// User actions.
//	handleMoveInput();
//	handleShooting();

	// AI actions.

//	for (auto e : mvcTriples_) {
////		std::cout << "1" << std::endl;
//		std::get<2>(e)->gameInput(mvcTriples_, width_, height_);
////		std::cout << "2" << std::endl;
//	}

	unsigned int size = mvcTriples_.size();
	for (unsigned int i = 0; i < size; i++) {
		std::get<2>(mvcTriples_[i])->gameInput(mvcTriples_, width_, height_);
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
				if (std::get<0>(mvcTriples_.at(i))->checkCollision(std::get<0>(mvcTriples_.at(j)))) {
					// Handle collision.
					if (std::get<0>(mvcTriples_.at(i))->collided(std::get<0>(mvcTriples_.at(j)))) {
						// delete
						mvcTriples_.erase(mvcTriples_.begin() + i);
					}
					if (std::get<0>(mvcTriples_.at(j))->collided(std::get<0>(mvcTriples_.at(i)))) {
						// delete
						mvcTriples_.erase(mvcTriples_.begin() + j);
					}
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

//void Game::handleMoveInput() {
//	spaceShipController_->handleMoveInput(width_, height_);
//}
//
//void Game::handleShooting() {
//	spaceShipController_->handleShooting(mvcTriples_);
//}

void Game::render() {
	for (auto triple : mvcTriples_) {
		std::get<1>(triple)->draw();
	}
}

void Game::setupTriples(factories::DataParser data) {
	// model
	std::shared_ptr<models::Model> model = std::make_shared<models::SpaceShip>(data);
	model->setUp(data);
	// View
	std::shared_ptr<views::ModelView> view = std::make_shared<views::SpaceShipView>(model, data, window_);
	// Controller
	spaceShipController_ = std::make_shared<controllers::SpaceShipController>(model, view, data);

	mvcTriple test(model, view, spaceShipController_);
	mvcTriples_.push_back(test);

	/* --- */

	factories::DataParser data2;
	data2.parse("Data/enemyShip.xml");
	std::shared_ptr<models::Model> model2 = std::make_shared<models::EnemyShip>(data2);
	model2->setUp(data2);

	std::shared_ptr<views::ModelView> view2 = std::make_shared<views::SpaceShipView>(model2, data, window_);

	std::shared_ptr<controllers::Controller> controller2 = std::make_shared<controllers::EnemyShipController>(model2, view2, data2);

	mvcTriple test2(model2, view2, controller2);
	mvcTriples_.push_back(test2);

}


} /* namespace game */
