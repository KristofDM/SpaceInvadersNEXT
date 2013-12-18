/*
 * SpaceShipController.h
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#ifndef SPACESHIPCONTROLLER_H_
#define SPACESHIPCONTROLLER_H_

#include "ShipController.h"
#include "../../models/SpaceShip.h"
typedef std::shared_ptr<models::Model> modelPtr;

namespace controllers {

class SpaceShipController : public ShipController{
public:
	SpaceShipController(modelPtr model, modelViewPtr view, factories::DataParser data);

	virtual ~SpaceShipController();

	virtual void handleMoveInput(unsigned int, unsigned int);

	virtual void handleShooting(std::vector<std::shared_ptr<mvcTriple> >&);

	modelPtr getSpaceShip();

	bool checkDead();
};

} /* namespace controllers */

#endif /* SPACESHIPCONTROLLER_H_ */
