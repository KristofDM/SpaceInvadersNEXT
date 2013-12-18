/*
 * ShieldFactory.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef SHIELDFACTORY_H_
#define SHIELDFACTORY_H_

#include "AbstractFactory.h"
#include "../observers/views/SpaceShipView.h"
#include "../observers/controllers/StaticController.h"
#include "../models/Shield.h"

namespace factories {

class ShieldFactory : public AbstractFactory {
public:
	ShieldFactory();
	virtual ~ShieldFactory();
	virtual controllerPtr getEntity(std::string, sf::RenderWindow&);
	virtual controllerPtr getEntity(std::string, modelPtr, sf::RenderWindow&) { /* nothing. */ };
};

} /* namespace factories */

#endif /* SHIELDFACTORY_H_ */
