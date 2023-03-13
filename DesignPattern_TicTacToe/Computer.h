#pragma once
#include "Player.h"

class Computer : public Player
{
public:
	Computer();
	Computer(char m_Symbol, std::string m_Name = " ");
	Computer(Computer& computer);
	~Computer();
	
	std::pair<uint8_t, uint8_t> PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates);
};