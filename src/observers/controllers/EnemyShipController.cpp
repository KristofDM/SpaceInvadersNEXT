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

void EnemyShipController::handleShooting(std::vector<controllerPtr>& entities) {
	// AI CONTROLLED
	if (model_->shoot()) {
		// Shoot!
		std::shared_ptr<factories::AbstractFactory> factory = std::make_shared<factories::BulletFactory>();
		entities.push_back(factory->getController("../Data/regularAmmo.xml", model_, view_->getWindow()));
	}
}

int EnemyShipController::getPoints() {
	std::shared_ptr<models::EnemyShip> enemy = std::dynamic_pointer_cast<models::EnemyShip>(model_);
	return enemy->getPoints();
}

} /* namespace controllers */
