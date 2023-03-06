#pragma once
#include <string>
#include <vector>
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
	/*virtual void SetName(std::string Name) = 0;
	virtual std::string GetName() = 0;
	virtual void SetSymbol(char Symbol) = 0;
	virtual char GetSymbol() = 0;*/
	virtual std::pair<uint8_t, uint8_t> PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates)=0;
	//todo: clasa separata pentru fiecare tip de player
};
