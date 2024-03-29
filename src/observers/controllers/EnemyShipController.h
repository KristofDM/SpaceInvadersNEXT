/*
 * EnemyShipController.h
 *
 *  Created on: Dec 1, 2013
 *      Author: kristof
 */

#ifndef ENEMYSHIPCONTROLLER_H_
#define ENEMYSHIPCONTROLLER_H_

#include "ShipController.h"

namespace controllers {

class EnemyShipController : public ShipController {
public:
	EnemyShipController(modelPtr model, modelViewPtr view, factories::DataParser);

	virtual ~EnemyShipController();

	virtual void handleMoveInput(unsigned int, unsigned int);

	virtual void handleShooting(std::vector<std::shared_ptr<mvcTriple> >&);

};

} /* namespace controllers */

#endif /* ENEMYSHIPCONTROLLER_H_ */
