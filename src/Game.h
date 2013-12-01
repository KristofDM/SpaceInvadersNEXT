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
#include "observers/controllers/ShipController.h"
#include "models/Model.h"
#include "models/SpaceShip.h"
#include "models/EnemyShip.h"
#include "factories/DataParser.h"
#include "observers/views/SpaceShipView.h"

typedef std::vector<std::shared_ptr<models::Model> > modelsVec;
typedef std::vector<std::shared_ptr<views::ModelView> > viewsVec;
typedef std::vector<std::shared_ptr<controllers::ShipController> > shipControllerVec;
typedef std::vector<std::shared_ptr<controllers::Controller> > controllersVec;

typedef std::list<std::tuple<std::shared_ptr<models::Model>, std::shared_ptr<views::ModelView>, std::shared_ptr<controllers::ShipController> > > shipTriplets;
typedef std::list<std::tuple<std::shared_ptr<models::Model>, std::shared_ptr<views::ModelView>, std::shared_ptr<controllers::ShipController> > > dumbTriplets;

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

	modelsVec models_;

	viewsVec views_;

	shipControllerVec shipControllers_;

	controllersVec staticControllers_;

	shipTriplets ships;

	dumbTriplets other;

	void setupModels(factories::DataParser );
	void setupViews(factories::DataParser );
	void setupControllers(factories::DataParser );
};

} /* namespace game */

#endif /* GAME_H_ */
