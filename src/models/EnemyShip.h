/*
 * EnemyShip.h
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#ifndef ENEMYSHIP_H_
#define ENEMYSHIP_H_

#include "Ship.h"
#include "SpaceShip.h"

namespace models {

class EnemyShip : public Ship {
public:
	EnemyShip(factories::DataParser, int);
	virtual ~EnemyShip();

	virtual void moveLeft();
//	virtual bool checkCollision(std::shared_ptr<Model> other) const;
	virtual bool collided(std::shared_ptr<Model> other);
	int getPoints();

private:

	static double amountTravelled_;
	static int amount_;
	static int movedTimes_;
	static double movedDown_;
	int moveAmount_;
	int points_;


};

} /* namespace models */

#endif /* ENEMYSHIP_H_ */
