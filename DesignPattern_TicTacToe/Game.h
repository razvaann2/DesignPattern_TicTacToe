#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include "Computer.h"
#include <memory>
class Game
{
public:
	/*Player* m_currentPlayer= new Player();
	Player* m_player1 = new Human();
	Player* m_player2 = new Computer();*/
	std::shared_ptr<Player>m_currentPlayer;
	IPlayer m_player1;
	IPlayer m_player2;
	Board m_board;
public:
	Game();
	Game(Game& game);
	~Game();

	int CheckGameStatus();
	void ChangePlayer();

};

//#include "../DesignPattern_TicTacToe/Game.h" cale catre header ul respectiv

//sa nu contina cod redundant
//proiect de tip lib sau dll care sa contina logica jocului si 2 de ui care sa se lege la dll
//sa avem o interfata
//testarea in googlemok
//diagrama UML