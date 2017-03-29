
#ifndef DIALOGUE_H
#define DIALOGUE_H

class Dialogue
{
	private:
		//!!!! NOTE !!!!! check for condition FIRST and then checks for choiceCheck
		//Text checks sequentially; Most latest text for npc must come FIRST
		
		//**** TRAD TEXT *****
		//Stores all texts
		std::vector<std::string> text;
		//Stores all the conditions (flag number)
		std::vector<int> condition;
		//Stores whether the condition is looking for a true or false
		std::vector<bool> conditionNeg;
		//Stores whether to change state after displaying the text, and whether it will be a true or a false
		std::vector<int> chgCheck;
		//Stores what number to change
		std::vector<int> chgNum;
		

		//TODO Work under progress VVVVVV
		//******* CHOICES TEXT *******
		//Stores whether the next text will be a choice box
		std::vector<bool> choiceCheck;
		std::vector<std::string> choiceOne;
		std::vector<std::string> choiceTwo;
		//Stores whether to change state after choice
		std::vector<bool> chgChoice;
		//Stores which state to change after choice
		std::vector<int> chgOneNum;
		std::vector<int> chgTwoNum;
		//Stores whether the condition is going to change to a true or false
		std::vector<bool> chgOneNeg;
		std::vector<bool> chgTwoNeg;

	public:
		Dialogue();
		void newText();
};

#endif
