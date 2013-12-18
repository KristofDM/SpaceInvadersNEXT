/*
 * SpaceShipFactory.cpp
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#include "SpaceShipFactory.h"

namespace factories {

SpaceShipFactory::SpaceShipFactory() {
	// TODO Auto-generated constructor stub

}

SpaceShipFactory::~SpaceShipFactory() {
	// TODO Auto-generated destructor stub
}

controllerPtr getEntity(std::string file, sf::RenderWindow& window) {
	DataParser data;
	data.parseObject(file);

	modelPtr model = std::make_shared<models::SpaceShip>(data);
	model->setUp(data);

	// View
	modelViewPtr view = std::make_shared<views::SpaceShipView>(model, data, window);
	// Controller
	controllerPtr controller = std::make_shared<controllers::SpaceShipController>(model, view, data);
	controller->setFlags(false, true);

	return controller;
}


} /* namespace factories */
