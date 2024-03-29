#include "Board.h"

Board::Board(): m_board(3, std::vector<char>(3))
{
		
	for (uint8_t i = 0; i < m_board.size(); i++)
	{
		for (uint8_t j = 0; j < m_board[i].size(); j++)
		{
			this->m_board[i][j] = ' ';
			this->m_availableCoordinates.push_back(std::make_pair(i, j));
		}
	}
}

Board::Board(Board& board)
{
	this->m_availableCoordinates = board.GetAvailableCoordinates();
	this->m_board = board.GetBoard();
}

Board::~Board()
{
	for (auto i : m_board)
		i.clear();
	m_board.clear();
	m_availableCoordinates.clear();
}

void Board::SetBoard(std::vector<std::vector<char>> board)
{
	this->m_board = board;
}

std::vector<std::vector<char>>& Board::GetBoard()
{
	return this->m_board;
}

bool Board::CheckCoordonates(std::pair<uint8_t, uint8_t> coords)
{
	for (auto i : m_availableCoordinates)
	{
		if (i == coords)
			return true;
	}
	return false;
}

void Board::SetAvailableCoordinates(std::vector<std::pair<uint8_t, uint8_t>> availableCoordinates)
{
	this->m_availableCoordinates = availableCoordinates;
}

std::vector<std::pair<uint8_t, uint8_t>>& Board::GetAvailableCoordinates() 
{
	return m_availableCoordinates;
}

void Board::AddSymbol(const char character, const std::pair<uint8_t,uint8_t>coordinates) 
{
	m_board[coordinates.first][coordinates.second] = character;
	m_availableCoordinates.erase(std::find(m_availableCoordinates.begin(), m_availableCoordinates.end(), coordinates));
}
