/*
 * SpaceShipController.h
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#ifndef SPACESHIPCONTROLLER_H_
#define SPACESHIPCONTROLLER_H_

#include "ShipController.h"

namespace controllers {

class SpaceShipController : public ShipController{
public:
	SpaceShipController(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser data);

	virtual ~SpaceShipController();

	virtual void handleMoveInput(unsigned int, unsigned int);

	virtual void handleShooting(std::vector<mvcTriple>&);
};

} /* namespace controllers */

#endif /* SPACESHIPCONTROLLER_H_ */
