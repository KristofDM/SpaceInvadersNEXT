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
	totalScore_ += points;
	this->notify();
	std::cout << "totalScore_ = " << totalScore_ << std::endl;
}

void HUD::changeLives(int lives) {
	lives_ += lives;
	this->notify();
}

int HUD::getTotalScore() const {
	return totalScore_;
}

int HUD::getTotalLives() const {
	return lives_;
}

} /* namespace models */
