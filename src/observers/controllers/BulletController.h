/*
 * BulletController.h
 *
 *  Created on: Nov 29, 2013
 *      Author: kristof
 */

#ifndef BULLETCONTROLLER_H_
#define BULLETCONTROLLER_H_

#include "Controller.h"

namespace controllers {

class BulletController : public Controller{
public:
	BulletController(std::shared_ptr<models::Model> model, std::shared_ptr<views::ModelView> view, factories::DataParser data);

	virtual ~BulletController();

	virtual void handleMoveInput(unsigned int, unsigned int);

};

} /* namespace controllers */

#endif /* BULLETCONTROLLER_H_ */
