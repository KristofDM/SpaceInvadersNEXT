///*
// * ViewFactory.h
// *
// *  Created on: Nov 29, 2013
// *      Author: kristof
// */
//
//#ifndef VIEWFACTORY_H_
//#define VIEWFACTORY_H_
//
//#include <memory>
//#include <string>
//#include "DataParser.h"
//#include "../models/Model.h"
//
//namespace factories {
//
//
//namespace views {class ModelView; class SpaceShipView; class BulletView;}
////namespace models {class Model;}
//
//class ViewFactory {
//public:
//	ViewFactory(std::shared_ptr<sf::RenderWindow>);
//
//	virtual ~ViewFactory();
//
//	std::shared_ptr<views::ModelView> create(std::string, std::shared_ptr<models::Model>);
//
//private:
//	std::shared_ptr<sf::RenderWindow> window_;
//};
//
//} /* namespace factories */
//
//#endif /* VIEWFACTORY_H_ */
