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
typedef std::shared_ptr<models::Model> modelPtr;

namespace views {

class ModelView : public observers::Observer{
public:
	ModelView(modelPtr, factories::DataParser, sf::RenderWindow&);

	virtual void update() = 0;

	virtual void draw();

	modelPtr getModel();

	sf::RenderWindow& getWindow();

	virtual ~ModelView();

protected:
	sf::RenderWindow& window_;
	modelPtr model_;
};

} /* namespace views */

#endif /* MODELVIEW_H_ */
