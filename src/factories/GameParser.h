/*
 * GameParser.h
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#ifndef GAMEPARSER_H_
#define GAMEPARSER_H_

#include <tuple>
#include <string>
#include <vector>
#include <iostream>
#include "../tinyXML/tinyxml.h"
#include "../Exception.h"

//! In the format: amount, space, file, order, moveAmount, speed
typedef std::tuple<int, int, std::string, std::string, int, double> infoTuple;

namespace factories {

class GameParser {
public:
	GameParser();

	virtual ~GameParser();

	void parseGame(std::string);

	std::string getSpaceShipXML() const;
	infoTuple getShieldInfo() const;
	std::vector<infoTuple> getEnemyInfo() const;
	double getSpeedMult() const;
	std::string getFileName() const;
	std::string getBGFile() const;
private:
	std::string file_;

	std::string spaceShipXML_;

	infoTuple shieldInfo_;

	std::vector<infoTuple> enemyInfo_;

	double speedMultiplier_;

	std::string bgFile_;

	void parseRow(TiXmlElement*, int, double);

};

} /* namespace factories */

#endif /* GAMEPARSER_H_ */
