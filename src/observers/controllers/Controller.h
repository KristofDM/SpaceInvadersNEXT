/*
 * Controller.h
 *
 *  Created on: Nov 22, 2013
 *      Author: kristof
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <tuple>
#include <list>
#include <iostream>
#include <memory>
#include "../../models/Model.h"
#include "../views/ModelView.h"

typedef std::shared_ptr<models::Model> modelPtr;
typedef std::shared_ptr<views::ModelView> modelViewPtr;

namespace controllers {

enum EMoveDirection {x, y, xy, none};

class Controller;
typedef std::shared_ptr<controllers::Controller> controllerPtr;
typedef std::tuple<modelPtr, modelViewPtr, std::shared_ptr<Controller> > mvcTriple;

class Controller : public observers::Observer{
public:
	/**
	 * @param model The model (Entity) this controller will control.
	 * @param view The view this controller will control (and which will take care of the rendering of the model.
	 * @param data Object containing additional information about our to-be constructed object.
	 */
	Controller(modelPtr, modelViewPtr, factories::DataParser);

	virtual ~Controller();

	virtual void update() { /* Do nothing yet. Controller is a possible observer. */ }

	/**
	 * @param height The height of our game area.
	 * @param width The width of our game area.
	 */
	virtual void handleMoveInput(unsigned int, unsigned int) = 0;

	/**
	 * Will take care of things like moving and shooting.
	 */
	virtual void gameInput(std::vector<controllerPtr>&, unsigned int, unsigned int) = 0;

	/**
	 * Gives the ability to set two flags. These will usually be the invincible and shooting flags.
	 */
	virtual void setFlags(bool, bool);

	/**
	 * Asks whether or not the Entity this controller has control over is still relevant.
	 * @return True if it's still relevant, false if it isn't.
	 */
	virtual bool checkRelevant(unsigned int, unsigned int);

	/**
	 * Marks the model as ready to be deleted.
	 */
	virtual void markDeleted();

	/**
	 * Lets the Entity know it has collided with the parameter object.
	 * @return True if the effects of the collision were as we would think they were. (decreased hp etc.)
	 * @return False if it failed. (Because the model was invincible for example.)
	 */
	virtual bool collided(modelPtr);

	/**
	 * Lets the entity check if it has collided with the parameter object.
	 * @return True if they collided, false if they didn't.
	 */
	virtual bool checkCollision(modelPtr);

	/**
	 * Sends signal to the view that there needs to be rendered.
	 */
	virtual void draw();

	/**
	 * @return Returns the Entity (model) it has control over.
	 */
	virtual modelPtr getModel();

protected:
	modelPtr model_;
	modelViewPtr view_;
	EMoveDirection moveDir_;
};

} /* namespace controllers */

#endif /* CONTROLLER_H_ */
