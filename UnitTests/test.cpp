#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
#include "Computer.h"
#include "Game.h"

TEST(PlayerTest, ProduceTest) {
    Player* player;
    auto human = player->Produce(EPlayerType::Human);
    auto computer = player->Produce(EPlayerType::Computer);
    EXPECT_NE(human, nullptr);
    EXPECT_NE(computer, nullptr);
}

TEST(GameTest, CheckGameStatusTest)
{
    Game newGame;
    newGame.ChangePlayer();
    newGame.m_board.AddSymbol(newGame.m_currentPlayer->GetSymbol(), std::make_pair<uint8_t, uint8_t>(0, 0));
    newGame.ChangePlayer();
    newGame.m_board.AddSymbol(newGame.m_currentPlayer->GetSymbol(), std::make_pair<uint8_t, uint8_t>(0, 2));
    newGame.ChangePlayer();
    newGame.m_board.AddSymbol(newGame.m_currentPlayer->GetSymbol(), std::make_pair<uint8_t, uint8_t>(1, 1));
    newGame.ChangePlayer();
    newGame.m_board.AddSymbol(newGame.m_currentPlayer->GetSymbol(), std::make_pair<uint8_t, uint8_t>(2, 1));
    newGame.ChangePlayer();
    newGame.m_board.AddSymbol(newGame.m_currentPlayer->GetSymbol(), std::make_pair<uint8_t, uint8_t>(2, 2));
    EXPECT_EQ(newGame.CheckGameStatus(), 6);
}

TEST(ComputerTest, PickPositionTest)
{
    std::vector<std::pair<uint8_t, uint8_t>> availableCoordinates = { {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2} };
    Computer computer;
    std::pair<uint8_t, uint8_t> position = computer.PickPosition(availableCoordinates);
    bool isPositionValid = false;
    for (const auto& coord : availableCoordinates)
    {
        if (coord == position)
        {
            isPositionValid = true;
            break;
        }
    }
    EXPECT_TRUE(isPositionValid);
}

TEST(HumanTest, PickPositionValid)
{
    std::istringstream input("5\n");
    std::cin.rdbuf(input.rdbuf());

    std::vector<std::pair<uint8_t, uint8_t>> availableCoordinates = { {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };
    Human human;
    std::pair<uint8_t, uint8_t> position = human.PickPosition(availableCoordinates);

    EXPECT_EQ(std::make_pair((uint8_t)1, (uint8_t)1), position);
}

TEST(GameTest, ChangePlayerTest) {
    Game game;
    ASSERT_EQ(game.m_currentPlayer, game.m_player1);
    game.ChangePlayer();
    ASSERT_EQ(game.m_currentPlayer, game.m_player2);
    game.ChangePlayer();
    ASSERT_EQ(game.m_currentPlayer, game.m_player1);
}

TEST(BoardTest, AddSymbolTest) {
    Board board;
    std::pair<uint8_t, uint8_t> position = std::make_pair(0, 0);
    board.AddSymbol('X', position);
    EXPECT_EQ(board.GetBoard()[position.first][position.second], 'X');
    EXPECT_NE(board.GetAvailableCoordinates()[0], position);
    std::pair<uint8_t, uint8_t> position2 = std::make_pair(2, 2);
    board.AddSymbol('O', position2);
    EXPECT_EQ(board.GetBoard()[position2.first][position2.second], 'O');
    EXPECT_NE(board.GetAvailableCoordinates()[6], position2);
}

TEST(GamePlayersTest, ChangePlayerTest) {
    std::shared_ptr<Player> player1 = std::make_shared<Human>('X');
    std::shared_ptr<Player> player2 = std::make_shared<Computer>('O');
    Game game;
    EXPECT_EQ(game.m_currentPlayer->GetSymbol(), player1->GetSymbol());
    game.ChangePlayer();
    EXPECT_EQ(game.m_currentPlayer->GetSymbol(), player2->GetSymbol());
    game.ChangePlayer();
    EXPECT_EQ(game.m_currentPlayer->GetSymbol(), player1->GetSymbol());
}