/*
 * SpaceShipController.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "SpaceShipController.h"

namespace controllers {

SpaceShipController::SpaceShipController(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser data)
	: ShipController(model, view, data)
{
}

SpaceShipController::~SpaceShipController() {
	// TODO Auto-generated destructor stub
}

void SpaceShipController::handleShooting(std::vector<mvcTriple>& mvcTriples) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && model_->shoot()) {
		// Shoot!
		std::cout << "YOU ARE SHOOTING!" << std::endl;

		factories::DataParser data;
		data.parse("Data/regularAmmo.xml");

		float x = model_->getPosition().x + (model_->getBounds().width/2);
		sf::Vector2f pos(x, model_->getPosition().y);
		std::shared_ptr<models::Model> newBullet = std::make_shared<models::Bullet>(model_, pos, model_->getOrientation());
		newBullet->setUp(data);

		std::shared_ptr<views::ModelView> newBulletView = std::make_shared<views::BulletView>(newBullet, data, view_->getWindow());

		std::shared_ptr<controllers::Controller> newBulletController = std::make_shared<controllers::BulletController>(newBullet, newBulletView, data);

		mvcTriple bullet(newBullet, newBulletView, newBulletController);
		mvcTriples.push_back(bullet);

		std::cout << "you have shot" << std::endl;
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
