/*
 * BulletController.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: kristof
 */

#include "BulletController.h"

namespace controllers {

BulletController::BulletController(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser data)
		: Controller(model, view, data)
{}

BulletController::~BulletController() {
	// TODO Auto-generated destructor stub
}

void BulletController::handleMoveInput(unsigned int width, unsigned int height) {
	if (moveDir_ != none && moveDir_ != x ) {
		if (model_->getOrientation() == models::up) {
			model_->moveUp();
		}
		else {
			model_->moveDown();
		}
	}
}

} /* namespace controllers */
