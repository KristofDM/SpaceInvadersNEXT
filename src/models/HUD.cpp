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
	  level_(1)
{}

HUD::~HUD() {
	// TODO Auto-generated destructor stub
}

void HUD::changePoints(int points) {
	totalScore_ += points;
	this->notify();
}

void HUD::addLevel(int lives) {
	level_ += lives;
	this->notify();
}

int HUD::getTotalScore() const {
	return totalScore_;
}

int HUD::getLevel() const {
	return level_;
}

} /* namespace models */
