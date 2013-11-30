/*
 * ModelView.h
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#ifndef MODELVIEW_H_
#define MODELVIEW_H_

#include <memory>
#include <SFML/Graphics.hpp>
#include <utility>
#include <iostream>
#include "../../models/Model.h"
#include "../../Exception.h"
#include "../../factories/DataParser.h"

namespace views {

class ModelView : public observers::Observer{
public:
	ModelView(std::shared_ptr<models::Model>, factories::DataParser, sf::RenderWindow&);

	virtual void update() = 0;

	virtual void draw() = 0;

	std::shared_ptr<models::Model> getModel();

	sf::RenderWindow& getWindow();

	virtual ~ModelView();

protected:
	sf::RenderWindow& window_;
	std::shared_ptr<models::Model> model_;
};



//class AlienView : public ModelView {
//public:
//	AlienView(sf::Sprite, std::shared_ptr<sf::RenderWindow>);
////	virtual void updateView();
//	virtual ~AlienView();
//private:
//};

} /* namespace views */

#endif /* MODELVIEW_H_ */
