/*
 * HUDFactory.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef HUDFACTORY_H_
#define HUDFACTORY_H_

#include "AbstractFactory.h"
#include "../observers/views/HUDView.h"
#include "../observers/controllers/HUDController.h"
#include "../models/HUD.h"

namespace factories {

class HUDFactory : public AbstractFactory {
public:
	HUDFactory();
	virtual ~HUDFactory();

	//! Constructs a controllerPtr to a HUD.
	virtual controllerPtr getController(std::string, modelPtr, sf::RenderWindow&);

	virtual controllerPtr getController(std::string, sf::RenderWindow&) { return nullptr; }
	virtual controllerPtr getController(std::string, int, int, sf::RenderWindow&) { return nullptr; }
};

} /* namespace factories */

#endif /* HUDFACTORY_H_ */
