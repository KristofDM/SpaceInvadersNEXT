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

#include "factories/AbstractFactory.h"
#include "factories/SpaceShipFactory.h"
#include "factories/HUDFactory.h"
#include "factories/ShieldFactory.h"
#include "factories/EnemyShipFactory.h"


typedef std::shared_ptr<controllers::Controller> controllerPtr;

namespace game {

class Game {
public:
	//! Constructor. Constructs its data members with init values.
	Game(unsigned int, unsigned int, sf::RenderWindow&);

	virtual ~Game();

	//! Perform one game cycle.
	void cycle();

	void render();

	//! Set up the game.
	void setUp();

	//! Lets it caller know whether or not the game has ended.
	//! @return True if the game has ended, false if not.
	bool endGame();

	//! Advance to next level.
	void nextLevel();

	Game& operator=(const Game rhs);

	std::vector<controllerPtr> getEntities();

private:
	//! Field width. (== window_ width)
	unsigned int width_;

	//! Field height. (== window_ height)
	unsigned int height_;

	sf::RenderWindow& window_;

	//! True if the game is over.
	bool gameOver_;

	//! Tells us how much faster the aliens need to go in the next level.
	double levelMultiplier_;

	int level_;

	//! The controller to the spaceShip the player has control over.
	std::shared_ptr<controllers::SpaceShipController> spaceShipController_;

	//! A vector of all controllers in the game. (Excluding GameController)
	std::vector<controllerPtr> entityControllers_;

	//! A matrix containing pointers to the EnemyShips.
	std::vector<std::vector<std::shared_ptr<controllers::EnemyShipController> > > enemies_;

	//! The controller that takes care of the HUD.
	std::shared_ptr<controllers::HUDController> HUD_;

    void setupControllers(factories::GameParser);

	void determineShooters();

	void setupEnemies(factories::GameParser);

	bool checkForNextLevel();
};

} /* namespace game */

#endif /* GAME_H_ */
