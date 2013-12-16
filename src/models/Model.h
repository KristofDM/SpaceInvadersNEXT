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

namespace models {

enum EOrientation {up, down, none};

class Model {
public:
	Model(EOrientation);

	virtual ~Model();

	//! Attaches Observer to our registry.
	void attach(observers::Observer* obs);

	//! Detaches Observer from our registry.
	void detach(observers::Observer* obs);

	sf::Sprite getSprite() const;

	sf::Vector2f getPosition() const;

	virtual void setUp(factories::DataParser data, int space = 0);

	sf::FloatRect getBounds() const;

	virtual void moveLeft() = 0;

	virtual void moveRight() = 0;

	virtual void moveUp() = 0;

	virtual void moveDown() = 0;

	virtual bool shoot() = 0;

	virtual bool collided(std::shared_ptr<Model>) = 0;

	virtual unsigned int getDamage() = 0;

	virtual bool checkCollision(std::shared_ptr<Model>) const;

	EOrientation getOrientation() const;

	bool checkRelevant(unsigned int, unsigned int) const;

	//! This will return the objects owner. By default this is itself.
	virtual std::shared_ptr<Model> getOwner();

	void markDeleted();

	bool getDeleted();

	virtual void setFlags(bool, bool) = 0;

protected:
	//! sprite_ is a member of the model because it's used in logic. (Data collision etc. is calculated with sprite_ methods.) It also hold the position etc.
	sf::Texture texture_;
	sf::Sprite sprite_;
	EOrientation orientation_;
	bool deleted_;
	bool invincible_;

	//! Registry that holds all Obervers.
	std::vector<observers::Observer*> registry_;

	//! Notifies all observers of Model changes.
	virtual void notify() const;
};

} /* namespace models */

#endif /* MODEL_H_ */
