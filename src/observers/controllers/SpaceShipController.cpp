/*
 * SpaceShipController.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "SpaceShipController.h"

namespace controllers {

SpaceShipController::SpaceShipController(modelPtr model, modelViewPtr view, factories::DataParser data)
	: ShipController(model, view, data)
{
}

SpaceShipController::~SpaceShipController() {
	// TODO Auto-generated destructor stub
}

void SpaceShipController::handleShooting(std::vector<controllerPtr>& entities) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && model_->shoot()) {
		// Shoot!
		std::shared_ptr<factories::AbstractFactory> factory = std::make_shared<factories::BulletFactory>();
		entities.push_back(factory->getEntity("Data/regularAmmo.xml", model_, view_->getWindow()));
	}
}

void SpaceShipController::handleMoveInput(unsigned int width, unsigned int height) {
// Possible support for diagonal movement needs to be implemented.
	if (moveDir_ == none) {
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (moveDir_ != none && moveDir_ != y) {
			// move left
			if (model_->getPosition().x > 0) {
				model_->moveLeft();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (moveDir_ != none && moveDir_ != y) {
			// move right
			if (model_->getPosition().x + model_->getBounds().width < width) {
				model_->moveRight();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (moveDir_ != none && moveDir_ != x ) {
			// move up
			if (model_->getPosition().y > 0) {
				model_->moveUp();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (moveDir_ != none && moveDir_ != x) {
			// move up
			if (model_->getPosition().y + model_->getBounds().height < height) {
				model_->moveDown();
			}
		}
	}
}

modelPtr SpaceShipController::getSpaceShip() {
	return model_;
}

bool SpaceShipController::checkDead() {
	std::shared_ptr<models::SpaceShip> spaceShip = std::dynamic_pointer_cast<models::SpaceShip>(model_);
	if (spaceShip != nullptr && spaceShip->getLives() <= 0) {
		return true;
	}
	else {
		return false;
	}
}



} /* namespace controllers */
