/*
 * HUDView.h
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#ifndef HUDVIEW_H_
#define HUDVIEW_H_

#include <sstream>
#include "ModelView.h"
#include "../../models/HUD.h"
#include "../../models/Ship.h"

namespace views {

class HUDView : public ModelView{
public:
	HUDView(sf::Font, modelPtr, factories::DataParser, sf::RenderWindow&, modelPtr);
	virtual ~HUDView();
	virtual void update();
	virtual void draw();
	void drawEnd();

private:
	modelPtr spaceShip_;
	sf::Font font_;
	sf::Text score_;
	sf::Text lives_;
	sf::Text endMsg_;
	sf::Text level_;
};

} /* namespace views */

#endif /* HUDVIEW_H_ */
