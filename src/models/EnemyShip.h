/*
 * EnemyShip.h
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#ifndef ENEMYSHIP_H_
#define ENEMYSHIP_H_

#include "Ship.h"

namespace models {

class EnemyShip : public Ship {
public:
	EnemyShip(factories::DataParser);
	virtual ~EnemyShip();

	virtual void moveLeft();

private:
	static double amountTravelled_;

};

} /* namespace models */

#endif /* ENEMYSHIP_H_ */
