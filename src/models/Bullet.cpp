/*
 * Bullet.cpp
 *
 *  Created on: Nov 28, 2013
 *      Author: kristof
 */

#include "Bullet.h"
#include <iostream>

namespace models {

Bullet::Bullet(std::shared_ptr<Model> owner, sf::Vector2f pos, EOrientation orientation)
	: MovingObject(0, orientation),
	  damage_(1),
	  owner_(owner),
	  initPosition_(pos)
{
}

Bullet::~Bullet() {
}

void Bullet::setUp(factories::DataParser data, int space) {
	try{
		speed_ = data.getSpeed();

		// Load texture/sprite
		if(!texture_.loadFromFile(data.getSpritePath())) {
			throw Exception("Could not load sprite on location " + data.getSpritePath());
		}
		sprite_.setTexture(texture_);
		sprite_.setPosition(initPosition_);
		// We rotate it in our model because it is also relevant for logic purposes.
		switch(owner_->getOrientation()) {
		case down:
			sprite_.rotate(180);
			break;
		case up:
		default:
			break;
		}
	}
	catch (Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::shared_ptr<Model> Bullet::getOwner() {
	return owner_;
}

unsigned int Bullet::getDamage() {
	return damage_;
}

bool Bullet::collided(std::shared_ptr<Model>) {
	// remove bullet.
	return true;
}



} /* namespace game */
