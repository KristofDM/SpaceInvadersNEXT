/*
 * EnemyShip.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "EnemyShip.h"

namespace models {

double EnemyShip::amountTravelled_ = 0;
int EnemyShip::amount_ = 0;
int EnemyShip::movedTimes_ = 0;
double EnemyShip::movedDown_ = 0;

EnemyShip::EnemyShip(factories::DataParser data, int moveAmount)
	: Ship(data.getLives(), data.getFireRate(), data.getSpeed(), down),
	  moveAmount_(moveAmount),
	  points_(20)
{
	amount_++;
}

EnemyShip::~EnemyShip() {
	amount_--;
}

void EnemyShip::moveLeft() {
	if (movedTimes_ != 2) {
		if (amountTravelled_ <= moveAmount_ * amount_) {
			sprite_.move(-speed_, 0);
			amountTravelled_ += speed_;
			this->notify();
		}
		else {
			amountTravelled_ += speed_;
			this->moveRight();
			if (amountTravelled_ >= (2 * moveAmount_) * amount_) {
				amountTravelled_ = 0;
				movedTimes_++;
			}
		}
	}
	else {
		if (movedDown_ < 25 * amount_) {
			this->moveDown();
			movedDown_ += speed_;
		}
		else {
			movedDown_ = 0;
			movedTimes_ = 1;
		}
	}
}

int EnemyShip::getPoints() {
	return points_;
}

bool EnemyShip::collided(std::shared_ptr<Model> other) {
	// Need to check whether or not fatalCollision_ is needs to be turned on.
	std::shared_ptr<Shield> test;
	test = std::dynamic_pointer_cast<Shield>(other);
	std::shared_ptr<SpaceShip> test2;
	test2 = std::dynamic_pointer_cast<SpaceShip>(other);
	if (test != nullptr || test2 != nullptr) {
		// Set fatalCollision_ to true.
		fatalCollision_ = true;
	}

	if (!invincible_) {
		sf::Time t = invincibleTimer_.getElapsedTime();
		float t2 = t.asSeconds();
		if (t2 > 1) {
			lives_ -= other->getDamage();
			if (lives_ <= 0) {
				return true;
			}
			invincibleTimer_.restart();
		}
		return false;
	}
	else {
		return false;
	}
}


//bool EnemyShip::shoot() {
//	// Model itself
//	sf::Time t = clock_.getElapsedTime();
//	float t2= t.asSeconds();
//	if (t2 > 60.0/fireRate_) {
//		clock_.restart();
//		return true;
//	}
//	else {
//		return false;
//	}
//}


} /* namespace models */
