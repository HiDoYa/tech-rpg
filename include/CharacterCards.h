#include "SpriteManager.h"
#include "StatBar.h"
#include "Character.h"
#include "ClickButton.h"

#ifndef CHARACTERCARDS_H
#define CHARACTERCARDS_H
class CharacterCards
{
	private:
		sf::Font font;

		//Image is the character's image
		SpriteManager image;
		//Background is just character card background
		SpriteManager background;

		sf::Text name;
		sf::Text desc;

		sf::Text str;
		sf::Text def;
		sf::Text agi;

		StatBar hp;
		StatBar mana;

		//TODO This button adds or removes party members (can only add up to 3)
		ClickButton partyButton;
		bool existInParty;
		int allyIndex;

		//TODO finish skill buttons
		sf::Text skillText;
		std::vector<std::shared_ptr<ClickButton>> skillButton;
		bool skillLoad;
		int skillLoadNum;
	public:
		CharacterCards();
		//Utility
		void setupText(sf::Text&, sf::Font&, int = 30);
		void updatePosition(std::vector<std::shared_ptr<Character>>, sf::View);

		//Setup
		void setupCard(Character, int, std::vector<int>);
		void checkForButton(std::vector<int>&, int&, bool&, sf::RenderWindow&);
		void checkForSkill(sf::RenderWindow&);

		void drawAll(std::vector<std::shared_ptr<Character>>, sf::RenderWindow&);
};
#endif
