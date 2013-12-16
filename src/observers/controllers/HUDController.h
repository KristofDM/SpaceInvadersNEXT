/*
 * HUDController.h
 *
 *  Created on: Dec 15, 2013
 *      Author: kristof
 */

#ifndef HUDCONTROLLER_H_
#define HUDCONTROLLER_H_

#include "StaticController.h"
#include "../../models/HUD.h"
#include "../views/HUDView.h"

namespace controllers {

class HUDController : public StaticController {
public:
	HUDController(modelPtr model, modelViewPtr view, factories::DataParser data);

	virtual ~HUDController();

	void changePoints(int);

	void addLevel(int);

	void drawEnd();

};

} /* namespace controllers */

#endif /* HUDCONTROLLER_H_ */
