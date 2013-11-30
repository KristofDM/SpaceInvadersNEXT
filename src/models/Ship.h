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
#include "FlyingObject.h"
//#include "../observers/views/ModelView.h"
//#include "../factories/ViewFactory.h"
//#include "../factories/ControllerFactory.h"

namespace models {

class Ship : public FlyingObject {
public:
	Ship(int, int, double, EOrientation);

	int getLives();

	void setLives(int);

	int getFireRate();

	void setFireRate(int);

	virtual ~Ship();

	virtual bool shoot();



protected:
	int lives_;

	int fireRate_;

	std::vector<std::shared_ptr<Bullet> > bullets;

	sf::Clock clock_;
};

} /* namespace models */

#endif /* SHIP_H_ */
