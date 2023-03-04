#pragma once
#include "Player.h"

class Human : public Player
{
public:
	Human();
	Human(char m_Symbol, std::string m_Name = " ");
	Human(Human& human);
	~Human();
	void SetName(std::string Name);
	std::string GetName();
	void SetSymbol(char Symbol);
	char GetSymbol();
};
