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
#include "observers/controllers/HUDController.h"
#include "models/Model.h"
#include "models/SpaceShip.h"
#include "models/EnemyShip.h"
#include "models/Ship.h"
#include "models/Shield.h"
#include "models/HUD.h"
#include "factories/DataParser.h"
#include "factories/GameParser.h"
#include "observers/views/SpaceShipView.h"
#include "observers/views/HUDView.h"
#include "factories/MainFactory.h"
#include "factories/Factory.h"


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

	bool endGame();

private:
	unsigned int width_;
	unsigned int height_;
	sf::RenderWindow& window_;
	bool gameOver_;


	std::shared_ptr<controllers::ShipController> spaceShipController_;

	std::vector<std::shared_ptr<mvcTriple> > mvcTriples_;

	std::vector<std::vector<std::shared_ptr<mvcTriple> > > enemies_;

	std::shared_ptr<mvcTriple> HUD_;

	void setupTriples(factories::GameParser);

	void determineShooters();
};

} /* namespace game */

#endif /* GAME_H_ */
