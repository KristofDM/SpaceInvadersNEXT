/*
 * EnemyShip.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "EnemyShip.h"

namespace models {

EnemyShip::EnemyShip(factories::DataParser data, int moveAmount, int speed)
	: Ship(data.getLives(), data.getFireRate(), speed, down),
	  moveAmount_(moveAmount),
	  points_(data.getPoints()),
	  dirSwitch(true),
	  travelled_(0),
	  moveDown_(false)
{
}

EnemyShip::~EnemyShip() {
}

void EnemyShip::moveLeft() {
	if (moveDown_) {
		if (travelled_ < (0.25 * moveAmount_)) {
			this->moveDown();
			travelled_ += speed_;
		}
		else {
			moveDown_ = false;
			travelled_ = 0;
		}
	}
	else if (dirSwitch) {
		// True goes to left.
		if (travelled_ < moveAmount_) {
			sprite_.move(-speed_, 0);
			travelled_ += speed_;
		}
		else {
			// Reset amount travelled.
			dirSwitch = false;
			travelled_ = 0;
			moveDown_ = true;
		}
	}
	else {
		if (travelled_ < moveAmount_) {
			sprite_.move(speed_, 0);
			travelled_ += speed_;
		}
		else {
			// Reset amount travelled.
			dirSwitch = true;
			travelled_ = 0;
			moveDown_ = true;
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

bool EnemyShip::shoot() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0,499);
    int number = distribution(generator);

	if (shooting_ && number == 0) {
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

} /* namespace models */
