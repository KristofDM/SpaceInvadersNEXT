/*
 * SpaceShip.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: kristof
 */

#include "SpaceShip.h"

namespace models {

SpaceShip::SpaceShip(factories::DataParser data)
	: Ship(data.getLives(), data.getFireRate(), data.getSpeed(), up)
{}

SpaceShip::~SpaceShip() {
}

} /* namespace models */
