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

	virtual void moveLeft();
	virtual bool collided(std::shared_ptr<Model> other);
	int getPoints();
	bool shoot();

private:
	int moveAmount_;
	int points_;
	bool dirSwitch;
	int travelled_;
	bool moveDown_;

};

} /* namespace models */

#endif /* ENEMYSHIP_H_ */
