/*
 * Factory.cpp
 *
 *  Created on: Dec 9, 2013
 *      Author: kristof
 */

#include "Factory.h"
#include "../models/SpaceShip.h"
#include "../observers/views/SpaceShipView.h"
#include "../observers/controllers/SpaceShipController.h"
#include "../observers/controllers/EnemyShipController.h"
#include "../observers/controllers/StaticController.h"
#include "../models/Shield.h"
#include "../models/Bullet.h"
#include "../observers/views/BulletView.h"
#include "../models/EnemyShip.h"

namespace factories {

Factory::Factory()
{
}

Factory::~Factory() {
	// TODO Auto-generated destructor stub
}

std::shared_ptr<mvcTriple> Factory::createSpaceShip(std::string file, sf::RenderWindow& window) {
	DataParser data;
	data.parseObject(file);

	modelPtr model = std::make_shared<models::SpaceShip>(data);
	model->setUp(data);
	// View
	// temp window here
	modelViewPtr view = std::make_shared<views::SpaceShipView>(model, data, window);
	// Controller
	controllerPtr controller = std::make_shared<controllers::SpaceShipController>(model, view, data);
	controller->setFlags(true, true);
	std::shared_ptr<mvcTriple> triple (new mvcTriple(model, view, controller));

	return triple;
}

std::shared_ptr<mvcTriple> Factory::createEnemyShip(std::string file, int space, int moveAmount, sf::RenderWindow& window) {
	DataParser data;
	data.parseObject(file);

	modelPtr ship = std::make_shared<models::EnemyShip>(data, moveAmount);
	ship->setUp(data, space);

	modelViewPtr view = std::make_shared<views::SpaceShipView>(ship, data, window);
	controllerPtr controller (new controllers::EnemyShipController(ship, view, data));
	std::shared_ptr<mvcTriple> triple (new mvcTriple(ship, view, controller));

	return triple;
}

std::shared_ptr<mvcTriple> Factory::createShield(std::string file, int space, sf::RenderWindow& window) {
	DataParser data;
	data.parseObject(file);

	modelPtr shield = std::make_shared<models::Shield>(models::none, data.getLives(), 100);
	shield->setUp(data, space);

	// need to adjust shield places.
	modelViewPtr view = std::make_shared<views::SpaceShipView>(shield, data, window);

	controllerPtr controller (new controllers::StaticController(shield, view, data));

	std::shared_ptr<mvcTriple> triple (new mvcTriple(shield, view, controller));

	return triple;
}

std::shared_ptr<mvcTriple> Factory::createBullet(std::string file, std::shared_ptr<models::Model> owner, sf::RenderWindow& window) {
	factories::DataParser data;
	data.parseObject(file);

	float x = owner->getPosition().x + (owner->getBounds().width/2);
	sf::Vector2f pos(x, owner->getPosition().y);
	modelPtr newBullet = std::make_shared<models::Bullet>(owner, pos, owner->getOrientation());
	newBullet->setUp(data);

	modelViewPtr newBulletView = std::make_shared<views::BulletView>(newBullet, data, window);

	controllerPtr newBulletController = std::make_shared<controllers::BulletController>(newBullet, newBulletView, data);
	std::shared_ptr<mvcTriple> triple = std::make_shared<mvcTriple>(newBullet, newBulletView, newBulletController);

	return triple;
}

} /* namespace factories */
