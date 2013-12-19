/*
 * ModelView.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#include "ModelView.h"

namespace views {

ModelView::ModelView(modelPtr model, factories::DataParser data, sf::RenderWindow& window)
	: window_(window),
	  model_(model)
{
	observers::Observer* test = this;
	model_->attach(test);

}

ModelView::~ModelView() {
}

void ModelView::draw() {
	window_.draw(model_->getSprite());
}

sf::RenderWindow& ModelView::getWindow() {
	return window_;
}

} /* namespace views */
