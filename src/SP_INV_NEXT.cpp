//============================================================================
// Name        : SP_INV_NEXT.cpp
// Author      : Kristof DM
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "Game.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders NEXT");
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

    game::Game game(800, 600, window);
    game.setUp();

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
					if (event.key.code == sf::Keyboard::Y && game.endGame()) {
						// RESET GAME
						game = game::Game(800, 600, window);
						game.setUp();
					}
					else if (event.key.code == sf::Keyboard::N && game.endGame()) {
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
    	game.cycle();
        game.endGame();
        game.render();
        window.display();
    }
    return 0;
}
