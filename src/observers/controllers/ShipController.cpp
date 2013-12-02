/*
 * SpaceShipController.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: kristof
 */

#include "ShipController.h"

namespace controllers {

ShipController::ShipController(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser data)
	: Controller(model, view, data)
{

	// Attach to Observer registry of model? No we don't need this... (yet).
	//std::shared_ptr<observers::Observer> thisController(this);
	//model_->attach(thisController);
}

void ShipController::gameInput(std::vector<mvcTriple>& mvcTriples, unsigned int width, unsigned int height) {
	this->handleMoveInput(width, height);
	this->handleShooting(mvcTriples);
}



} /* namespace controllers */
