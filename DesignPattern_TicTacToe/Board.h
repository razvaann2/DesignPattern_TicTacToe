#pragma once
#include <vector>
class Board
{
private:
	 std::vector<std::pair<uint8_t, uint8_t>>m_AvailableCoordinates;
	 std::vector<std::vector<char>>m_Board;

public:
	Board();
	Board(Board& board);
	~Board();
	void SetBoard(std::vector<std::vector<char>>board);
	std::vector<std::vector<char>> GetBoard();
	void SetAvailableCoordinates(std::vector<std::pair<uint8_t, uint8_t>>availableCoordinates);
	std::vector<std::pair<uint8_t, uint8_t>> GetAvailableCoordinates();
	void AddSymbol(char character, Board& board,std::pair<uint8_t,uint8_t>coordinates);
	

};

