/*
 * HUDFactory.cpp
 *
 *  Created on: Dec 18, 2013
 *      Author: kristof
 */

#include "HUDFactory.h"

namespace factories {

HUDFactory::HUDFactory() {
	// TODO Auto-generated constructor stub

}

HUDFactory::~HUDFactory() {
	// TODO Auto-generated destructor stub
}

controllerPtr HUDFactory::getController(std::string file, modelPtr spaceShip, sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("Graphics/SPACEMAN.TTF"))
    {
    	std::cerr << "font didn't get loaded." << std::endl;
    }
    std::shared_ptr<models::Model> HUDModel = std::make_shared<models::HUD>();
    std::shared_ptr<views::ModelView> HUDView = std::make_shared<views::HUDView>(font, HUDModel, factories::DataParser(), window, spaceShip);
    std::shared_ptr<controllers::Controller> HUDController = std::make_shared<controllers::HUDController>(HUDModel, HUDView, factories::DataParser());
    HUDView->update();

    return HUDController;
}

} /* namespace factories */
