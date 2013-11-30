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
    factories::DataParser data;

    data.parse("Data/SpaceShip.xml");

	setupModels(data);

	setupViews(data);

	setupControllers(data);
}

void Game::cycle() {
	handleMoveInput();
	handleShooting();

	// Bullets travel.
	for (auto bullet : staticControllers_) {
		bullet->handleMoveInput(width_, height_);
	}

	// Get rid of objects that are outside of the window.
	for (auto object : staticControllers_) {
		// Check models position, if it is outside of the window... erase from modelsVec/viewsVec/controllersVec (they are on the same index)
	}
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
}

void Game::setupViews(factories::DataParser data) {
	for (auto model : models_) {
		views_.push_back(std::make_shared<views::SpaceShipView>(model, data, window_));
	}
}

void Game::setupControllers(factories::DataParser data) {
	spaceShipController_ = std::make_shared<controllers::ShipController>(models_.at(0), views_.at(0), data);
	for (unsigned int i = 0; i < models_.size(); i++) {
		shipControllers_.push_back(spaceShipController_);
	}
}

} /* namespace game */
