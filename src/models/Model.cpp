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

sf::Sprite Model::getSprite() {
	return sprite_;
}

sf::Vector2f Model::getPosition() {
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

sf::FloatRect Model::getBounds() {
	return sprite_.getGlobalBounds();
}

void Model::attach(std::shared_ptr<observers::Observer> obs) {
	registry_.push_back(obs);
}

void Model::detach(std::shared_ptr<observers::Observer> obs) {
	registry_.push_back(obs);
}

void Model::notify() {
	for (auto observer : registry_) {
		observer->update();
	}
}

EOrientation Model::getOrientation() {
	return orientation_;
}

} /* namespace models */
