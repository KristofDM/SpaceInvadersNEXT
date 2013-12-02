/*
 * Model.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#include "Model.h"

namespace models {

Model::Model(EOrientation orientation)
	: orientation_(orientation)
{}

Model::~Model() {

}

sf::Sprite Model::getSprite() const {
	return sprite_;
}

sf::Vector2f Model::getPosition() const {
	return sprite_.getPosition();
}


void Model::setUp(factories::DataParser data) {
	try{
		// Load texture/sprite
		if(!texture_.loadFromFile(data.getSpritePath())) {
			throw Exception("Could not load sprite on location " + data.getSpritePath());
		}
		sprite_.setTexture(texture_);
		sprite_.setPosition(data.getPos());
	}
	catch (Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

sf::FloatRect Model::getBounds() const {
	return sprite_.getGlobalBounds();
}

void Model::attach(std::shared_ptr<observers::Observer> obs) {
	registry_.push_back(obs);
}

void Model::detach(std::shared_ptr<observers::Observer> obs) {
	registry_.push_back(obs);
}

void Model::notify() const {
	for (auto observer : registry_) {
		observer->update();
	}
}

EOrientation Model::getOrientation() const {
	return orientation_;
}

bool Model::checkRelevant(unsigned int width, unsigned int height) const {
	if ((sprite_.getPosition().y + sprite_.getGlobalBounds().height)  < 0 || (sprite_.getPosition().y) > height) {
		// Height
		return false;
	}
	else if ((sprite_.getPosition().x + sprite_.getGlobalBounds().width) < 0 || sprite_.getPosition().x > width) {
		// Width
		return false;
	}
	else {
		return true;
	}
}

std::shared_ptr<Model> Model::getOwner() {
	return nullptr;
}

bool Model::checkCollision(std::shared_ptr<Model> other) const{
	sf::Vector2f otherPos = other->getSprite().getPosition();
	sf::Vector2f thisPos = sprite_.getPosition();
	if (otherPos.x >= thisPos.x && otherPos.x <= (thisPos.x + sprite_.getGlobalBounds().width) && otherPos.y >= thisPos.y && otherPos.y <= (thisPos.y + sprite_.getGlobalBounds().height)) {
		if (this == other->getOwner().get()) {
			// Colliding with its owner, nothing happens.
			return false;
		}
		return true;
	}
	return false;
}

} /* namespace models */
