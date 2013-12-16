/*
 * MovingObjectController.cpp
 *
 *  Created on: Dec 16, 2013
 *      Author: kristof
 */

#include "MovingObjectController.h"

namespace controllers {

MovingObjectController::MovingObjectController(modelPtr model, modelViewPtr view, factories::DataParser data)
	: Controller(model, view, data)
{}

MovingObjectController::~MovingObjectController() {
	// TODO Auto-generated destructor stub
}

void MovingObjectController::changeSpeed(double multiplier) {
	std::shared_ptr<models::MovingObject> obj = std::dynamic_pointer_cast<models::MovingObject>(model_);
	obj->changeSpeed(multiplier);
}


} /* namespace controllers */
