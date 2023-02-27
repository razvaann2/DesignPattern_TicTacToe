#pragma once
#include <string>
class Player
{

private:
	std::string m_Name;
	char m_Symbol;

public:
	Player(char m_Symbol,std::string m_Name=" ");
	Player(Player& player);
	Player();
	~Player();
	void SetName(std::string Name);
	std::string GetName();
	void SetSymbol(char Symbol);
	char GetSymbol();
	bool operator==(const Player& player1);
	
	//todo: clasa separata pentru fiecare tip de player
};
