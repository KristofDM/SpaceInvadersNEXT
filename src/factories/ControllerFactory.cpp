///*
// * ControllerFactory.cpp
// *
// *  Created on: Nov 29, 2013
// *      Author: kristof
// */
//
//#include "ControllerFactory.h"
//
//namespace factories {
//
//ControllerFactory::ControllerFactory()
//{}
//
//ControllerFactory::~ControllerFactory() {
//	// TODO Auto-generated destructor stub
//}
//
////controllerPtr ControllerFactory::create(std::string dataFile, modelPtr model, modelViewPtr view) {
////	try {
////		DataParser data(dataFile);
////		switch (data.getType()) {
////		case ship:
////			return std::make_shared<controllers::ShipController>(model, view, data);
////			break;
////		case weapon:
////			return std::make_shared<controllers::BulletController>(model, view, data);
////			break;
////		default:
////			throw(Exception("Something went wrong in the Controller Factory."));
////		}
////	}
////	catch(Exception& e) {
////		std::cout << e.what() << std::endl;
////	}
////}
//
//} /* namespace factories */
