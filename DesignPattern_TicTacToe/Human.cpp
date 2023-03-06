#include "Human.h"

Human::Human()
{
}

Human::Human(char Symbol, std::string Name)
{
	m_symbol = Symbol;
	m_name = Name;
}

Human::Human(Human& human)
{
	m_name = human.GetName();
	m_symbol = human.GetSymbol();
}

Human::~Human()
{
}

std::pair<uint8_t, uint8_t> Human::PickPosition(std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates)
{
	//cin o pereche, verific daca e in vector(valabilitate) si daca nu e recitesc.
	return std::pair<uint8_t, uint8_t>();
}

void Human::SetName(std::string Name)
{
	m_name = Name;
}

std::string Human::GetName()
{
	return m_name;
}

void Human::SetSymbol(char Symbol)
{
	m_symbol = Symbol;
}

char Human::GetSymbol()
{
	return m_symbol;
}
