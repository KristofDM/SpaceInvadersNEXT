/*
 * GameController.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "Game.h"
#include "GameView.h"

namespace game {

class GameController {
public:
	//! Standard constructor. Will construct the Game model.
	GameController(int, int, sf::RenderWindow&, std::string);
	virtual ~GameController();

	//! Command the Game model to perform one game cycle.
	void cycle();

	//! Command the Game model to render everything on the screen.
	void render();

	//! Command the Game model to set itself up.
	void setUp();

	//! Check if the Game has ended.
	bool endGame();
private:
	//! Game model. Contains all controllers etc.
	Game game_;

	//! Game view. Takes care of the rendering.
	GameView gameView_;
};

} /* namespace game */

#endif /* GAMECONTROLLER_H_ */
