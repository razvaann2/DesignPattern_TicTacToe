#include "Computer.h"
#include <cstdlib>
#include <ctime>

Computer::Computer()
{
}

Computer::Computer(char Symbol, std::string Name)
	:Player(Symbol,Name)
{
}

Computer::Computer(Computer& computer)
{
	m_name = computer.GetName();
	m_symbol = computer.GetSymbol();
}

Computer::~Computer()
{
}



std::pair<uint8_t, uint8_t> Computer::PickPosition(std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates)
{
	std::pair<uint8_t, uint8_t> position;
	std::srand(std::time(nullptr));
	int poz = std::rand() % availableCoordinates.size();
	position = availableCoordinates[poz];
	availableCoordinates.erase(availableCoordinates.begin() + poz);
	return position;
}
