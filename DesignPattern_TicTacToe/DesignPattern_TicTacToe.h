#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DesignPattern_TicTacToe.h"

class DesignPattern_TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    DesignPattern_TicTacToe(QWidget *parent = nullptr);
    ~DesignPattern_TicTacToe();

private:
    Ui::DesignPattern_TicTacToeClass ui;
};
