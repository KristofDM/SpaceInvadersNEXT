/*
 * SpaceShip.h
 *
 *  Created on: Nov 23, 2013
 *      Author: kristof
 */

#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include "Ship.h"
#include "../factories/DataParser.h"

namespace models {

class SpaceShip : public Ship {
//! Concrete model class from model factory.
//! The spaceship the player has control over.
public:
	SpaceShip(factories::DataParser);
	virtual ~SpaceShip();
private:
};

} /* namespace models */

#endif /* SPACESHIP_H_ */
