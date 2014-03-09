#include <SFML/Graphics.hpp>
#include"HeroShip.h"

int main()
{
    // Create the main window to display 
    sf::RenderWindow *window;
    window=new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
    window->setFramerateLimit(20);
    //Create the ship
    HeroShip *myship=new HeroShip();
    //Open the game loop
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();
        }
 	
       //Get input from user
       myship->handleEvents();
       //Update ship’s values
       myship->update();
	 
       // Clear screen
       window->clear();
       //display stuff
       myship->display(window);
       //finally display the window on screen
       window->display();
    }
    return 0;
}

