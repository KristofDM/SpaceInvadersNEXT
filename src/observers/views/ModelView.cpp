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
//	std::shared_ptr<observers::Observer> thisView(this);
	observers::Observer* test = this;
//	std::weak_ptr<observers::Observer> tv2 = thisView;
//	thisView.reset();
	model_->attach(test);

}

//ModelView::ModelView(modelPtr model, factories::DataParser data)
//	: window_(),
//	  model_(model)
//{
////	std::shared_ptr<observers::Observer> thisView(this);
////	std::weak_ptr<observers::Observer> tv2 = thisView;
////	thisView.reset();
////	model_->attach(tv2);
//
//}

ModelView::~ModelView() {
//	std::weak_ptr<observers::Observer> thisView(this);
//	model_->detach(thisView);
//
//	model_.reset();
}

void ModelView::draw() {
	window_.draw(model_->getSprite());
}



sf::RenderWindow& ModelView::getWindow() {
	return window_;
}

} /* namespace views */
