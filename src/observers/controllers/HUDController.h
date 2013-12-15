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

namespace controllers {

class HUDController : public StaticController {
public:
	HUDController(modelPtr model, modelViewPtr view, factories::DataParser data);

	virtual ~HUDController();

	void changePoints(int);

	void changeLives(int);
};

} /* namespace controllers */

#endif /* HUDCONTROLLER_H_ */
