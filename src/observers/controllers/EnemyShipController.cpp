/*
 * EnemyShipController.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "EnemyShipController.h"

namespace controllers {

EnemyShipController::	EnemyShipController(modelPtr model, modelViewPtr view, factories::DataParser data)
	: ShipController(model, view, data)
{
}

EnemyShipController::~EnemyShipController() {
	// TODO Auto-generated destructor stub
}

void EnemyShipController::handleMoveInput(unsigned int width, unsigned int height) {
	// AI CONTROLLED
	model_->moveLeft();

}

void EnemyShipController::handleShooting(std::vector<std::shared_ptr<mvcTriple> >& mvcTriples) {

	// AI CONTROLLED
	if (model_->shoot()) {
		// Shoot!
		std::shared_ptr<factories::MainFactory> factory = std::make_shared<factories::Factory>();
		std::shared_ptr<mvcTriple> bullet = factory->createBullet("Data/regularAmmo.xml", model_, view_->getWindow());
		mvcTriples.push_back(bullet);
	}
}

} /* namespace controllers */
