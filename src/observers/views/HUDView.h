/*
 * HUDView.h
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#ifndef HUDVIEW_H_
#define HUDVIEW_H_

#include "ModelView.h"

namespace views {

class HUDView : public ModelView{
public:
	HUDView(sf::Font, modelPtr, factories::DataParser, sf::RenderWindow&);
	virtual ~HUDView();
	virtual void update();
	virtual void draw();

private:
	sf::Font font_;
	sf::Text score_;
	sf::Text lives_;
	sf::Text endMsg_;
};

} /* namespace views */

#endif /* HUDVIEW_H_ */
