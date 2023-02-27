#include "Board.h"

Board::Board()
{
	for (uint8_t i = 0; i < m_Board.size(); i++)
	{
		for (uint8_t j = 0; j < m_Board[i].size(); j++)
		{
			this->m_Board[i][j] = ' ';
			this->m_AvailableCoordinates.push_back(std::make_pair(i, j));
		}
	}
}

Board::Board(Board& board)
{
	this->m_AvailableCoordinates = board.GetAvailableCoordinates();
	this->m_Board = board.GetBoard();
}

Board::~Board()
{
}

void Board::SetBoard(std::vector<std::vector<char>> board)
{
	this->m_Board = board;
}

std::vector<std::vector<char>> Board::GetBoard()
{
	return this->m_Board;
}

void Board::SetAvailableCoordinates(std::vector<std::pair<uint8_t, uint8_t>> availableCoordinates)
{
	this->m_AvailableCoordinates = availableCoordinates;
}

std::vector<std::pair<uint8_t, uint8_t>> Board::GetAvailableCoordinates()
{
	return this->m_AvailableCoordinates;
}

void Board::AddSymbol(char character, Board& board,std::pair<uint8_t,uint8_t>coordinates)
{
	board.GetBoard()[coordinates.first][coordinates.second] = character;
	board.GetAvailableCoordinates().erase(std::find(board.GetAvailableCoordinates().begin(), board.GetAvailableCoordinates().end(), coordinates));
}
