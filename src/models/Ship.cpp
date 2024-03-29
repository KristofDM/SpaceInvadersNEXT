/*
 * Ship.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: kristof
 */

#include "Ship.h"
#include "SpaceShip.h"

namespace models {

Ship::Ship(int lives, int fireRate, double speed, EOrientation orientation)
	: MovingObject(speed, orientation),
	  lives_(lives),
	  fireRate_(fireRate),
	  shootTimer_(),
	  invincibleTimer_(),
	  damage_(100),
	  shooting_(false),
	  fatalCollision_(false)
{}

int Ship::getLives() {
	return lives_;
}

void Ship::setLives(int lives) {
	lives_ = lives;
}

int Ship::getFireRate() {
	return fireRate_;
}

void Ship::setFireRate(int fireRate) {
	fireRate_ = fireRate;
}

bool Ship::shoot() {
	if (shooting_) {
		// Model itself
		sf::Time t = shootTimer_.getElapsedTime();
		float t2= t.asSeconds();
		if (t2 > 60.0/fireRate_) {
			shootTimer_.restart();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Ship::collided(std::shared_ptr<Model> other) {
	if (!invincible_) {
		sf::Time t = invincibleTimer_.getElapsedTime();
		float t2 = t.asSeconds();
		if (t2 > 1) {
			lives_ -= other->getDamage();
			if (lives_ <= 0) {
				this->notify();
				return true;
			}
			invincibleTimer_.restart();
		}
		this->notify();
		return false;
	}
	else {
		return false;
	}
}

unsigned int Ship::getDamage() {
	return damage_;
}

void Ship::setFlags(bool invincible, bool shooting) {
	invincible_ = invincible;
	shooting_ = shooting;
}

bool Ship::getFatalCollision() const {
	return fatalCollision_;
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

} /* namespace models */
