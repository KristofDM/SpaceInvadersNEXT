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
						// delete
						std::get<2>(*mvcTriples_.at(i))->markDeleted();

					}
					if (std::get<2>(*mvcTriples_.at(j))->collided(std::get<0>(*mvcTriples_.at(i)))) {
						// delete
						std::get<2>(*mvcTriples_.at(j))->markDeleted();
					}
				}
			}
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
	}
}

void Game::render() {
	for (auto triple : mvcTriples_) {
		std::get<1>(*triple)->draw();
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

	std::shared_ptr<mvcTriple> test (new mvcTriple(model, view, spaceShipController_));
	mvcTriples_.push_back(test);

	/* --- */

	factories::DataParser data2;
	data2.parse("Data/enemyShip.xml");
	std::shared_ptr<models::Model> model2 = std::make_shared<models::EnemyShip>(data2);
	model2->setUp(data2);

	std::shared_ptr<views::ModelView> view2 = std::make_shared<views::SpaceShipView>(model2, data, window_);

	std::shared_ptr<controllers::Controller> controller2 (new controllers::EnemyShipController(model2, view2, data2));

	test_.push_back(controller2);

	std::shared_ptr<mvcTriple> test2 (new mvcTriple(model2, view2, controller2));

	mvcTriples_.push_back(test2);
}


} /* namespace game */
