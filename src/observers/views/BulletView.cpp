/*
 * BulletView.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: kristof
 */

#include "BulletView.h"

namespace views {

BulletView::BulletView(std::shared_ptr<models::Model> model, factories::DataParser data, sf::RenderWindow& window)
	: ModelView(model, data, window)
{
}

BulletView::~BulletView() {
	// TODO Auto-generated destructor stub
}

void BulletView::update() {
	this->draw();
}

void BulletView::draw() {
	window_.draw(model_->getSprite());
}

} /* namespace views */
