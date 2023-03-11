#include "Human.h"
#include "Computer.h"


//IPlayer Player::Produce(EPlayerType type)
//{
//	if (type == EPlayerType::Human)
//		return std::make_shared<Human>();
//	if (type == EPlayerType::Computer)
//		return std::make_shared<Computer>();
//	return{};
//}
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


