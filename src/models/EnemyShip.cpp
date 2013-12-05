/*
 * EnemyShip.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#include "EnemyShip.h"

namespace models {

double EnemyShip::amountTravelled_ = 0;

EnemyShip::EnemyShip(factories::DataParser data)
	: Ship(data.getLives(), data.getFireRate(), data.getSpeed(), down)
{}

EnemyShip::~EnemyShip() {
	// TODO Auto-generated destructor stub
}

void EnemyShip::moveLeft() {
	if (amountTravelled_ < 150) {
		sprite_.move(-speed_, 0);
		amountTravelled_ += speed_;
		this->notify();
	}
	else {
		amountTravelled_ += speed_;
		this->moveRight();
		if (amountTravelled_ == 300) {
			amountTravelled_ = 0;
		}
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
