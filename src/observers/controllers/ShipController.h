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


typedef std::tuple<std::shared_ptr<models::Model>, std::shared_ptr<views::ModelView>, std::shared_ptr<controllers::Controller> > triple;
typedef std::vector<std::shared_ptr<models::Model> > modelsVec;
typedef std::vector<std::shared_ptr<views::ModelView> > viewsVec;
typedef std::vector<std::shared_ptr<controllers::Controller> > controllersVec;

namespace controllers {

class ShipController : public Controller {
public:
	ShipController(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser);

	virtual void handleMoveInput(unsigned int, unsigned int);

	virtual void handleShooting(std::vector<std::shared_ptr<models::Model> >&, std::vector<std::shared_ptr<views::ModelView> >&, std::vector<std::shared_ptr<controllers::Controller> >&);

};
} /* namespace controllers */

#endif /* SHIPCONTROLLER_H_ */
