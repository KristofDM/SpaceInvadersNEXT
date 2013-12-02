/*
 * Game.h
 *
 *  Created on: Nov 25, 2013
 *      Author: kristof
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#include <memory>
#include "observers/controllers/EnemyShipController.h"
#include "observers/controllers/SpaceShipController.h"
#include "observers/controllers/StaticController.h"
#include "observers/controllers/ShipController.h"
#include "models/Model.h"
#include "models/SpaceShip.h"
#include "models/EnemyShip.h"
#include "models/Shield.h"
#include "factories/DataParser.h"
#include "factories/GameParser.h"
#include "observers/views/SpaceShipView.h"

typedef std::shared_ptr<controllers::Controller> controllerPtr;
typedef std::tuple<modelPtr, modelViewPtr, controllerPtr > mvcTriple;

namespace game {

class Game {
public:
	Game(unsigned int, unsigned int, sf::RenderWindow&);

	Game(std::string); // XML file describing game

	virtual ~Game();

	void handleMoveInput();

	void handleShooting();

	void cycle();

	void render();

	void setUp();

private:
	unsigned int width_;
	unsigned int height_;
	sf::RenderWindow& window_;

	std::shared_ptr<controllers::ShipController> spaceShipController_;

	std::vector<std::shared_ptr<mvcTriple> > mvcTriples_;

	std::vector<controllerPtr > test_;

	void setupTriples(factories::GameParser);
};

} /* namespace game */

#endif /* GAME_H_ */
