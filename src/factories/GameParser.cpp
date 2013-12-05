/*
 * GameParser.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#include "GameParser.h"

namespace factories {

GameParser::GameParser() {
	// TODO Auto-generated constructor stub

}

GameParser::~GameParser() {
	// TODO Auto-generated destructor stub
}

void GameParser::parseGame(std::string dataFile) {
	try {
		TiXmlDocument doc;
		if(!doc.LoadFile(dataFile.c_str())) {
			std::cout << doc.ErrorDesc() << std::endl;
			std::string errorMessage = doc.ErrorDesc();
			errorMessage += " " + dataFile;
			throw(Exception(errorMessage));
		}

		TiXmlElement* object = doc.FirstChildElement();

		if(object == NULL) {
			doc.Clear();
			throw(Exception("Failed to load file: No root element", 1));
		}
		for(TiXmlElement* o = object->FirstChildElement(); o != NULL; o = o->NextSiblingElement()) {
		std::string oPart = o->Value();
		std::cout << oPart << std::endl;
		if (oPart == "spaceShip") {
			// Parse spaceship info
			spaceShipXML_ = o->Attribute("file");
		}
		else if (oPart == "enemies") {
			// Parse enemies
			parseRow(o);
		}
		else if (oPart == "shield") {
			infoTuple shieldInfo(std::stoi(o->Attribute("amount")), o->Attribute("file"));
			shieldInfo_ = shieldInfo;
		}
		else {
			throw(Exception(oPart + " is not supported by the game parser."));
		}
		}
	}
	catch (Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void GameParser::parseRow(TiXmlElement* p) {
	try {
		for (TiXmlElement* var = p->FirstChildElement(); var != NULL; var = var->NextSiblingElement()) {
			std::string fieldName = var->Value();
			if (fieldName == "row") {
				infoTuple entry(std::stoi(var->Attribute("amount")), var->Attribute("file"));
				enemyInfo_.push_back(entry);
			}
			else {
				throw(Exception(fieldName + " is not a valid enemy row."));
			}
		}
	}
	catch(Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::string GameParser::getSpaceShipXML() {
	return spaceShipXML_;
}

infoTuple GameParser::getShieldInfo() {
	return shieldInfo_;
}

std::vector<infoTuple> GameParser::getEnemyInfo() {
	return enemyInfo_;
}

} /* namespace factories */
