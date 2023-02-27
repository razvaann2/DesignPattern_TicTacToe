#pragma once
#include "Player.h"
#include "Board.h"
class Game
{
private:
	Player CurrentPlayer;
	Player Player1;
	Player Player2;
	Board board;
public:
	Game();
	~Game();


};

