/*
 * Controller.h
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <tuple>
#include <iostream>
#include <memory>
#include "../../models/Model.h"
#include "../views/ModelView.h"

namespace controllers {

enum EMoveDirection {x, y, xy, none};

class Controller : public observers::Observer{
public:
	Controller(std::shared_ptr<models::Model>, std::shared_ptr<views::ModelView>, factories::DataParser);

	virtual ~Controller();

	virtual void update() { }; // Not needed yet. (Change controller because of view)

	virtual void handleMoveInput(unsigned int, unsigned int) = 0;

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
