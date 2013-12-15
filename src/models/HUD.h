/*
 * HUD.h
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#ifndef HUD_H_
#define HUD_H_

#include "StaticObject.h"

namespace models {

class HUD : public StaticObject {
public:
	HUD();
	virtual ~HUD();

	virtual unsigned int getDamage() { }

	virtual bool collided(std::shared_ptr<Model>) { }

	void changePoints(int);

	void changeLives(int);

private:
	int totalScore_;
	int lives_;
};

} /* namespace models */

#endif /* HUD_H_ */
