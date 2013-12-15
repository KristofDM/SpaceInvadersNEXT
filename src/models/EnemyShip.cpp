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

//bool EnemyShip::checkCollision(std::shared_ptr<Model> other) const{
//	sf::Vector2f otherPos = other->getSprite().getPosition();
//	sf::Vector2f thisPos = sprite_.getPosition();
//
//	double thisHeight = sprite_.getGlobalBounds().height;
//	double thisWidth = sprite_.getGlobalBounds().width;
//
//	if ((thisPos.y + thisHeight) > otherPos.y && (thisPos.y + thisHeight) < (otherPos.y + other->getSprite().getGlobalBounds().height)) {
//		if (this != other->getOwner().get()) {
//			// Colliding with its owner, nothing happens.
//			std::cout << "allejoppa" << std::endl;
//		}
//	}
//
////	if ((thisPos.y + sprite_.getGlobalBounds().height < otherPos.y + other->getSprite().getGlobalBounds().height && thisPos.y + sprite_.getGlobalBounds().height > otherPos.y &&
////			   (thisPos.x + (sprite_.getGlobalBounds().width/2) >= otherPos.x && thisPos.x + (sprite_.getGlobalBounds().width/2) <= (otherPos.x + other->getSprite().getGlobalBounds().width)))) {
////		if (this != other->getOwner().get()) {
////			// Colliding with its owner, nothing happens.
////			std::cout << "allejoppa" << std::endl;
////		}
////	}
//
//	if ((thisPos.y + sprite_.getGlobalBounds().height < otherPos.y + other->getSprite().getGlobalBounds().height && thisPos.y + sprite_.getGlobalBounds().height > otherPos.y &&
//			   (thisPos.x + (sprite_.getGlobalBounds().width/2) >= otherPos.x && thisPos.x + (sprite_.getGlobalBounds().width/2) <= (otherPos.x + other->getSprite().getGlobalBounds().width))) || (otherPos.x >= thisPos.x && otherPos.x <= (thisPos.x + sprite_.getGlobalBounds().width) && otherPos.y >= thisPos.y && (otherPos.y <= (thisPos.y + sprite_.getGlobalBounds().height))))
//	{
//		if (this == other->getOwner().get()) {
//			// Colliding with its owner, nothing happens.
//			return false;
//		}
//		return true;
//	}
//	return false;
//}


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
