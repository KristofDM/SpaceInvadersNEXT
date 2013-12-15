/*
 * HUD.cpp
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#include "HUD.h"

namespace models {

HUD::HUD()
	: StaticObject(none),
	  totalScore_(0),
	  lives_(0)
{}

HUD::~HUD() {
	// TODO Auto-generated destructor stub
}

void HUD::changePoints(int points) {

}

void HUD::changeLives(int lives) {

}

} /* namespace models */
