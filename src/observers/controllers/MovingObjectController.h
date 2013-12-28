/*
 * MovingObjectController.h
 *
 *  Created on: Dec 16, 2013
 *      Author: kristof
 */

#ifndef MOVINGOBJECTCONTROLLER_H_
#define MOVINGOBJECTCONTROLLER_H_

#include "Controller.h"
#include "../../models/MovingObject.h"

namespace controllers {

class MovingObjectController : public Controller{
public:
	MovingObjectController(modelPtr model, modelViewPtr view, factories::DataParser);

	virtual ~MovingObjectController();

	/**
	 * Changes the speed of the moving object.
	 * @param multiplier The amount by which the speed needs to be increased/decreased. A value of 2 will double the speed for example.
	 */
	virtual void changeSpeed(double);
};

} /* namespace controllers */

#endif /* MOVINGOBJECTCONTROLLER_H_ */
