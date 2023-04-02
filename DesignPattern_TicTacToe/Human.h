#pragma once
#include "Player.h"

/// <summary>
/// The Human class is used to make the actions for the Human player.
/// </summary>
class Human : public Player
{
public:
	Human();
	Human(char m_Symbol, std::string m_Name = " ");
	Human(Human& human);
	~Human();
	
	/// <summary>
	/// Picks a position for the Human player.
	/// </summary>
	/// <param name="availableCoordinates">
	/// The empty positions on the table.
	/// </param>
	/// <returns>
	/// The coordonates of the picked position.
	/// </returns>
	std::pair<uint8_t, uint8_t> PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates);
};
