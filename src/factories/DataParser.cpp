/*
 * DataParser.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: kristof
 */

#include "DataParser.h"

namespace factories {

DataParser::DataParser()
	: type_(none),
	  pos_(),
	  lives_(-1),
	  fireRate_(-1),
	  speed_(-1),
	  sprite_(),
	  scale_(-1),
	  moveDirection_(-1),
	  space_(0),
	  points_(0)
{}

// Parse datafiles.

void DataParser::parseObject(std::string dataFile) {
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
			if (oPart == "type") {
				TiXmlText* text = o->FirstChild()->ToText();
				std::string typeName = text->Value();
				if (typeName == "ammotype") {
					type_ = ammotype;
				}
				else if (typeName == "ship") {
					type_ = ship;
				}
				else if (typeName == "enemyship") {
					type_ = enemyship;
				}
				else {
					throw(Exception(typeName + " is an unknown type of object."));
				}
			}
			else if (oPart == "model") {
				this->parseModel(o);
			}
			else if (oPart == "view") {
				this->parseView(o);
			}
			else if (oPart == "controller") {
				this->parseController(o);
			}
			else {
				// Invalid CFG
				doc.Clear();
				std::string errormsg = "Unrecognized data in datafile.";
				throw(Exception(errormsg, 1));
			}
		}
	}
	catch (Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

DataParser::~DataParser() {
	// TODO Auto-generated destructor stub
}

void DataParser::parseView(TiXmlElement* p) {
	try {
		for (TiXmlElement* var = p->FirstChildElement(); var != NULL; var = var->NextSiblingElement()) {
			std::string fieldName = var->Value();
			if(fieldName == "sprite") {
				 TiXmlText* text = var->FirstChild()->ToText();
				 if (text == NULL) {
					 throw Exception("No sprite specified for object.");
				 }
				 std::string name = text->Value();
				 std::string location = "Graphics/" + name;
				 sprite_ = location;
			}
			else if (fieldName == "scale") {
				 TiXmlText* text = var->FirstChild()->ToText();
				 if (text == NULL) {
					 throw Exception("No scale specified for object.");
				 }
				 std::string value = text->Value();
				 scale_ = std::stod(value);
			}
			else {
				throw Exception("Unknown fieldname: " + fieldName);
			}
		}
	}
	catch(Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void DataParser::parseModel(TiXmlElement* p) {
	try {
		for (TiXmlElement* var = p->FirstChildElement(); var != NULL; var = var->NextSiblingElement()) {
			std::string fieldName = var->Value();
			if(fieldName == "position") {
				sf::Vector2f pos(std::stod(var->Attribute("x")), std::stod(var->Attribute("y")));
				pos_ = pos;
			}
			else if (fieldName == "lives") {
				TiXmlText* text = var->FirstChild()->ToText();
				 if (text == NULL) {
					 // No value given.
					 throw Exception("No amount of lives specified for object.");
				 }
				 std::string value = text->Value();
				 lives_ = std::stoi(value);
			}
			else if (fieldName == "fireRate") {
				TiXmlText* text = var->FirstChild()->ToText();
				 if (text == NULL) {
					 // No value given.
					 throw Exception("FireRate not specified for object.");
				 }
				 std::string value = text->Value();
				 fireRate_ = std::stoi(value);
			}
			else if (fieldName == "speed") {
				TiXmlText* text = var->FirstChild()->ToText();
				 if (text == NULL) {
					 // No value given.
					 throw Exception("Speed not specified for object.");
				 }
				 std::string value = text->Value();
				 speed_ = std::stod(value);
			}
			else if (fieldName == "space") {
				TiXmlText* text = var->FirstChild()->ToText();
				 if (text == NULL) {
					 // No value given.
					 throw Exception("Space not specified for object.");
				 }
				 std::string value = text->Value();
				 space_ = std::stoi(value);
			}
			else if (fieldName == "points" && type_ == enemyship) {
				TiXmlText* text = var->FirstChild()->ToText();
				 if (text == NULL) {
					 // No value given.
					 throw Exception("Points_ not specified for object.");
				 }
				 std::string value = text->Value();
				 points_ = std::stoi(value);
			}
		}
	}
	catch(Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void DataParser::parseController(TiXmlElement* p) {
	try {
		for (TiXmlElement* var = p->FirstChildElement(); var != NULL; var = var->NextSiblingElement()) {
			std::string fieldName = var->Value();
			if(fieldName == "move") {
				std::string dir = var->Attribute("direction");
				if (dir != "x" && dir != "xy" && dir != "y" && dir != "none") {
					throw Exception("Direction " + dir + " is not supported.");
				}
				if (dir == "x") {
					moveDirection_ = 0;
				}
				else if (dir == "y") {
					moveDirection_ = 1;
				}
				else if (dir == "xy") {
					moveDirection_ = 2;
				}
				else if (dir == "none") {
					moveDirection_ = 3;
				}
			}
		}
	}
	catch(Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

sf::Vector2f DataParser::getPos() const{
	return pos_;
}

int DataParser::getLives() const{
	return lives_;
}

int DataParser::getFireRate() const{
	return fireRate_;
}

std::string DataParser::getSpritePath() const{
	return sprite_;
}

double DataParser::getScale() const{
	return scale_;
}

int DataParser::getMoveDirection() const{
	return moveDirection_;
}

double DataParser::getSpeed() const{
	return speed_;
}

EDataType DataParser::getType() const{
	return type_;
}

int DataParser::getSpace() const{
	return space_;
}

int DataParser::getPoints() const{
	return points_;
}


} /* namespace factories */
