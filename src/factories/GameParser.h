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

typedef std::tuple<int, int, std::string, std::string, int> infoTuple;

namespace factories {

class GameParser {
public:
	GameParser();

	virtual ~GameParser();

	void parseGame(std::string);

	std::string getSpaceShipXML();

	infoTuple getShieldInfo();

	std::vector<infoTuple> getEnemyInfo();

private:
	std::string spaceShipXML_;

	infoTuple shieldInfo_;

	std::vector<infoTuple> enemyInfo_;

	void parseRow(TiXmlElement*, int);

};

} /* namespace factories */

#endif /* GAMEPARSER_H_ */
