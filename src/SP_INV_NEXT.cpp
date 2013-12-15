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

    sf::Font font;
	// Load it from a file
	if (!font.loadFromFile("Graphics/SPACEMAN.TTF"))
	{
		// Throw exception
	}

	sf::Text text("Space Invaders: NEXT", font, 30);
	text.setColor(sf::Color(100, 100, 100));

    while (window.isOpen()) {
    	// Main program loop.
    	game.cycle();
		sf::Event event;
        while (window.pollEvent(event)) {
        	// Events loop (polling).
        	switch(event.type) {
				case sf::Event::Closed:
					window.close();
					return 0;
					break;
				default:
					break;
        	}
        }
        window.clear();
        game.endGame();
        window.draw(sprite_);
    	window.draw(text);
        game.render();
        window.display();
    }
    return 0;
}
