/*
 * EnemyShipFactory.cpp
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#include "EnemyShipFactory.h"

namespace factories {

EnemyShipFactory::EnemyShipFactory()
	: counter_(0)
{
	// TODO Auto-generated constructor stub

}

EnemyShipFactory::~EnemyShipFactory() {
	// TODO Auto-generated destructor stub
}

controllerPtr EnemyShipFactory::getController(std::string file, int row, int space, sf::RenderWindow& window) {
	GameParser game;
	game.parseGame(file);

	infoTuple info = game.getEnemyInfo().at(row); // They all contain the same data.

	DataParser data;
	data.parseObject(std::get<2>(info));

	modelPtr ship = std::make_shared<models::EnemyShip>(data, std::get<4>(info), std::get<5>(info));
	ship->setUp(data, space);

	modelViewPtr view = std::make_shared<views::SpaceShipView>(ship, data, window);
	controllerPtr controller (new controllers::EnemyShipController(ship, view, data));

	return controller;
}

} /* namespace factories */
