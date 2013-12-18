//============================================================================
// Name        : SP_INV_NEXT.cpp
// Author      : Kristof DM
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "GameController.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders NEXT");
    window.setFramerateLimit(60);
    sf::Texture texture_;
    sf::Sprite sprite_;

    try{
    		// Load texture/sprite
    		if(!texture_.loadFromFile("Graphics/space-1.png")) {
    			throw Exception("Could not load sprite on location Graphics/space-1");
    		}
    		sprite_.setTexture(texture_);
    	}
	catch (Exception& e) {
		std::cout << e.what() << std::endl;
	}

    controllers::GameController gameController(800, 600, window);
    gameController.setUp();

    while (window.isOpen()) {
    	// Main program loop.
		sf::Event event;
        while (window.pollEvent(event)) {
        	// Events loop (polling).
        	switch(event.type) {
				case sf::Event::Closed:
					window.close();
					return 0;
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Y && gameController.endGame()) {
						// RESET GAME
						gameController = controllers::GameController(800, 600, window);
						gameController.setUp();
					}
					else if (event.key.code == sf::Keyboard::N && gameController.endGame()) {
						window.close();
						return 0;
						break;
					}
					break;
				default:
					break;
        	}
        }
        window.clear();
        window.draw(sprite_);
    	gameController.cycle();
    	gameController.endGame();
    	gameController.render();
        window.display();
    }
    return 0;
}
