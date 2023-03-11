#include "Game.h"

Game::Game()
{
	m_currentPlayer = std::make_shared<Player>();
	m_player1 = std::make_shared<Human>('X');
	m_player2 = std::make_shared<Human>('O');
	m_currentPlayer = m_player1;
}

Game::Game(Game& game)
{
	//this->m_currentPlayer = game.m_currentPlayer;
}

Game::~Game()
{
}

bool Game::CheckGameStatus()
{
	for (uint8_t i = 0; i < m_board.GetBoard().size(); i++)
	{
		if (m_board.GetBoard()[i][0] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[i][1] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[i][2] == m_currentPlayer->GetSymbol())
			return true;
		if (m_board.GetBoard()[0][i] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[1][i] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[2][i] == m_currentPlayer->GetSymbol())
			return true;
	}

	if (m_board.GetBoard()[0][0] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[1][1] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[2][2] == m_currentPlayer->GetSymbol())
		return true;
	
	if (m_board.GetBoard()[2][0] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[1][1] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[0][2] == m_currentPlayer->GetSymbol())
		return true;

	return false;
}

void Game::ChangePlayer()
{
	if (m_currentPlayer == m_player1)
	{
		//m_currentPlayer.reset();
	m_currentPlayer = m_player2;
	}
	else
	{
		//m_currentPlayer.reset();
		m_currentPlayer = m_player1;
	}
}
