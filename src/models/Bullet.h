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
	Bullet(std::shared_ptr<Model> owner, sf::Vector2f pos, EOrientation orientation);

	virtual ~Bullet();

	virtual void setUp(factories::DataParser, int space = 0);

	virtual std::shared_ptr<Model> getOwner();

	virtual unsigned int getDamage();

	virtual bool collided(std::shared_ptr<Model>);

private:
	unsigned int damage_;

	std::shared_ptr<Model> owner_;

	sf::Vector2f initPosition_;
};

} /* namespace models */

#endif /* BULLET_H_ */
