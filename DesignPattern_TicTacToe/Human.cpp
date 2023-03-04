#include "Human.h"

Human::Human()
{
}

Human::Human(char Symbol, std::string Name)
{
	m_Symbol = Symbol;
	m_Name = Name;
}

Human::Human(Human& human)
{
	m_Name = human.GetName();
	m_Symbol = human.GetSymbol();
}

Human::~Human()
{
}

void Human::SetName(std::string Name)
{
	m_Name = Name;
}

std::string Human::GetName()
{
	return m_Name;
}

void Human::SetSymbol(char Symbol)
{
	m_Symbol = Symbol;
}

char Human::GetSymbol()
{
	return m_Symbol;
}
