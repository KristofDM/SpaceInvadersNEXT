/*
 * HUDView.cpp
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#include "HUDView.h"

namespace views {

HUDView::HUDView(sf::Font font, modelPtr model, factories::DataParser data, sf::RenderWindow& window)
	: ModelView(model, data, window),
	  font_(font),
	  score_(),
	  lives_(),
	  endMsg_()
{

}

HUDView::~HUDView() {
	// TODO Auto-generated destructor stub
}

void HUDView::update() {
	this->draw();
}

void HUDView::draw() {
	window_.draw(lives_);
	window_.draw(score_);

//	if (endgame is true -> DRAW ENDGAIM)
}


} /* namespace views */
