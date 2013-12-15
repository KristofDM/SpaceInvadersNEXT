/*
 * StaticController.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#include "StaticController.h"

namespace controllers {

StaticController::StaticController(modelPtr model, modelViewPtr view, factories::DataParser data)
	: Controller(model, view, data)
{}

StaticController::~StaticController() {
	// TODO Auto-generated destructor stub
}

void StaticController::setFlags(bool invincible, bool shooting) {
	model_->setFlags(invincible, shooting);
}


} /* namespace controllers */
