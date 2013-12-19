/*
 * EnemyShip.h
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#ifndef ENEMYSHIP_H_
#define ENEMYSHIP_H_

#include <random>
#include <chrono>
#include "Ship.h"
#include "SpaceShip.h"

namespace models {

class EnemyShip : public Ship {
public:
	EnemyShip(factories::DataParser, int, double);
	virtual ~EnemyShip();

	//! Move the spaceship. This method takes care of every movement of the enemyships.
	virtual void moveLeft();

	//! Specifies what this object should do when it collided with another entity.
	virtual bool collided(std::shared_ptr<Model> other);

	//! Returns the amount of points destroying this ship awards the player.
	int getPoints();

	//! Returns whether or not it is ok to shoot.
	//! @return True if the ship is able to shoot. False if it is not.
	bool shoot();

private:
	int moveAmount_;
	int points_;
	bool dirSwitch;
	double travelled_;
	bool moveDown_;

};

} /* namespace models */

#endif /* ENEMYSHIP_H_ */
