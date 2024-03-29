/*
 * Ship.h
 *
 *  Created on: Nov 23, 2013
 *      Author: kristof
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <vector>
#include <memory>
#include "Model.h"
#include "Bullet.h"
#include "MovingObject.h"
#include "Shield.h"

//#include "../observers/views/ModelView.h"
//#include "../factories/ViewFactory.h"
//#include "../factories/ControllerFactory.h"

namespace models {

class Ship : public MovingObject {
public:
	Ship(int, int, double, EOrientation);

	virtual int getLives();

	void setLives(int);

	int getFireRate();

	void setFireRate(int);

	virtual ~Ship();

	virtual bool shoot();

	virtual bool collided(std::shared_ptr<Model>);

	virtual unsigned int getDamage();

	virtual void setFlags(bool, bool);

	virtual bool getFatalCollision() const;

protected:
	int lives_;

	int fireRate_;

	unsigned int damage_;

	sf::Clock shootTimer_;

	sf::Clock invincibleTimer_;

	bool shooting_;

	bool fatalCollision_;
};

} /* namespace models */

#endif /* SHIP_H_ */
