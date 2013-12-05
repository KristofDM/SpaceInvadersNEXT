/*
 * Shield.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#include "Shield.h"

namespace models {

Shield::Shield(EOrientation orientation, int lives, unsigned int damage)
	: StaticObject(orientation),
	  lives_(lives),
	  damage_(damage)
{}

Shield::~Shield() {
	// TODO Auto-generated destructor stub
}

unsigned int Shield::getDamage() {
	return damage_;
}

bool Shield::collided(std::shared_ptr<Model> other) {
	lives_ -= other->getDamage();
	if (lives_ <= 0) {
		return true;
	}
	else {
		return false;
	}
}


} /* namespace models */
