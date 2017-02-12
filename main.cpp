#include <iostream>

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//Game classes
#include "include/Textbox.h"
#include "include/Npc.h"
#include "include/Player.h"
#include "include/Map.h"

int main()
{
	//Declares and creates a new window
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Game");

	//Defines what region is shown on screen
	sf::View view = window.getView();

	//Music
	sf::Music music;
	music.openFromFile("sound/ambientMu.ogg");
	music.play();

	//Text box instances
	Textbox box(view);

	//NPC instances
	Npc npcTest(128, 128, "images/test4.png");
	
	//Player instances
	Player chr(0, 0);

	//Background
	Map ground, background, collision;
	ground.setupBitmap("maps/testmap", window);
	collision.setupBitmap("maps/testcollision", window);
	background.setupStatic("images/background.jpg");

	//Sets framerate to 60fps
	window.setFramerateLimit(60);

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
				std::cout << "closing-event ";
				window.close();
			}
		}


		//Npc interaction
		npcTest.speak("That One Guy", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus sed velit semper, bibendum orci id, auctor tellus. Proin sollicitudin, urna et accumsan", box);

		//Character moves if npcs aren't speaking
		if(!npcTest.getSpeaking())
		{
			chr.movePos();
		}

		//Activates window for OpenGL rendering
		sf::Color winColor(107, 120, 140);
		window.clear(winColor);

		//Sets view
		view.setCenter(chr.getPosition());
		window.setView(view);

		//Sets position of box
		box.updatePosition(view);

		//Always on bottom
		background.drawStatic(window, view); 

		//Mid
		ground.drawBitmap(window);
		collision.drawCollision(window, chr);
		window.draw(chr.getSprite());

		//Npcs
		window.draw(npcTest.getSprite());
		npcTest.collision(chr);
		
		//Always on top
		box.drawAll(window);

		//End current frame and display its contents on screen
		window.display();
	}

	return 0;
}

