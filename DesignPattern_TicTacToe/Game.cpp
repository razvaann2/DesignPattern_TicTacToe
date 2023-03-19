#include "Game.h"

IGamePtr IGame::Produce()
{
	return std::make_shared<Game>();
}

Game::Game()
{
	//m_player1 = std::make_shared<Human>();
	m_player1->Produce(EPlayerType::Human);
	m_player1->SetSymbol('X');
	//m_player2 = std::make_shared<Computer>();
	//m_player2->Produce(EPlayerType::Human);
	m_player2->Produce(EPlayerType::Computer);
	m_player2->SetSymbol('O');
	m_currentPlayer = m_player1;
}

Game::Game(Game& game)
{
	//this->m_currentPlayer = game.m_currentPlayer;
}

Game::~Game()
{
}

int Game::CheckGameStatus()
{
	for (uint8_t i = 0; i < m_board.GetBoard().size(); i++)
	{
		if (m_board.GetBoard()[i][0] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[i][1] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[i][2] == m_currentPlayer->GetSymbol())
			return i;
		if (m_board.GetBoard()[0][i] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[1][i] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[2][i] == m_currentPlayer->GetSymbol())
			return 3+i;
	}

	if (m_board.GetBoard()[0][0] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[1][1] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[2][2] == m_currentPlayer->GetSymbol())
		return 6;
	
	if (m_board.GetBoard()[2][0] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[1][1] == m_currentPlayer->GetSymbol() && m_board.GetBoard()[0][2] == m_currentPlayer->GetSymbol())
		return 7;

	return -1;
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

//void Game::AddListener(IGameListenerPtr listener)
//{
//	m_listeners.push_back(listener);
//}
//
//void Game::RemoveListener(IGameListenerPtr listener)
//{
//	auto it = std::find(m_listeners.begin(), m_listeners.end(), listener);
//	if (it != m_listeners.end()) {
//		m_listeners.erase(it);
//	}
//}
//
//void Game::NotifyMoveMade()
//{
//	for (auto listener : m_listeners) {
//		listener->OnMoveMade();
//	}
//}
//
//void Game::NotifyGameOver()
//{
//	for (auto listener : m_listeners) {
//		listener->OnGameOver();
//	}
//}