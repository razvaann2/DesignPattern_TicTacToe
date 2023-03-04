#include "Computer.h"
#include <cstdlib>
#include <ctime>

Computer::Computer()
{
}

Computer::Computer(char Symbol, std::string Name)
{
	m_Symbol = Symbol;
	m_Name = Name;
}

Computer::Computer(Computer& computer)
{
	m_Name = computer.GetName();
	m_Symbol = computer.GetSymbol();
}

Computer::~Computer()
{
}

void Computer::SetName(std::string Name)
{
}

std::string Computer::GetName()
{
	return std::string();
}

void Computer::SetSymbol(char Symbol)
{
}

char Computer::GetSymbol()
{
	return 0;
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
