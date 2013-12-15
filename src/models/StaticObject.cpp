/*
 * StaticObject.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#include "StaticObject.h"

namespace models {

StaticObject::StaticObject(EOrientation orientation)
	: Model(orientation)
{}

StaticObject::~StaticObject() {
	// TODO Auto-generated destructor stub
}

void StaticObject::setFlags(bool invincible, bool shooting) {
	invincible_ = invincible;
}



} /* namespace models */
