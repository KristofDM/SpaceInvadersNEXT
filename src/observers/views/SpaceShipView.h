/*
 * SpaceShipView.h
 *
 *  Created on: Nov 29, 2013
 *      Author: kristof
 */

#ifndef SPACESHIPVIEW_H_
#define SPACESHIPVIEW_H_

#include <memory>
#include "ModelView.h"

namespace views {

class SpaceShipView : public ModelView {
public:

	/**
	 * Constructor, constructs base object and subscribes to the change-propagation mechanism of the model (the Observer registry). Also sets up the relationship to the controller.
	 * After the controller is initialized the view displays itself on the screen.
	 */
	SpaceShipView(std::shared_ptr<models::Model>, factories::DataParser, sf::RenderWindow&);

	//! Updates our model. (Could check if there is an actual change and then update or could just always redraw.)
	virtual void update();

	//! Renders our model.
	virtual void draw();

private:
};

} /* namespace views */

#endif /* SPACESHIPVIEW_H_ */
