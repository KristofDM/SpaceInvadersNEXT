/*
 * StaticObject.h
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#ifndef STATICOBJECT_H_
#define STATICOBJECT_H_

#include "Model.h"

namespace models {

class StaticObject : public Model {
public:
	StaticObject(EOrientation);

	virtual ~StaticObject();

	virtual void moveLeft() { };

	virtual void moveRight() { };

	virtual void moveUp() { };

	virtual void moveDown() { };

	virtual bool shoot() {return false;};

	virtual unsigned int getDamage() = 0;

	virtual bool collided(std::shared_ptr<Model>) = 0;

};


} /* namespace models */

#endif /* STATICOBJECT_H_ */
