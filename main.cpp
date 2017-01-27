#include <cmath>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//Game classes
#include "include/Npc.h"
#include "include/Player.h"
#include "include/Textbox.h"

//testing

int main()
{
	//Declares and creates a new window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

	//Instance Tests 
	Textbox box(window);
	box.closeBox();
	Npc kitty(20, 20, "images/hello.jpeg");
	kitty.setScale(0.3);
	Player chr(300, 250, "images/penguin.png");
	chr.setScale(0.07);

	//Time
	sf::Clock clock;
	sf::Time time;

	//Sets framerate to 30fps
	window.setFramerateLimit(30);

	//Main loop - ends when window is closed
	while(window.isOpen())
	{
		//Event Processing
		sf::Event event;
		while (window.pollEvent(event))
		{
			//Request for closing the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		time = clock.getElapsedTime();
		time.asSeconds();

		//Setting the text
		box.openBox();
		if(box.getOpen())
		{
			box.animateText("This is a test, abc one two three.");
		}
		//box.animateText("hello, this is a test for the text box. asdf asdf filler filler.");

		chr.movePos(10);

		//Activates window for OpenGL rendering
		window.clear(sf::Color::Blue);

		//window.draw();
		window.draw(kitty.getSprite());
		window.draw(chr.getSprite());
		box.drawAll(window);

		//End current frame and display its contents on screen
		window.display();
	}

	return 0;
}
