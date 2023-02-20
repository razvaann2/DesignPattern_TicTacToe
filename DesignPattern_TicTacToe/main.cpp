#include "DesignPattern_TicTacToe.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesignPattern_TicTacToe w;
    w.show();
    return a.exec();
}
