/*
 * SpaceShipView.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: kristof
 */

#include "SpaceShipView.h"

namespace views {

SpaceShipView::SpaceShipView(std::shared_ptr<models::Model> model, factories::DataParser data, sf::RenderWindow& window)
	: ModelView(model, data, window)
{
}

void SpaceShipView::update() {
	this->draw();
}

void SpaceShipView::draw() {
	window_.draw(model_->getSprite());
}


} /* namespace views */
