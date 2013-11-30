/*
 * Model.h
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "../observers/Observer.h"
#include "../Exception.h"
#include "../factories/DataParser.h"
#include "../factories/ControllerFactory.h"
#include "../factories/ViewFactory.h"

namespace models {

enum EOrientation {up, down, none};

class Model {
public:
	Model(EOrientation);

	virtual ~Model();

	//! Attaches Observer to our registry.
	void attach(std::shared_ptr<observers::Observer>);

	//! Detaches Observer from our registry.
	void detach(std::shared_ptr<observers::Observer>);

	sf::Sprite getSprite();

	sf::Vector2f getPosition();

	virtual void setUp(factories::DataParser);

	sf::FloatRect getBounds();

	virtual void moveLeft() = 0;

	virtual void moveRight() = 0;

	virtual void moveUp() = 0;

	virtual void moveDown() = 0;

	virtual bool shoot() = 0;

	EOrientation getOrientation();

protected:
	//! sprite_ is a member of the model because it's used in logic. (Data collision etc. is calculated with sprite_ methods.) It also hold the position etc.
	sf::Texture texture_;
	sf::Sprite sprite_;
	EOrientation orientation_;

	//! Registry that holds all Obervers.
	std::vector<std::shared_ptr<observers::Observer> > registry_;

	//! Notifies all observers of Model changes.
	virtual void notify();
};

} /* namespace models */

#endif /* MODEL_H_ */
