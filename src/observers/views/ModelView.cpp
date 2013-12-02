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
	std::shared_ptr<observers::Observer> thisView(this);
	model_->attach(thisView);
}

ModelView::~ModelView() {
	std::shared_ptr<observers::Observer> thisView(this);
	model_->detach(thisView);
}

sf::RenderWindow& ModelView::getWindow() {
	return window_;
}

} /* namespace views */
