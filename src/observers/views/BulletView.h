/*
 * BulletView.h
 *
 *  Created on: Nov 29, 2013
 *      Author: kristof
 */

#ifndef BULLETVIEW_H_
#define BULLETVIEW_H_

#include "ModelView.h"

namespace views {

class BulletView : public ModelView {
public:
	/**
	 * Constructor, constructs base object and subscribes to the change-propagation mechanism of the model (the Observer registry). Also sets up the relationship to the controller.
	 * After the controller is initialized the view displays itself on the screen.
	 */
	BulletView(modelPtr model, factories::DataParser data, sf::RenderWindow& window);

	virtual ~BulletView();

	//! Updates our model. (Could check if there is an actual change and then update or could just always redraw.)
	virtual void update();

	//! Renders our model.
	virtual void draw();

private:

};

} /* namespace views */

#endif /* BULLETVIEW_H_ */
