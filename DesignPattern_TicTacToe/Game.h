#pragma once
#include "Player.h"
#include "Board.h"
class Game
{
private:
	Player m_currentPlayer;
	Player m_player1;
	Player m_player2;
	Board m_board;
public:
	Game();
	~Game();
	bool CheckGameStatus();
	void ChangePlayer();

};

