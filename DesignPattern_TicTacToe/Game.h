#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include "Computer.h"
class Game
{
private:
	Player* m_currentPlayer;
	Human* m_player1;
	Computer* m_player2;
	Board m_board;
public:
	Game();
	Game(Game& game);
	~Game();

	bool CheckGameStatus();
	void ChangePlayer();

};

//#include "../DesignPattern_TicTacToe/Game.h" cale catre header ul respectiv