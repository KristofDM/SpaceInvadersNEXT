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
	virtual controllerPtr getEntity(std::string, modelPtr, sf::RenderWindow&);
	virtual controllerPtr getEntity(std::string, sf::RenderWindow&) { return nullptr; }
};

} /* namespace factories */

#endif /* HUDFACTORY_H_ */
