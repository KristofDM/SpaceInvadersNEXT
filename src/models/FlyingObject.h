/*
 * FlyingObject.h
 *
 *  Created on: Nov 30, 2013
 *      Author: kristof
 */

#ifndef FLYINGOBJECT_H_
#define FLYINGOBJECT_H_

#include "Model.h"

namespace models {

class FlyingObject : public Model {
public:
	FlyingObject(double, EOrientation);

	virtual ~FlyingObject();

	virtual void moveLeft();

	virtual void moveRight();

	virtual void moveUp();

	virtual void moveDown();

	virtual bool shoot() { };

private:
	double speed_;

};

} /* namespace models */

#endif /* FLYINGOBJECT_H_ */
