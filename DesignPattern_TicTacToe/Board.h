#pragma once
#include <vector>

/// <summary>
/// The board class is used to store the content of the board and modify it.
/// </summary>
class Board
{
private:
	 /// <summary>
	 /// m_availebleCoordinates store the empty positions on the board.
	 /// </summary>
	 std::vector<std::pair<uint8_t, uint8_t>>m_availableCoordinates;
	 /// <summary>
	 /// m_board store the current content of the board.
	 /// </summary>
	 std::vector<std::vector<char>>m_board;

public:
	Board();
	Board(Board& board);
	~Board();
	void SetBoard(std::vector<std::vector<char>>board);
	std::vector<std::vector<char>>& GetBoard();
	/// <summary>
	/// Check if the input coordonate is valid and it's position on the board is empty.
	/// </summary>
	/// <param name="coords">
	/// The position that will be checked.
	/// </param>
	/// <returns>
	/// A boolean value depending of the availability of the input coordonate.
	/// </returns>
	bool CheckCoordonates(std::pair<uint8_t, uint8_t> coords);
	void SetAvailableCoordinates(std::vector<std::pair<uint8_t, uint8_t>>availableCoordinates);
	std::vector<std::pair<uint8_t, uint8_t>>& GetAvailableCoordinates();
	/// <summary>
	/// Adds X or O to the board after a move is made.
	/// </summary>
	/// <param name="character">
	/// A character witch is X or O.
	/// </param>
	/// <param name="coordinates">
	/// The position where the character will be placed.
	/// </param>
	void AddSymbol(const char character, const std::pair<uint8_t,uint8_t>coordinates);
};

