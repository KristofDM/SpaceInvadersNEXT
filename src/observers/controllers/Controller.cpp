/*
 * Controller.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#include "Controller.h"

namespace controllers {

Controller::Controller(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser data)
	: model_(model),
	  view_(view),
	  moveDir_(EMoveDirection(data.getMoveDirection()))
{}

Controller::~Controller() {
	std::shared_ptr<observers::Observer> thisController(this);
	model_->detach(thisController);
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

bool Controller::collided(std::shared_ptr<models::Model> other) {
	return model_->collided(other);
}

bool Controller::checkCollision(std::shared_ptr<models::Model> other) {
	return model_->checkCollision(other);
}



} /* namespace controllers */
