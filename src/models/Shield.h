/*
 * Shield.h
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#ifndef SHIELD_H_
#define SHIELD_H_

#include "Model.h"
#include "StaticObject.h"

namespace models {

class Shield : public StaticObject {
public:
	Shield(EOrientation, int, unsigned int);

	virtual ~Shield();

	virtual bool collided(std::shared_ptr<Model>);

	virtual unsigned int getDamage();

private:
	int lives_;

	unsigned int damage_;
};

} /* namespace models */

#endif /* SHIELD_H_ */
