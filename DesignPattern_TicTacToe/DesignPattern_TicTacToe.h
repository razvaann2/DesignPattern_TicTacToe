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
   // QLabel x_label;
    //QLabel O_label;

protected:
    void paintEvent(QPaintEvent* event) override;
private:
    Ui::DesignPattern_TicTacToeClass ui;
private slots:
    void onButtonClicked();
};
