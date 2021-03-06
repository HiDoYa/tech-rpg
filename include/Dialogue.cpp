#include <SFML/Graphics.hpp>
#include <iostream>

#include "Dialogue.h"

//Flag 0 is always false and flag 1 is always true

Dialogue::Dialogue()
{
}

//****** PUSH ********

void Dialogue::pushNextText()
{
	std::vector<int> newIntVec;
	std::vector<bool> newBoolVec;

	text.push_back("");
	condition.push_back(newIntVec);
	conditionCheck.push_back(newBoolVec);
	chgNum.push_back(newIntVec);
	chgCheck.push_back(newBoolVec);

	giveType.push_back(newIntVec);
	giveId.push_back(newIntVec);

	//Choice
	choiceFlag.push_back(false);
	choiceDisp.push_back("");
	choiceOne.push_back("");
	choiceTwo.push_back("");
	choiceOneDisp.push_back("");
	choiceTwoDisp.push_back("");
	chgOneNum.push_back(newIntVec);
	chgTwoNum.push_back(newIntVec);
	chgOneBool.push_back(newBoolVec);
	chgTwoBool.push_back(newBoolVec);

	giveOneType.push_back(newIntVec);
	giveTwoType.push_back(newIntVec);
	giveOneId.push_back(newIntVec);
	giveTwoId.push_back(newIntVec);
}

void Dialogue::pushText(std::string textInp)
{
	text[text.size() - 1] = textInp;
}

void Dialogue::pushCondition(int condInp)
{
	condition[condition.size() - 1].push_back(condInp);
}

void Dialogue::pushConditionCheck(bool condCheckInp)
{
	conditionCheck[conditionCheck.size() - 1].push_back(condCheckInp);
}

void Dialogue::pushChgNum(int chgNumInp)
{
	chgNum[chgNum.size() - 1].push_back(chgNumInp);
}

void Dialogue::pushChgCheck(bool chgChkInp)
{
	chgCheck[chgCheck.size() - 1].push_back(chgChkInp);
}

void Dialogue::pushGiveType(int intInp)
{
	giveType[giveType.size() - 1].push_back(intInp);
}

void Dialogue::pushGiveId(int intInp)
{
	giveId[giveId.size() - 1].push_back(intInp);
}

//************* CHOICE SPECIFIC **********
void Dialogue::curChoiceTrue()
{
	choiceFlag[choiceFlag.size() - 1] = true;
}

void Dialogue::pushChoice(std::string strInp)
{
	choiceDisp[choiceDisp.size() - 1] = strInp;
}

void Dialogue::pushChoiceOne(std::string strInp)
{
	choiceOne[choiceOne.size() - 1] = strInp;
}

void Dialogue::pushChoiceTwo(std::string strInp)
{
	choiceTwo[choiceTwo.size() - 1] = strInp;
}

void Dialogue::pushChoiceOneDisp(std::string strInp)
{
	choiceOneDisp[choiceOneDisp.size() - 1] = strInp;
}

void Dialogue::pushChoiceTwoDisp(std::string strInp)
{
	choiceTwoDisp[choiceTwoDisp.size() - 1] = strInp;
}

void Dialogue::pushChgOneNum(int intInp)
{
	chgOneNum[chgOneNum.size() - 1].push_back(intInp);
}

void Dialogue::pushChgTwoNum(int intInp)
{
	chgTwoNum[chgTwoNum.size() - 1].push_back(intInp);
}

void Dialogue::pushChgOneBool(bool boolInp)
{
	chgOneBool[chgOneBool.size() - 1].push_back(boolInp);
}

void Dialogue::pushChgTwoBool(bool boolInp)
{
	chgTwoBool[chgTwoBool.size() - 1].push_back(boolInp);
}

void Dialogue::pushGiveOneType(int intInp)
{
	giveOneType[giveOneType.size() - 1].push_back(intInp);
}

void Dialogue::pushGiveTwoType(int intInp)
{
	giveTwoType[giveTwoType.size() - 1].push_back(intInp);
}

void Dialogue::pushGiveOneId(int intInp)
{
	giveOneId[giveOneId.size() - 1].push_back(intInp);
}

void Dialogue::pushGiveTwoId(int intInp)
{
	giveTwoId[giveTwoId.size() - 1].push_back(intInp);
}

//******** ACCESSORS **********
std::vector<std::string> Dialogue::getText()
{
	return text;
}

std::vector<std::vector<int>> Dialogue::getCondition()
{
	return condition;
}

std::vector<std::vector<bool>> Dialogue::getConditionCheck()
{
	return conditionCheck;
}

std::vector<std::vector<int>> Dialogue::getChgNum()
{
	return chgNum;
}

std::vector<std::vector<bool>> Dialogue::getChgCheck()
{
	return chgCheck;
}

std::vector<std::vector<int>> Dialogue::getGiveType()
{
	return giveType;
}

std::vector<std::vector<int>> Dialogue::getGiveId()
{
	return giveId;
}

std::vector<bool> Dialogue::getChoiceFlag()
{
	return choiceFlag;
}

std::vector<std::string> Dialogue::getChoiceDisp()
{
	return choiceDisp;
}

std::vector<std::string> Dialogue::getChoiceOne()
{
	return choiceOne;
}

std::vector<std::string> Dialogue::getChoiceTwo()
{
	return choiceTwo;
}

std::vector<std::string> Dialogue::getChoiceOneDisp()
{
	return choiceOneDisp;
}

std::vector<std::string> Dialogue::getChoiceTwoDisp()
{
	return choiceTwoDisp;
}

std::vector<std::vector<int>> Dialogue::getChgOneNum()
{
	return chgOneNum;
}

std::vector<std::vector<int>> Dialogue::getChgTwoNum()
{
	return chgTwoNum;
}

std::vector<std::vector<bool>> Dialogue::getChgOneBool()
{
	return chgOneBool;
}

std::vector<std::vector<bool>> Dialogue::getChgTwoBool()
{
	return chgTwoBool;
}

std::vector<std::vector<int>> Dialogue::getGiveOneType()
{
	return giveOneType;
}

std::vector<std::vector<int>> Dialogue::getGiveTwoType()
{
	return giveTwoType;
}

std::vector<std::vector<int>> Dialogue::getGiveOneId()
{
	return giveOneId;
}

std::vector<std::vector<int>> Dialogue::getGiveTwoId()
{
	return giveTwoId;
}

