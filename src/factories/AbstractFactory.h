/*
 * AbstractFactory.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include "../observers/controllers/Controller.h"

typedef std::shared_ptr<controllers::Controller> controllerPtr;

namespace factories {

class AbstractFactory {
public:
	virtual controllerPtr getEntity(std::string, sf::RenderWindow&) = 0;
	virtual controllerPtr getEntity(std::string, modelPtr, sf::RenderWindow&) = 0;
};

} /* namespace factories */

#endif /* ABSTRACTFACTORY_H_ */
