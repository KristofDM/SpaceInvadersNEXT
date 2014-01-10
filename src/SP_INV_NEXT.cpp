//============================================================================
// Name        : SP_INV_NEXT.cpp
// Author      : Kristof DM
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "GameController.h"

int main(int argc, char* argv[]) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders NEXT");
    window.setFramerateLimit(60);

    std::string gameFile = "";

    if (argc == 1) {
    	std::cout << "No game XML file specified: the standard game will launch." << std::endl;
    	gameFile = "Data/game1.xml";
    }
    else if (argc == 2) {
    	gameFile = argv[2];
    }
    else {
    	std::cout << "Invalid amount of parameters: either use 0 or 1 parameter (the game xml file)" << std::endl;
    	exit(1);
    }

    game::GameController gameController(800, 600, window, gameFile);
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
						gameController = game::GameController(800, 600, window);
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
