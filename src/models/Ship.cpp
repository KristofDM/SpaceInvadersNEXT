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
	  clock_()
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
//	factories::DataParser data("Data/NormalTurret.xml");
//	std::shared_ptr<models::Model> newBullet = std::make_shared<Bullet>(this);
//	newBullet->setUp(data);

//	// View -- We don't want to pollute the view with the window. What we'll do is construct an abstract factory that takes care of the building of the bullets.
//	// The abstract factory holds a pointer to the window in question.
	//vFac.create("xml file", newBullet);
//	std::shared_ptr<views::ModelView> newBulletView = std::make_shared<views::BulletView>(newBullet, data, )
//
//	// Controller
//	std::shared_ptr<controllers::BulletController> newBulletController = cFac.create("Data/NormalTurret.xml", newBullet, newBulletView);

//	bullets.push_back(newBullet);

	sf::Time t = clock_.getElapsedTime();
	float t2= t.asSeconds();
	if (t2 > 60.0/fireRate_) {
		clock_.restart();
		return true;
	}
	else {
		return false;
	}

}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

} /* namespace models */
