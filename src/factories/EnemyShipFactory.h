/*
 * EnemyShipFactory.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef ENEMYSHIPFACTORY_H_
#define ENEMYSHIPFACTORY_H_

#include "AbstractFactory.h"
#include "../observers/views/SpaceShipView.h"
#include "../observers/controllers/EnemyShipController.h"
#include "../models/EnemyShip.h"

// amount, space, file, order, moveAmount, speed
typedef std::tuple<int, int, std::string, std::string, int, double> infoTuple;

namespace factories {

class EnemyShipFactory : public AbstractFactory {
public:
	EnemyShipFactory();
	virtual ~EnemyShipFactory();
	virtual controllerPtr getEntity(std::string, sf::RenderWindow&) { return nullptr	; }
	virtual controllerPtr getEntity(std::string, modelPtr, sf::RenderWindow&) { return nullptr; };

	//! Constructs a controllerPtr to an EnemyShip.
	virtual controllerPtr getEntity(std::string, int, int, sf::RenderWindow&);
private:
	int counter_;
};

} /* namespace factories */

#endif /* ENEMYSHIPFACTORY_H_ */
