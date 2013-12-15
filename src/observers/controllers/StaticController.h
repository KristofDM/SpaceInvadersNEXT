/*
 * StaticController.h
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#ifndef STATICCONTROLLER_H_
#define STATICCONTROLLER_H_

#include "Controller.h"

namespace controllers {

class StaticController : public Controller {
public:
	StaticController(modelPtr model, modelViewPtr view, factories::DataParser data);

	virtual ~StaticController();

	virtual void handleMoveInput(unsigned int, unsigned int) { /* do nothing */};

	virtual void gameInput(std::vector<std::shared_ptr<mvcTriple> >&, unsigned int, unsigned int) { /* do nothing */};

	void setFlags(bool, bool);

};

} /* namespace controllers */

#endif /* STATICCONTROLLER_H_ */
