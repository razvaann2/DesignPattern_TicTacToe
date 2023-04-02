#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include "Computer.h"
#include <memory>
#include "IGame.h"

/// <summary>
/// The Game class is used to store the board and the players of a game and make the game actions.
/// </summary>
class Game : public IGame
{
public:
	/// <summary>
	/// m_currentPlayer store the player whose turn is now.
	/// </summary>
	IPlayerPtr m_currentPlayer;
	/// <summary>
	/// m_player1 store the first player of the game.
	/// </summary>
	IPlayerPtr m_player1;
	/// <summary>
	/// m_player1 store the second player of the game.
	/// </summary>
	IPlayerPtr m_player2;
	/// <summary>
	/// m_board store the current content of the board.
	/// </summary>
	Board m_board;
	//std::vector<IGameListenerPtr> m_listeners;
public:
	Game();
	Game(Game& game);
	~Game();
	/// <summary>
	/// Checks if the game is over and returns the mode in wich it ended.
	/// </summary>
	/// <returns>
	/// The mode in wich the game ended.
	/// </returns>
	EWinType CheckGameStatus() override;
	/// <summary>
	/// Change the current player after a move is made.
	/// </summary>
	void ChangePlayer() override;
};