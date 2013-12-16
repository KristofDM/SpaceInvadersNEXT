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

void ShipController::gameInput(std::vector<std::shared_ptr<mvcTriple> >& mvcTriples, unsigned int width, unsigned int height) {
	this->handleMoveInput(width, height);
	this->handleShooting(mvcTriples);
}

void ShipController::setFlags(bool invincible, bool shooting) {
	model_->setFlags(invincible, shooting);
}



} /* namespace controllers */
