/*
 * ShieldFactory.cpp
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#include "ShieldFactory.h"

namespace factories {

ShieldFactory::ShieldFactory() {
	// TODO Auto-generated constructor stub

}

ShieldFactory::~ShieldFactory() {
	// TODO Auto-generated destructor stub
}

controllerPtr ShieldFactory::getEntity(std::string file, sf::RenderWindow& window) {
	GameParser game;
	game.parseGame(file);

	infoTuple info = game.getShieldInfo();

	DataParser data;
	data.parseObject(std::get<2>(info));

	modelPtr shield = std::make_shared<models::Shield>(models::none, data.getLives(), 100);
	shield->setUp(data, std::get<1>(info));

	// need to adjust shield places.
	modelViewPtr view = std::make_shared<views::SpaceShipView>(shield, data, window);
	controllerPtr controller (new controllers::StaticController(shield, view, data));

	return controller;
}


} /* namespace factories */