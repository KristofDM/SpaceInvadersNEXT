/*
 * GameView.h
 *
 *  Created on: Dec 19, 2013
 *      Author: kristof
 */

#ifndef GAMEVIEW_H_
#define GAMEVIEW_H_

#include <memory>
#include "Game.h"

namespace game {

class GameView {
public:
	GameView(std::shared_ptr<Game>);
	virtual ~GameView();

	void render();

private:
	std::shared_ptr<std::vector<controllerPtr> > entities_;
	std::shared_ptr<Game> game_;
};

} /* namespace game */

#endif /* GAMEVIEW_H_ */
