/*
 * GameParser.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: kristof
 */

#include "GameParser.h"

namespace factories {

GameParser::GameParser()
	: file_("")
{}

GameParser::~GameParser() {
	// TODO Auto-generated destructor stub
}

void GameParser::parseGame(std::string dataFile) {
	try {

		file_ = dataFile;

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
		if (oPart == "spaceShip") {
			// Parse spaceship info
			spaceShipXML_ = o->Attribute("file");
		}
		else if (oPart == "enemies") {
			// Parse enemies
			int amount = std::stoi(o->Attribute("maxSize"));
			parseRow(o, amount, std::stod(o->Attribute("speed")));
		}
		else if (oPart == "shield") {
			infoTuple shieldInfo(std::stoi(o->Attribute("amount")), std::stoi(o->Attribute("space")), o->Attribute("file"), "", 0, 0);
			shieldInfo_ = shieldInfo;
		}
		else if (oPart == "level") {
			speedMultiplier_ = std::stod(o->Attribute("multiplier"));
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

void GameParser::parseRow(TiXmlElement* p, int amount, double speed) {
	try {
		for (TiXmlElement* var = p->FirstChildElement(); var != NULL; var = var->NextSiblingElement()) {
			std::string fieldName = var->Value();
			if (fieldName == "row") {
				infoTuple entry(amount, std::stoi(var->Attribute("space")), var->Attribute("file"), var->Attribute("order"), std::stoi(var->Attribute("moveAmount")), speed);
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

std::string GameParser::getSpaceShipXML() const{
	return spaceShipXML_;
}

infoTuple GameParser::getShieldInfo() const{
	return shieldInfo_;
}

std::vector<infoTuple> GameParser::getEnemyInfo() const{
	return enemyInfo_;
}

double GameParser::getSpeedMult() const{
	return speedMultiplier_;
}

std::string GameParser::getFileName() const {
	return file_;
}

} /* namespace factories */
