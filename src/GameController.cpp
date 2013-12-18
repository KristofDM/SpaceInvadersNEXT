/*
 * GameController.cpp
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#include "GameController.h"

namespace controllers {

GameController::GameController(int width, int height, sf::RenderWindow& window)
	: game_(width, height, window)
{}

GameController::~GameController() {
	// TODO Auto-generated destructor stub
}

void GameController::cycle() {
	game_.cycle();
}

void GameController::render() {
	game_.render();
}

void GameController::setUp() {
	game_.setUp();
}

bool GameController::endGame() {
	game_.endGame();
}



} /* namespace controllers */
