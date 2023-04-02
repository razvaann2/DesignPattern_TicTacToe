#pragma once
#include "Player.h"

/// <summary>
/// The Computer class is used to make the actions for the Computer player.
/// </summary>
class Computer : public Player
{
public:
	Computer();
	Computer(char m_Symbol, std::string m_Name = " ");
	Computer(Computer& computer);
	~Computer();
	
	/// <summary>
	/// Picks a position for the Computer player.
	/// </summary>
	/// <param name="availableCoordinates">
	/// The empty positions on the table.
	/// </param>
	/// <returns>
	/// The coordonates of the picked position.
	/// </returns>
	std::pair<uint8_t, uint8_t> PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates);
};