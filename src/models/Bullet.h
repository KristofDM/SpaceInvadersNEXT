/*
 * Bullet.h
 *
 *  Created on: Nov 28, 2013
 *      Author: kristof
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "Model.h"
#include "FlyingObject.h"

namespace models {

class Bullet : public FlyingObject {
public:
	Bullet(std::shared_ptr<Model> owner, sf::Vector2f pos, EOrientation orientation);

	virtual ~Bullet();

	virtual void setUp(factories::DataParser);

private:
	unsigned int damage_;

	std::shared_ptr<Model> owner_;

	sf::Vector2f initPosition_;
};

} /* namespace models */

#endif /* BULLET_H_ */
