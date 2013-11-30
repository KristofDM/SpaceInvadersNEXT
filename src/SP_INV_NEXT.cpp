//============================================================================
// Name        : SP_INV_NEXT.cpp
// Author      : Kristof DM
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <memory>

#include "Game.h"
//#include "Utility.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders NEXT");

    game::Game game(800, 600, window);
    game.setUp();

    while (window.isOpen()) {
    	// Main program loop.
    	game.cycle();
		sf::Event event;
        while (window.pollEvent(event)) {
        	// Events loop (polling).
        	switch(event.type) {
				case sf::Event::Closed:
					window.close();
					// Should not use exit, no stack unwinding!
					exit(0);
//					return 0;
					break;
				default:
					break;
        	}
        }
        window.clear();
        game.render();
        window.display();
    }
    return 0;
}
