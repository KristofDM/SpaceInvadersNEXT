/*
 * GameController.h
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "Game.h"

namespace controllers {

class GameController {
public:
	GameController(int, int, sf::RenderWindow&);
	virtual ~GameController();
	void cycle();
	void render();
	void setUp();
	bool endGame();
private:
	models::Game game_;
};

} /* namespace controllers */

#endif /* GAMECONTROLLER_H_ */
