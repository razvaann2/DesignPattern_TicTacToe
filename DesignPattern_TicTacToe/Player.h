#pragma once
#include <string>
#include <vector>
#include <utility>
#include <memory>

enum class EPlayerType
{
	Human,
	Computer
};

using IPlayerPtr = std::shared_ptr<class Player>;

class Player
{

protected:
	std::string m_name;
	char m_symbol;

public:
	Player(char m_Symbol,std::string m_Name=" ");
	Player(Player& player);
	Player();
	~Player();

	void SetName(std::string Name);
	std::string GetName();
	void SetSymbol(char Symbol);
	char GetSymbol();
	static IPlayerPtr Produce(EPlayerType type);
	virtual std::pair<uint8_t, uint8_t> PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates) = 0;
	
};
