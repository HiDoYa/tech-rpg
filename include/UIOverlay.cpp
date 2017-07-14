#include <SFML/Graphics.hpp>
#include <iostream>

#include "UIOverlay.h"

UIOverlay::UIOverlay()
{
	//TODO Mainwrapper
	mainWrapperTexture.loadFromFile("images/ui/mapUi.png");
	mainWrapperSprite.setTexture(mainWrapperTexture);

	//Font
	font.loadFromFile("font/Ubuntu.ttf");
	currencyText.setCharacterSize(15);

	//Currency Text
	currencyText.setFont(font);
	
	//level Text
	levelText.setFont(font);
	levelText.setColor(sf::Color::Black);
	levelText.setCharacterSize(25);

	//Button
	charButton.getRect()->setSize(sf::Vector2f(200, 50));
	charButton.getText()->setString("Characters");
	charButton.getText()->setCharacterSize(15);

	skillButton.getRect()->setSize(sf::Vector2f(200, 50));
	skillButton.getText()->setString("Skills");
	skillButton.getText()->setCharacterSize(15);

	battlePosButton.getRect()->setSize(sf::Vector2f(200, 50));
	battlePosButton.getText()->setString("Battle");
	battlePosButton.getText()->setCharacterSize(15);

	menuSelected = sf::Color::Red;
	menuDeselected = sf::Color::Black;
}

//********** MUTATORS ************** 

void UIOverlay::setPosition(sf::View view)
{
	int x = view.getCenter().x - (view.getSize().x / 2);
	int y = view.getCenter().y - (view.getSize().y / 2);
	mainWrapperSprite.setPosition(x, y);

	currencyText.setPosition(sf::Vector2f(x + 900, y + 30));

	levelText.setPosition(sf::Vector2f(x + 33, y + 40));

	charButton.updatePositionMap(25, 700, view);
	skillButton.updatePositionMap(275, 700, view);
	battlePosButton.updatePositionMap(525, 700, view);
}

void UIOverlay::setCurrency(int cur)
{
	currencyText.setString("Gold: " + std::to_string(cur));
}

void UIOverlay::setLevel(int lvl)
{
	levelText.setString(std::to_string(lvl));
}

//********* ETC ***********

bool UIOverlay::checkForMapMenu(int& menuOption, sf::RenderWindow& win)
{
	bool charBool = charButton.mouseClickedInButton(menuSelected, menuDeselected, win);
	bool skillBool = skillButton.mouseClickedInButton(menuSelected, menuDeselected, win);
	bool battlePosBool = battlePosButton.mouseClickedInButton(menuSelected, menuDeselected, win);
	if(charBool)
	{
		menuOption = 0;
		return true;
	}
	else if(skillBool)
	{
		menuOption = 1;
		return true;
	}
	else if(battlePosBool)
	{
		menuOption = 2;
		return true;
	}
	return false;
}

void UIOverlay::drawAll(sf::RenderWindow& win)
{
	win.draw(mainWrapperSprite);

	win.draw(levelText);

	win.draw(currencyText);

	charButton.drawAll(win);
	skillButton.drawAll(win);
	battlePosButton.drawAll(win);
}
