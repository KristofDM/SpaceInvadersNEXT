/*
 * HUDView.cpp
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#include "HUDView.h"

namespace views {

HUDView::HUDView(sf::Font font, modelPtr model, factories::DataParser data, sf::RenderWindow& window, modelPtr spaceShip)
	: ModelView(model, data, window),
	  spaceShip_(spaceShip),
	  font_(font),
	  score_(),
	  lives_(),
	  endMsg_("You lose! Play again? (y/n)"),
	  level_()
{
	observers::Observer* test = this;
	spaceShip->attach(test);
}

HUDView::~HUDView() {
	// TODO Auto-generated destructor stub
}

void HUDView::update() {
	// Update our texts.
	std::shared_ptr<models::HUD> test = std::dynamic_pointer_cast<models::HUD>(model_);
	std::shared_ptr<models::Ship> ship = std::dynamic_pointer_cast<models::Ship>(spaceShip_);
	if (test != nullptr && ship != nullptr) {

		std::stringstream ss;

		ss << "Score: ";
		ss << test->getTotalScore();
		std::string score = ss.str();
		ss.str("");
		score_ = sf::Text(score, font_, 20);
		score_.setColor(sf::Color(100, 100, 100));
		score_.setPosition(0, 0);

		ss << "Lives: ";
		ss << ship->getLives();
		std::string lives = ss.str();
		ss.str("");
		lives_ = sf::Text(lives, font_, 20);
		lives_.setColor(sf::Color(100, 100, 100));
		lives_.setPosition(350, 0);

		ss << "Level: ";
		ss << test->getLevel();
		std::string level = ss.str();
		ss.str("");
		level_ = sf::Text(level, font_, 20);
		level_.setColor(sf::Color(100, 100, 100));
		level_.setPosition(650, 0);
	}
	this->draw();
}

void HUDView::draw() {
		window_.draw(lives_);
		window_.draw(score_);
		window_.draw(level_);
}

void HUDView::drawEnd() {
	endMsg_.setPosition(25, 50);
	endMsg_.setFont(font_);
	endMsg_.setColor(sf::Color(100, 100, 100));
	window_.draw(endMsg_);
}


} /* namespace views */
