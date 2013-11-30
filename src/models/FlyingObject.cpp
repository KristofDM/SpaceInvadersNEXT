/*
 * FlyingObject.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: kristof
 */

#include "FlyingObject.h"

namespace models {

FlyingObject::FlyingObject(double speed, EOrientation orientation)
	: Model(orientation),
	  speed_(speed)
{}

FlyingObject::~FlyingObject() {
	// TODO Auto-generated destructor stub
}

void FlyingObject::moveLeft() {
	sprite_.move(-speed_, 0);
	this->notify();
}

void FlyingObject::moveRight() {
	sprite_.move(speed_, 0);
	this->notify();
}

void FlyingObject::moveUp() {
	sprite_.move(0, -speed_);
	this->notify();
}

void FlyingObject::moveDown() {
	sprite_.move(0, speed_);
	this->notify();
}

} /* namespace models */
