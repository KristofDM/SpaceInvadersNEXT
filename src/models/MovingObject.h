/*
 * MovingObject.h
 *
 *  Created on: Nov 30, 2013
 *      Author: kristof
 */

#ifndef MovingObject_H_
#define MovingObject_H_

#include "Model.h"

namespace models {

class MovingObject : public Model {
public:
	MovingObject(double, EOrientation);

	virtual ~MovingObject();

	virtual void moveLeft();

	virtual void moveRight();

	virtual void moveUp();

	virtual void moveDown();

	virtual bool shoot() {return false;};

	virtual unsigned int getDamage() = 0;

	virtual bool collided(std::shared_ptr<Model>) = 0;

	virtual void setFlags(bool, bool);

	virtual void changeSpeed(double);

protected:
	double speed_;

};

} /* namespace models */

#endif /* MovingObject_H_ */
