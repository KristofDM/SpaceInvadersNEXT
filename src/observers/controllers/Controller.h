/*
 * Controller.h
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <tuple>
#include <list>
#include <iostream>
#include <memory>
#include "../../models/Model.h"
#include "../views/ModelView.h"

typedef std::shared_ptr<models::Model> modelPtr;
typedef std::shared_ptr<views::ModelView> modelViewPtr;

namespace controllers {

enum EMoveDirection {x, y, xy, none};

class Controller;
typedef std::shared_ptr<controllers::Controller> controllerPtr;
typedef std::tuple<modelPtr, modelViewPtr, std::shared_ptr<Controller> > mvcTriple;

class Controller : public observers::Observer{
public:
	Controller(modelPtr, modelViewPtr, factories::DataParser);

	virtual ~Controller();

	virtual void update() { }; // Not needed yet. (Change controller because of view)

	virtual void handleMoveInput(unsigned int, unsigned int) = 0;

	virtual void gameInput(std::vector<std::shared_ptr<mvcTriple> >&, unsigned int, unsigned int) = 0;

	virtual void setFlags(bool, bool);

	virtual bool checkRelevant(unsigned int, unsigned int);

	virtual void markDeleted();

	virtual bool collided(modelPtr);

	virtual bool checkCollision(modelPtr);

protected:
	modelPtr model_;
	modelViewPtr view_;
	EMoveDirection moveDir_;
};

} /* namespace controllers */

#endif /* CONTROLLER_H_ */
