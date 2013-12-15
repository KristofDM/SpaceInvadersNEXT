/*
 * HUDController.cpp
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#include "HUDController.h"

namespace controllers {

HUDController::HUDController(modelPtr model, modelViewPtr view, factories::DataParser data)
	: StaticController(model, view, data)
{}

HUDController::~HUDController() {
	// TODO Auto-generated destructor stub
}

void HUDController::changePoints(int points) {
	std::shared_ptr<models::HUD> hud = std::dynamic_pointer_cast<models::HUD>(model_);
	hud->changePoints(points);
}

void HUDController::changeLives(int lives) {
	std::shared_ptr<models::HUD> hud = std::dynamic_pointer_cast<models::HUD>(model_);
	hud->changeLives(lives);
}

} /* namespace controllers */
