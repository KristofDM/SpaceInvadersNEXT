///*
// * ViewFactory.cpp
// *
// *  Created on: Nov 29, 2013
// *      Author: kristof
// */
//
//#include "ViewFactory.h"
//
//namespace factories {
//
//ViewFactory::ViewFactory(std::shared_ptr<sf::RenderWindow> window)
//	: window_(window)
//{}
//
//ViewFactory::~ViewFactory() {
//	// TODO Auto-generated destructor stub
//}
//
//modelViewPtr ViewFactory::create(std::string dataFile, modelPtr model) {
//	DataParser data(dataFile);
//	switch (data.getType()) {
//	case ship:
//		return std::make_shared<views::SpaceShipView>(model, data, window_);
//		break;
//	case weapon:
//		return std::make_shared<views::BulletView>(model, data, window_);
//		break;
//	default:
//		break;
//	}
//}
//
//
//} /* namespace factories */
