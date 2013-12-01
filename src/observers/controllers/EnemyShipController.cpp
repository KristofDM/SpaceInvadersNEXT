/*
 * EnemyShipController.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "EnemyShipController.h"

namespace controllers {

EnemyShipController::	EnemyShipController(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser data)
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

void EnemyShipController::handleShooting(modelsVec& m, viewsVec& v, controllersVec& c) {

	// AI CONTROLLED
	if (model_->shoot()) {
		// Shoot!

		factories::DataParser data;
		data.parse("Data/regularAmmo.xml");

		float x = model_->getPosition().x + (model_->getBounds().width/2);
		sf::Vector2f pos(x, model_->getPosition().y);
		std::shared_ptr<models::Model> newBullet = std::make_shared<models::Bullet>(model_, pos, model_->getOrientation());
		m.push_back(newBullet);
		newBullet->setUp(data);

		std::shared_ptr<views::ModelView> newBulletView = std::make_shared<views::BulletView>(newBullet, data, view_->getWindow());
		v.push_back(newBulletView);

		std::shared_ptr<controllers::Controller> newBulletController = std::make_shared<controllers::BulletController>(newBullet, newBulletView, data);
		c.push_back(newBulletController);
	}
}

} /* namespace controllers */
