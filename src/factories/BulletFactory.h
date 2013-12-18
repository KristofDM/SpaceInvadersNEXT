/*
 * BulletFactory.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef BULLETFACTORY_H_
#define BULLETFACTORY_H_

#include "AbstractFactory.h"
#include "../observers/views/BulletView.h"
#include "../observers/controllers/BulletController.h"
#include "../models/Bullet.h"

namespace factories {

class BulletFactory : public AbstractFactory {
public:
	BulletFactory();
	virtual ~BulletFactory();
	virtual controllerPtr getEntity(std::string, modelPtr, sf::RenderWindow&);
	virtual controllerPtr getEntity(std::string, sf::RenderWindow&) { return nullptr; }
	virtual controllerPtr getEntity(std::string, int, int, sf::RenderWindow&) { return nullptr; }
};

} /* namespace factories */

#endif /* BULLETFACTORY_H_ */
