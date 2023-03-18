#include "TicTacToe_ui.h"
#include "Game.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TicTacToe_ui w;
    w.show();
    return a.exec();
}
