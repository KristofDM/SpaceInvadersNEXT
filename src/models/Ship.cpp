/*
 * Ship.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: kristof
 */

#include "Ship.h"

namespace models {

Ship::Ship(int lives, int fireRate, double speed, EOrientation orientation)
	: FlyingObject(speed, orientation),
	  lives_(lives),
	  fireRate_(fireRate),
	  shootTimer_(),
	  invincibleTimer_(),
	  damage_(20)
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

bool Ship::collided(std::shared_ptr<Model> other) {
	sf::Time t = invincibleTimer_.getElapsedTime();
	float t2 = t.asSeconds();
	if (t2 > 3) {
		lives_ -= other->getDamage();
		std::cout << "Ship got hit! rem lives_ = " << lives_ << std::endl;

		if (lives_ <= 0) {
			std::cout << "Ship should be removed." << std::endl;
		}
		invincibleTimer_.restart();
	}

	return false;
}

unsigned int Ship::getDamage() {
	return damage_;
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

} /* namespace models */
