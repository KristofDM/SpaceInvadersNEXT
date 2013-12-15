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

		factories::DataParser data;
		data.parseObject("Data/regularAmmo.xml");

		float x = model_->getPosition().x + (model_->getBounds().width/2);
		sf::Vector2f pos(x, model_->getPosition().y);
		modelPtr newBullet = std::make_shared<models::Bullet>(model_, pos, model_->getOrientation());
		newBullet->setUp(data);

		modelViewPtr newBulletView = std::make_shared<views::BulletView>(newBullet, data, view_->getWindow());

		controllerPtr newBulletController = std::make_shared<controllers::BulletController>(newBullet, newBulletView, data);

		std::shared_ptr<mvcTriple> bullet = std::make_shared<mvcTriple>(newBullet, newBulletView, newBulletController);

//		std::shared_ptr<factories::MainFactory> factory = std::make_shared<factories::Factory>();
//		std::shared_ptr<mvcTriple> bullet = factory->createBullet("Data/regularAmmo.xml", model_, view_->getWindow());
		mvcTriples.push_back(bullet);
	}
}

} /* namespace controllers */
