/*
 * SpaceShipController.h
 *
 *  Created on: Nov 24, 2013
 *      Author: kristof
 */

#ifndef SHIPCONTROLLER_H_
#define SHIPCONTROLLER_H_

#include <memory>
#include "MovingObjectController.h"
#include "../../models/Ship.h"

#include "../../factories/AbstractFactory.h"
#include "../../factories/BulletFactory.h"

typedef std::shared_ptr<models::Model> modelPtr;

namespace controllers {

class ShipController : public MovingObjectController {
public:
	ShipController(modelPtr model, modelViewPtr view, factories::DataParser);

	virtual void handleMoveInput(unsigned int, unsigned int) = 0;

	virtual void handleShooting(std::vector<controllerPtr>&) = 0;

	virtual void gameInput(std::vector<controllerPtr>&, unsigned int, unsigned int);

	virtual void setFlags(bool, bool);

	virtual bool getFatalCollision();

};
} /* namespace controllers */

#endif /* SHIPCONTROLLER_H_ */
