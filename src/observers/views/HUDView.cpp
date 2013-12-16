/*
 * HUDView.cpp
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#include "HUDView.h"

namespace views {

HUDView::HUDView(sf::Font font, modelPtr model, factories::DataParser data, sf::RenderWindow& window)
	: ModelView(model, data, window),
	  font_(font),
	  score_(),
	  lives_(),
	  endMsg_()
{

}

HUDView::~HUDView() {
	// TODO Auto-generated destructor stub
}

void HUDView::update() {
	// Update our texts.

	std::shared_ptr<models::HUD> test = std::dynamic_pointer_cast<models::HUD>(model_);
	if (test != nullptr) {
		std::cout << "ALLEJOPPA" << std::endl;
		std::string score = "Score: " + test->getTotalScore();
		score_ = sf::Text(score, font_, 30);

		std::string lives = "Lives: " + test->getTotalLives();
		lives_ = sf::Text(lives, font_, 30);
	}

	this->draw();
}

void HUDView::draw() {
	window_.draw(lives_);
	window_.draw(score_);
}

void HUDView::drawEnd(bool gameOver) {
	if (gameOver) {
		window_.draw(endMsg_);
	}
}


} /* namespace views */
