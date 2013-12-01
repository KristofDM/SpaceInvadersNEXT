/*
 * DataParser.h
 *
 *  Created on: Nov 24, 2013
 *      Author: kristof
 */

#ifndef DATAPARSER_H_
#define DATAPARSER_H_

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../tinyXML/tinyxml.h"
#include "../Exception.h"

namespace factories {

enum EDataType {ship, ammotype, enemyship, none};

class DataParser {
public:
	//! Divides the data file file in three parts: model_, view_ and controller_. Extracts info from all of these parts.
	DataParser();

	virtual ~DataParser();

	void parse(std::string);

	EDataType getType();

	sf::Vector2f getPos();
	int getLives();
	int getFireRate();
	double getSpeed();

	std::string getSpritePath();
	double getScale();

	int getMoveDirection();


private:

	EDataType type_;

	// Model
	sf::Vector2f pos_;
	int lives_;
	int fireRate_;
	double speed_;

	// View
	std::string sprite_;
	double scale_;

	// Controller
	int moveDirection_;

	//! Parses view portion of the data file.
	void parseView(TiXmlElement*);

	//! Parses model portion of the data file.
	void parseModel(TiXmlElement*);

	//! Parses controller portion of the data file.
	void parseController(TiXmlElement*);



};

} /* namespace factories */

#endif /* DATAPARSER_H_ */
