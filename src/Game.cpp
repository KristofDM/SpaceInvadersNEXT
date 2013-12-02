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

	factories::GameParser gameP;
	gameP.parseGame("Data/game1.xml");

    setupTriples(gameP);

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

void Game::setupTriples(factories::GameParser game) {

//	// Setup spaceship
//	factories::DataParser data;
//	data.parseObject(game.spaceShipXML_)
//	modelPtr model = std::make_shared<models::SpaceShip>(data);
//	model->setUp(data);

	// Setup factories?

	// model
	modelPtr model = std::make_shared<models::SpaceShip>(data);
	model->setUp(data);
	// View
	modelViewPtr view = std::make_shared<views::SpaceShipView>(model, data, window_);
	// Controller
	spaceShipController_ = std::make_shared<controllers::SpaceShipController>(model, view, data);

	std::shared_ptr<mvcTriple> test (new mvcTriple(model, view, spaceShipController_));
	mvcTriples_.push_back(test);

	/* --- */

	factories::DataParser data2;
	data2.parseObject("Data/enemyShip.xml");
	modelPtr model2 = std::make_shared<models::EnemyShip>(data2);
	model2->setUp(data2);

	modelViewPtr view2 = std::make_shared<views::SpaceShipView>(model2, data, window_);

	controllerPtr controller2 (new controllers::EnemyShipController(model2, view2, data2));

	test_.push_back(controller2);

	std::shared_ptr<mvcTriple> test2 (new mvcTriple(model2, view2, controller2));

	mvcTriples_.push_back(test2);

	/* --- */

	factories::DataParser data3;
	data3.parseObject("Data/shield1.xml");
	modelPtr model3 = std::make_shared<models::Shield>(models::none, data3.getLives(), 100);
	model3->setUp(data3);

	modelViewPtr view3 = std::make_shared<views::SpaceShipView>(model3, data3, window_);

	controllerPtr controller3 (new controllers::StaticController(model3, view3, data3));

	test_.push_back(controller3);

	std::shared_ptr<mvcTriple> test3 (new mvcTriple(model3, view3, controller3));

	mvcTriples_.push_back(test3);

	/* --- */

	factories::DataParser data4;
	data4.parseObject("Data/shield2.xml");
	modelPtr model4 = std::make_shared<models::Shield>(models::none, data4.getLives(), 100);
	model4->setUp(data4);

	modelViewPtr view4 = std::make_shared<views::SpaceShipView>(model4, data4, window_);

	controllerPtr controller4 (new controllers::StaticController(model4, view4, data4));

	test_.push_back(controller4);

	std::shared_ptr<mvcTriple> test4 (new mvcTriple(model4, view4, controller4));

	mvcTriples_.push_back(test4);

	/* --- */

	factories::DataParser data5;
	data5.parseObject("Data/shield.xml");
	modelPtr model5 = std::make_shared<models::Shield>(models::none, data5.getLives(), 100);
	model5->setUp(data5);

	modelViewPtr view5 = std::make_shared<views::SpaceShipView>(model5, data5, window_);

	controllerPtr controller5 (new controllers::StaticController(model5, view5, data5));

	test_.push_back(controller5);

	std::shared_ptr<mvcTriple> test5 (new mvcTriple(model5, view5, controller5));

	mvcTriples_.push_back(test5);
}


} /* namespace game */
