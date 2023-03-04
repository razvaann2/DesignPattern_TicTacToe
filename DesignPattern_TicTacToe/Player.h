#pragma once
#include <string>
class Player
{

protected:
	std::string m_Name;
	char m_Symbol;

public:
	Player(char m_Symbol,std::string m_Name=" ");
	Player(Player& player);
	Player();
	~Player();
	virtual void SetName(std::string Name) = 0;
	virtual std::string GetName() = 0;
	virtual void SetSymbol(char Symbol) = 0;
	virtual char GetSymbol() = 0;
	
	//todo: clasa separata pentru fiecare tip de player
};
