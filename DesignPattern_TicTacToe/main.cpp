#include <iostream>
#include "DesignPattern_TicTacToe.h"
#include <QtWidgets/QApplication>

void DisplayBoard(Game& game, bool helper)
{
	std::cout << std::endl;
	for (int i = 0; i < game.m_board.GetBoard().size(); i++)
	{
		std::cout << " ";
		for (int j = 0; j < game.m_board.GetBoard()[i].size(); j++)
		{
			if (helper)
				std::cout << game.m_board.GetBoard()[i][j];
			else
				std::cout << i * game.m_board.GetBoard().size() + j + 1;
			if (j < game.m_board.GetBoard()[i].size() - 1)
				std::cout << " | ";
		}
		std::cout << std::endl;
		if (i < game.m_board.GetBoard().size() - 1)
		{
			for (int k = 0; k < game.m_board.GetBoard().size(); k++)
				if (k < game.m_board.GetBoard().size() - 1)
					std::cout << "----";
				else
					std::cout << "---";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void ConsoleGame()
{
	Game consoleGame;
	DisplayBoard(consoleGame, false);
	consoleGame.ChangePlayer();
	while (!consoleGame.m_board.GetAvailableCoordinates().empty() && consoleGame.CheckGameStatus() == -1)
	{
		consoleGame.ChangePlayer();
		std::pair<uint8_t, uint8_t> coordonates = consoleGame.m_currentPlayer->PickPosition(consoleGame.m_board.GetAvailableCoordinates());
		consoleGame.m_board.AddSymbol(consoleGame.m_currentPlayer->GetSymbol(), coordonates);
		DisplayBoard(consoleGame, true);
		DisplayBoard(consoleGame, false);
	}
	std::cout << "Game Finished\n";
	if (consoleGame.m_board.GetAvailableCoordinates().empty())
	{
		std::cout << "Draw";
	}
	else
	{
		std::cout << "The winner is " << consoleGame.m_currentPlayer->GetSymbol() << std::endl;
	}
}

int main(int argc, char *argv[])
{
    std::cout << "Click 1 for console version and 2 for Qt version\n";
    int gameType;
    do 
    {
        std::cin >> gameType;
        if (gameType != 1 && gameType != 2)
            std::cout << "Select a valid option\n";
    } while (gameType != 1 && gameType != 2);
    if (gameType == 2)
    {
		std::cout << "Qt version selected\n";
        QApplication a(argc, argv);
        DesignPattern_TicTacToe w;
        w.show();
        return a.exec();
    }
	std::cout << "Console version selected\n";
	ConsoleGame();
    return 0;
}
