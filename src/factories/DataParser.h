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
	DataParser();

	virtual ~DataParser();

	//! Parses the provided dataFile to usable information for classes.
	void parseObject(std::string);

	EDataType getType() const;

	sf::Vector2f getPos() const;
	int getLives() const;
	int getFireRate() const;
	double getSpeed() const;
	int getSpace() const;
	int getPoints() const;

	std::string getSpritePath() const;
	double getScale() const;

	int getMoveDirection() const;

private:
	EDataType type_;

	// Model
	sf::Vector2f pos_;
	int lives_;
	int fireRate_;
	double speed_;
	int space_;
	int points_;

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
