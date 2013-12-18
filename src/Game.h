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
#include "observers/controllers/MovingObjectController.h"
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

#include "factories/AbstractFactory.h"
#include "factories/SpaceShipFactory.h"
#include "factories/HUDFactory.h"
#include "factories/ShieldFactory.h"
#include "factories/EnemyShipFactory.h"


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

	void nextLevel();

	Game& operator=(const Game rhs);

private:
	unsigned int width_;
	unsigned int height_;
	sf::RenderWindow& window_;
	bool gameOver_;
	double levelMultiplier_;
	int level_;
	std::shared_ptr<controllers::SpaceShipController> spaceShipController_;

	// TODO: Get rid of mvcTriple and only use controllers: much cleaner and makes a lot more sense.

	std::vector<controllerPtr> entityControllers_;

	std::vector<std::vector<std::shared_ptr<controllers::EnemyShipController> > > enemies_;

	std::shared_ptr<controllers::HUDController> HUD_;

    void setupControllers(factories::GameParser);

	void determineShooters();

	void setupEnemies(factories::GameParser);

	bool checkForNextLevel();
};

} /* namespace game */

#endif /* GAME_H_ */
