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

	// Not applicable.
	virtual unsigned int getDamage() {return 0; }

	virtual bool collided(std::shared_ptr<Model>) {return false;}

	void changePoints(int);

	void addLevel(int);

	int getTotalScore() const;

	int getLevel() const;

private:
	int totalScore_;
	int level_;
};

} /* namespace models */

#endif /* HUD_H_ */
