/*
 * SpaceShipFactory.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef SPACESHIPFACTORY_H_
#define SPACESHIPFACTORY_H_

#include "AbstractFactory.h"
#include "../observers/views/SpaceShipView.h"
#include "../models/SpaceShip.h"
#include "../observers/controllers/SpaceShipController.h"

namespace factories {

class SpaceShipFactory : public AbstractFactory {
public:
	SpaceShipFactory();
	virtual ~SpaceShipFactory();

	//! Constructs a controllerPtr to a SpaceShip.
	virtual controllerPtr getController(std::string, sf::RenderWindow&);

	virtual controllerPtr getController(std::string, modelPtr, sf::RenderWindow&) { return nullptr; };
	virtual controllerPtr getController(std::string, int, int, sf::RenderWindow&) { return nullptr; }
};

} /* namespace factories */

#endif /* SPACESHIPFACTORY_H_ */
