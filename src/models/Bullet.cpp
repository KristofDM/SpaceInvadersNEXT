/*
 * Bullet.cpp
 *
 *  Created on: Nov 28, 2013
 *      Author: kristof
 */

#include "Bullet.h"

namespace models {

Bullet::Bullet(std::shared_ptr<Model> owner, sf::Vector2f pos, EOrientation orientation)
	: FlyingObject(3, orientation),
	  damage_(1),
	  owner_(owner),
	  initPosition_(pos)
{
}

Bullet::~Bullet() {
}

void Bullet::setUp(factories::DataParser data) {
	try{
		// Load texture/sprite
		if(!texture_.loadFromFile(data.getSpritePath())) {
			throw Exception("Could not load sprite on location " + data.getSpritePath());
		}
		sprite_.setTexture(texture_);
		sprite_.setPosition(initPosition_);
	}
	catch (Exception& e) {
		std::cout << e.what() << std::endl;
	}
}



} /* namespace game */
