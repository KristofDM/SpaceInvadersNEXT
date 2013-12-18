/*
 * SpaceShipController.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: kristof
 */

#include "ShipController.h"

namespace controllers {

ShipController::ShipController(modelPtr model, modelViewPtr view, factories::DataParser data)
	: MovingObjectController(model, view, data)
{

	// Attach to Observer registry of model? No we don't need this... (yet).
	//std::shared_ptr<observers::Observer> thisController(this);
	//model_->attach(thisController);
}

void ShipController::gameInput(std::vector<controllerPtr>& entities, unsigned int width, unsigned int height) {
	this->handleMoveInput(width, height);
	this->handleShooting(entities);
}

void ShipController::setFlags(bool invincible, bool shooting) {
	model_->setFlags(invincible, shooting);
}

bool ShipController::getFatalCollision() {
	std::shared_ptr<models::Ship> ship = std::dynamic_pointer_cast<models::Ship>(model_);
	return ship->getFatalCollision();
}



} /* namespace controllers */
