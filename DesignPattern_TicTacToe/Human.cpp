#include "Human.h"
#include "Computer.h"
#include <iostream>

IPlayerPtr Player::Produce(EPlayerType type)
{
	if (type == EPlayerType::Human)
		return std::make_shared<Human>();
	if (type == EPlayerType::Computer)
		return std::make_shared<Computer>();
	return{};
}

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

std::pair<uint8_t, uint8_t> Human::PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates)
{
	while (true)
	{
		int number;
		std::cin >> number;
		number--;
		std::pair<uint8_t, uint8_t> position = std::make_pair(number / 3, number % 3);
		for (auto i : availableCoordinates)
		{
			if (i == position)
				return position;
		}
		std::cout << "Invalid position" << std::endl << std::endl;
	}
}
