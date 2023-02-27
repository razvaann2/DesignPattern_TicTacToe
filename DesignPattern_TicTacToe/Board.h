#pragma once
#include <vector>
class Board
{
private:
	 std::vector<std::pair<uint8_t, uint8_t>>m_availableCoordinates;
	 std::vector<std::vector<char>>m_board;

public:
	Board();
	Board(Board& board);
	~Board();
	void SetBoard(std::vector<std::vector<char>>board);
	 const std::vector<std::vector<char>>& GetBoard() const;
	void SetAvailableCoordinates(std::vector<std::pair<uint8_t, uint8_t>>availableCoordinates);
	std::vector<std::pair<uint8_t, uint8_t>> GetAvailableCoordinates();
	void AddSymbol(char character, Board& board,std::pair<uint8_t,uint8_t>coordinates);
	

};

