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

namespace controllers {

enum EMoveDirection {x, y, xy, none};

class Controller;
typedef std::tuple<std::shared_ptr<models::Model>, std::shared_ptr<views::ModelView>, std::shared_ptr<controllers::Controller> > mvcTriple;

class Controller : public observers::Observer{
public:
	Controller(std::shared_ptr<models::Model>, std::shared_ptr<views::ModelView>, factories::DataParser);

	virtual ~Controller();

	virtual void update() { }; // Not needed yet. (Change controller because of view)

	virtual void handleMoveInput(unsigned int, unsigned int) = 0;

	virtual void gameInput(std::vector<mvcTriple>&, unsigned int, unsigned int) = 0;

	virtual bool checkRelevant(unsigned int, unsigned int);

protected:
	std::shared_ptr<models::Model> model_;
	std::shared_ptr<views::ModelView> view_;
	EMoveDirection moveDir_;
};


//class AlienController : public Controller {
//public:
//	AlienController();
//	virtual ~AlienController();
//};

} /* namespace controllers */

#endif /* CONTROLLER_H_ */
