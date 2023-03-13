#pragma once
#include <QPainter>
#include <QtWidgets/QMainWindow>
#include <qpushbutton.h>
#include "Game.h"
#include "ui_DesignPattern_TicTacToe.h"
#include <qlabel.h>
#include "Player.h"
#include "Game.h"
#include <qmessagebox.h>
#include <qtimer.h>
#include <vector>
#include <random>

class DesignPattern_TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    DesignPattern_TicTacToe(QWidget* parent = nullptr);
    ~DesignPattern_TicTacToe();
    Game game;
    std::vector<QPushButton*> buttons;
    void onButtonClicked(int buttonIndex);
    std::pair<uint8_t, uint8_t> Pickxy(QPushButton* button_aux);
    void DrawLabel(QPushButton* button_aux);


protected:
    void paintEvent(QPaintEvent* event) override;
    void paintWinner(int i);
private:
    Ui::DesignPattern_TicTacToeClass ui;
private slots:
    void onButtonClicked();
};
