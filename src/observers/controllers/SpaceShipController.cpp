/*
 * SpaceShipController.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "SpaceShipController.h"

namespace controllers {

SpaceShipController::SpaceShipController(modelPtr model, modelViewPtr view, factories::DataParser data)
	: ShipController(model, view, data)
{
}

SpaceShipController::~SpaceShipController() {
	// TODO Auto-generated destructor stub
}

void SpaceShipController::handleShooting(std::vector<std::shared_ptr<mvcTriple> >& mvcTriples) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && model_->shoot()) {
		// Shoot!
		factories::DataParser data;
		data.parseObject("Data/regularAmmo.xml");

		float x = model_->getPosition().x + (model_->getBounds().width/2);
		sf::Vector2f pos(x, model_->getPosition().y);
		modelPtr newBullet = std::make_shared<models::Bullet>(model_, pos, model_->getOrientation());
		newBullet->setUp(data);

		modelViewPtr newBulletView = std::make_shared<views::BulletView>(newBullet, data, view_->getWindow());

		controllerPtr newBulletController = std::make_shared<controllers::BulletController>(newBullet, newBulletView, data);

		bullets_.push_back(newBulletController);

		std::shared_ptr<mvcTriple> bullet = std::make_shared<mvcTriple>(newBullet, newBulletView, newBulletController);
		mvcTriples.push_back(bullet);
	}
}

void SpaceShipController::handleMoveInput(unsigned int width, unsigned int height) {
// Possible support for diagonal movement needs to be implemented.
	if (moveDir_ == none) {
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (moveDir_ != none && moveDir_ != y) {
			// move left
			if (model_->getPosition().x > 0) {
				model_->moveLeft();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (moveDir_ != none && moveDir_ != y) {
			// move right
			if (model_->getPosition().x + model_->getBounds().width < width) {
				model_->moveRight();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (moveDir_ != none && moveDir_ != x ) {
			// move up
			if (model_->getPosition().y > 0) {
				model_->moveUp();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (moveDir_ != none && moveDir_ != x) {
			// move up
			if (model_->getPosition().y + model_->getBounds().height < height) {
				model_->moveDown();
			}
		}
	}
}

} /* namespace controllers */
