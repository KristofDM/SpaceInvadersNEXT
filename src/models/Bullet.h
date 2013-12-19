/*
 * Bullet.h
 *
 *  Created on: Nov 28, 2013
 *      Author: kristof
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "Model.h"
#include "MovingObject.h"

namespace models {

class Bullet : public MovingObject {
public:
	//! Construct its base class, set position and orientation.
	Bullet(std::shared_ptr<Model> owner, sf::Vector2f pos, EOrientation orientation);

	virtual ~Bullet();

	//! Setup the entity.
	virtual void setUp(factories::DataParser, int space = 0);

	//! Return the owner of this bullet object.
	virtual std::shared_ptr<Model> getOwner();

	//! Return the damage this bullet deals.
	virtual unsigned int getDamage();

	//! Specify what happens when this object has collided with another object.
	virtual bool collided(std::shared_ptr<Model>);

private:
	unsigned int damage_;

	std::shared_ptr<Model> owner_;

	sf::Vector2f initPosition_;
};

} /* namespace models */

#endif /* BULLET_H_ */
