#pragma once
#include "Player.h"
#include "Board.h"
#include "Human.h"
#include "Computer.h"
#include <memory>
#include "IGame.h"

class Game : public IGame
{
public:
	IPlayerPtr m_currentPlayer;
	IPlayerPtr m_player1;
	IPlayerPtr m_player2;
	Board m_board;
	//std::vector<IGameListenerPtr> m_listeners;
public:
	Game();
	Game(Game& game);
	~Game();
	int CheckGameStatus() override;
	void ChangePlayer() override;
	/*void AddListener(IGameListenerPtr listener) override;
	void RemoveListener(IGameListenerPtr listener) override;
	void NotifyMoveMade();
	void NotifyGameOver();*/

};

//#include "../DesignPattern_TicTacToe/Game.h" cale catre header ul respectiv

//sa nu contina cod redundant
//proiect de tip lib sau dll care sa contina logica jocului si 2 de ui care sa se lege la dll
//sa avem o interfata
//testarea in googlemok
//diagrama UML