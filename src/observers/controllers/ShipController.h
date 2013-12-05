/*
 * SpaceShipController.h
 *
 *  Created on: Nov 24, 2013
 *      Author: kristof
 */

#ifndef SHIPCONTROLLER_H_
#define SHIPCONTROLLER_H_

#include <memory>
#include "Controller.h"
#include "../../models/Ship.h"
#include "../../factories/DataParser.h"
#include "../../factories/ControllerFactory.h"
#include "../../factories/ViewFactory.h"
#include "../../models/Bullet.h"
#include "BulletController.h"
#include "../views/BulletView.h"


typedef std::shared_ptr<models::Model> modelPtr;

namespace controllers {

class ShipController : public Controller {
public:
	ShipController(modelPtr model, modelViewPtr view, factories::DataParser);

	virtual void handleMoveInput(unsigned int, unsigned int) = 0;

	virtual void handleShooting(std::vector<std::shared_ptr<mvcTriple> >&) = 0;

	virtual void gameInput(std::vector<std::shared_ptr<mvcTriple> >&, unsigned int, unsigned int);
};
} /* namespace controllers */

#endif /* SHIPCONTROLLER_H_ */
