#include "Item.h"
#include "SpriteManager.h"
#include "StatBar.h"
#include "SkillCards.h"
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
		SpriteManager skillDispBackground;

		sf::Text name;
		sf::Text desc;

		sf::Text str;
		sf::Text def;
		sf::Text agi;

		StatBar hp;
		StatBar mana;

		//This button adds or removes party members (can only add up to 3)
		ClickButton partyButton;
		bool existInParty;
		int allyIndex;

		sf::Text skillItemText;
		std::vector<std::shared_ptr<ClickButton>> skillButton;
		std::vector<std::shared_ptr<ClickButton>> itemButton;

		//Selecting new skills
		bool displaySkills;
		int skillToChange;
		std::vector<std::shared_ptr<SkillCards>> skillCards;
		ClickButton prevPage;
		ClickButton nextPage;
		int curPage;
		int maxPage;

		//Selecting new items
		bool displayWeapons;
		bool displayArmor;
		bool displayOs;
		int itemToChange;
		std::vector<std::shared_ptr<SkillCards>> weaponCards;
		std::vector<std::shared_ptr<SkillCards>> armorCards;
		std::vector<std::shared_ptr<SkillCards>> osCards;
	public:
		CharacterCards();
		//Utility
		void setDisplay(bool);
		void setupText(sf::Text&, sf::Font&, int = 30);
		void updatePosition(std::vector<std::shared_ptr<Character>>, sf::View);

		//Setup
		void setupCard(Character, int, std::vector<int>, 
				std::vector<std::shared_ptr<Skill>>, std::vector<int>,
				std::vector<std::shared_ptr<Item>>, std::vector<int>);
		void checkForButton(std::vector<int>&, std::vector<std::shared_ptr<Character>>&, 
				int&, bool&, sf::RenderWindow&);
		void checkForSkill(sf::RenderWindow&);

		void drawAll(std::vector<std::shared_ptr<Character>>, sf::RenderWindow&);
};
#endif
