/*
 * GameController.cpp
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#include "GameController.h"

namespace game {

GameController::GameController(int width, int height, sf::RenderWindow& window)
	: game_(width, height, window),
	  gameView_(std::make_shared<game::Game>(game_))
{
}

GameController::~GameController() {
	// TODO Auto-generated destructor stub
}

void GameController::cycle() {
	game_.cycle();
}

void GameController::render() {
	game_.render();
	// TODO: use GameView?
}

void GameController::setUp() {
	game_.setUp();
}

bool GameController::endGame() {
	return game_.endGame();
}



} /* namespace game */
