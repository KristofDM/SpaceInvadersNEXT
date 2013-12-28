/*
 * BulletFactory.cpp
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#include "BulletFactory.h"

namespace factories {

BulletFactory::BulletFactory() {
	// TODO Auto-generated constructor stub

}

BulletFactory::~BulletFactory() {
	// TODO Auto-generated destructor stub
}

controllerPtr BulletFactory::getController(std::string file, modelPtr owner, sf::RenderWindow& window) {
	factories::DataParser data;
	data.parseObject(file);

	float x = owner->getPosition().x + (owner->getBounds().width/2);
	sf::Vector2f pos;
	if (owner->getOrientation() == models::up) {
		pos = sf::Vector2f(x, owner->getPosition().y);
	}
	else {
		pos = sf::Vector2f(x, owner->getPosition().y + owner->getBounds().height);
	}
	modelPtr newBullet = std::make_shared<models::Bullet>(owner, pos, owner->getOrientation());
	newBullet->setUp(data);

	modelViewPtr newBulletView = std::make_shared<views::BulletView>(newBullet, data, window);

	controllerPtr newBulletController = std::make_shared<controllers::BulletController>(newBullet, newBulletView, data);

	return newBulletController;
}

} /* namespace factories */
