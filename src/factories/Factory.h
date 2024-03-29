/*
 * Factory.h
 *
 *  Created on: Dec 9, 2013
 *      Author: kristof
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "MainFactory.cpp"
#include "DataParser.h"
#include <tuple>
#include "GameParser.h"

namespace factories {

typedef std::shared_ptr<models::Model> modelPtr;
typedef std::shared_ptr<views::ModelView> modelViewPtr;
typedef std::shared_ptr<controllers::Controller> controllerPtr;
typedef std::tuple<modelPtr, modelViewPtr, controllerPtr > mvcTriple;

class Factory : public MainFactory {
public:

	Factory();
	virtual ~Factory();
	virtual std::shared_ptr<mvcTriple> createSpaceShip(std::string, sf::RenderWindow&);
	virtual std::shared_ptr<mvcTriple> createEnemyShip(std::string, int, int, sf::RenderWindow&, double);
	virtual std::shared_ptr<mvcTriple> createShield(std::string, int, sf::RenderWindow&);
	virtual std::shared_ptr<mvcTriple> createBullet(std::string, std::shared_ptr<models::Model>, sf::RenderWindow&);
	virtual std::shared_ptr<mvcTriple> createHUD(std::string, sf::RenderWindow&, modelPtr);

private:
	GameParser gameData_;
};

} /* namespace factories */

#endif /* FACTORY_H_ */
