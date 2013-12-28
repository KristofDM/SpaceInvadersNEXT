/*
 * ShieldFactory.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef SHIELDFACTORY_H_
#define SHIELDFACTORY_H_

#include "GameParser.h"
#include "AbstractFactory.h"
#include "../observers/views/SpaceShipView.h"
#include "../observers/controllers/StaticController.h"
#include "../models/Shield.h"

namespace factories {

class ShieldFactory : public AbstractFactory {
public:
	ShieldFactory();
	virtual ~ShieldFactory();

	//! Constructs a controllerPtr to a Shield.
	virtual controllerPtr getController(std::string, sf::RenderWindow&);
	virtual controllerPtr getController(std::string, modelPtr, sf::RenderWindow&) { return nullptr; };
	virtual controllerPtr getController(std::string, int, int, sf::RenderWindow&) { return nullptr; }
private:
	int counter_;
};

} /* namespace factories */

#endif /* SHIELDFACTORY_H_ */
