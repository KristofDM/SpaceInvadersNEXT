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
	BulletView(modelPtr model, factories::DataParser data, sf::RenderWindow& window);

	virtual ~BulletView();

	virtual void update();

	virtual void draw();

private:

};

} /* namespace views */

#endif /* BULLETVIEW_H_ */
