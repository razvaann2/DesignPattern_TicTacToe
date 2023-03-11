#pragma once
#include <QPainter>
#include <QtWidgets/QMainWindow>
#include <qpushbutton.h>
#include "Game.h"
#include "ui_DesignPattern_TicTacToe.h"
#include <qlabel.h>

class DesignPattern_TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    DesignPattern_TicTacToe(QWidget *parent = nullptr);
    ~DesignPattern_TicTacToe();
    Game game;
 

protected:
    void paintEvent(QPaintEvent* event) override;
    void paintWinner(int i);
private:
    Ui::DesignPattern_TicTacToeClass ui;
private slots:
    void onButtonClicked();
};
