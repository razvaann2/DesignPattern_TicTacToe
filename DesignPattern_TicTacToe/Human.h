#pragma once
#include "Player.h"

class Human : public Player
{
public:
	Human();
	Human(char m_Symbol, std::string m_Name = " ");
	Human(Human& human);
	~Human();
	
	
	std::pair<uint8_t, uint8_t> PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates);
};
