/*
 * Observer.h
 *
 *  Created on: Nov 23, 2013
 *      Author: kristof
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

namespace observers {

class Observer {
public:
	// Is called when the observed entity has changed.
	virtual void update() = 0;
	virtual ~Observer();
};

} /* namespace observers */

#endif /* OBSERVER_H_ */
