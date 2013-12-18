/*
 * Controller.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#include "Controller.h"

namespace controllers {

Controller::Controller(modelPtr model, modelViewPtr view, factories::DataParser data)
	: model_(model),
	  view_(view),
	  moveDir_(EMoveDirection(data.getMoveDirection()))
{}

Controller::~Controller() {
//	std::shared_ptr<observers::Observer> thisController(this);
//	model_->detach(thisController);

}

bool Controller::checkRelevant(unsigned int width, unsigned int height) {
	if (model_->getDeleted() || !model_->checkRelevant(width, height)) {
		return false;
	}
	else {
		return true;
	}
}

void Controller::markDeleted() {
	model_->markDeleted();
}

bool Controller::collided(modelPtr other) {
	return model_->collided(other);
}

bool Controller::checkCollision(modelPtr other) {
	return model_->checkCollision(other);
}

void Controller::setFlags(bool invincible, bool shooting) {
	model_->setFlags(invincible, shooting);
}

void Controller::draw() {
	view_->draw();
}

modelPtr Controller::getModel() {
	return model_;
}


} /* namespace controllers */
