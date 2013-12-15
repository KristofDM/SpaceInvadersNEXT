/*
 * MainFactory.h
 *
 *  Created on: Dec 9, 2013
 *      Author: kristof
 */

#ifndef MAINFACTORY_H_
#define MAINFACTORY_H_

#include <memory>
#include <tuple>
#include <string>
#include "../models/Model.h"
#include "../observers/controllers/Controller.h"
#include "../observers/views/ModelView.h"


namespace factories {


typedef std::shared_ptr<models::Model> modelPtr;
typedef std::shared_ptr<views::ModelView> modelViewPtr;
typedef std::shared_ptr<controllers::Controller> controllerPtr;
typedef std::tuple<modelPtr, modelViewPtr, controllerPtr > mvcTriple;

class MainFactory {
public:
	virtual std::shared_ptr<mvcTriple> createSpaceShip(std::string, sf::RenderWindow&) = 0;
	virtual std::shared_ptr<mvcTriple> createEnemyShip(std::string, int, int, sf::RenderWindow&) = 0;
	virtual std::shared_ptr<mvcTriple> createShield(std::string, int, sf::RenderWindow&) = 0;
	virtual std::shared_ptr<mvcTriple> createBullet(std::string, std::shared_ptr<models::Model>, sf::RenderWindow&) = 0;
};

} /* namespace factories */

#endif /* MAINFACTORY_H_ */
