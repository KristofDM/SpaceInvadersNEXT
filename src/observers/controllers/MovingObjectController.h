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

	virtual void changeSpeed(double);
};

} /* namespace controllers */

#endif /* MOVINGOBJECTCONTROLLER_H_ */
