/*
 * GameView.cpp
 *
 *  Created on: Dec 19, 2013
 *      Author: kristof
 */

#include "GameView.h"

namespace game {

GameView::GameView(std::shared_ptr<Game> game)
	: game_(game),
	  entities_(std::make_shared<std::vector<controllerPtr> >(game->getEntities()))
{
}

GameView::~GameView() {
	// TODO Auto-generated destructor stub
}

void GameView::render() {
	for (auto controller : *entities_) {
		controller->draw();
	}
}

} /* namespace game */
