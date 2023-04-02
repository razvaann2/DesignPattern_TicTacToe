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

/// <summary>
/// The Player class is used to store the name of the player and it's symbol(X or O).
/// </summary>
class Player
{

protected:
	/// <summary>
	/// m_name store the name of the player.
	/// </summary>
	std::string m_name;
	/// <summary>
	/// m_symbol store the symbol of the player(X or O).
	/// </summary>
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
	/// <summary>
	/// Creates a pointer of the class type Human or Computer.
	/// </summary>
	/// <param name="type">
	/// The type of the player.
	/// </param>
	/// <returns>
	/// A pointer of the class type Human or Computer.
	/// </returns>
	static IPlayerPtr Produce(EPlayerType type);
	/// <summary>
	/// PickPosition is a pure virtual method that picks a position and it will change depending if the player is a human or a computer.
	/// </summary>
	/// <param name="availableCoordinates">
	/// The empty positions on the table.
	/// </param>
	/// <returns>
	/// The coordonates of the picked position.
	/// </returns>
	virtual std::pair<uint8_t, uint8_t> PickPosition(const std::vector<std::pair<uint8_t, uint8_t>>& availableCoordinates) = 0;
	
};
