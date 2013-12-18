/*
 * BulletController.h
 *
 *  Created on: Nov 29, 2013
 *      Author: kristof
 */

#ifndef BULLETCONTROLLER_H_
#define BULLETCONTROLLER_H_

#include "Controller.h"
#include <list>
#include <vector>

typedef std::shared_ptr<models::Model> modelPtr;


namespace controllers {

class BulletController : public Controller{
public:
	BulletController(modelPtr model, modelViewPtr view, factories::DataParser data);

	virtual ~BulletController();

	virtual void handleMoveInput(unsigned int, unsigned int);

	virtual void gameInput(std::vector<controllerPtr>&, unsigned int, unsigned int);

};

} /* namespace controllers */

#endif /* BULLETCONTROLLER_H_ */
