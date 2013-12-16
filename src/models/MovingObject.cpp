/*
 * MovingObject.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: kristof
 */

#include "MovingObject.h"

namespace models {

MovingObject::MovingObject(double speed, EOrientation orientation)
	: Model(orientation),
	  speed_(speed)
{}

MovingObject::~MovingObject() {
	// TODO Auto-generated destructor stub
}

void MovingObject::moveLeft() {
	sprite_.move(-speed_, 0);
	this->notify();
}

void MovingObject::moveRight() {
	sprite_.move(speed_, 0);
	this->notify();
}

void MovingObject::moveUp() {
	sprite_.move(0, -speed_);
	this->notify();
}

void MovingObject::moveDown() {
	sprite_.move(0, speed_);
	this->notify();
}

void MovingObject::setFlags(bool invincible, bool shooting) {
	invincible_ = invincible;
}

void MovingObject::changeSpeed(double multiplier) {
	speed_ *= multiplier;
}

} /* namespace models */
