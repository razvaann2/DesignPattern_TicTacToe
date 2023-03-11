#include "DesignPattern_TicTacToe.h"
#include "Player.h"
#include "Game.h"
#include <qmessagebox.h>

DesignPattern_TicTacToe::DesignPattern_TicTacToe(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QPushButton* buttons[9];
    
    int width = this->width();
    int height = this->height();

    for (int i = 0; i < 9; ++i)
    {
        buttons[i] = new QPushButton(this);
        buttons[i]->setFixedSize(width / 3, height / 3);
        buttons[i]->raise();
    }

    
    buttons[0]->move(0, 0);
    buttons[1]->move(width / 3, 0);
    buttons[2]->move(2 * width / 3, 0);
    buttons[3]->move(0, height / 3);
    buttons[4]->move(width / 3, height / 3);
    buttons[5]->move(2 * width / 3, height / 3);
    buttons[6]->move(0, 2 * height / 3);
    buttons[7]->move(width / 3, 2 * height / 3);
    buttons[8]->move(2 * width / 3, 2 * height / 3);
    for (int i = 0; i < 9; ++i)
    {
        
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    }
    

}
void DesignPattern_TicTacToe::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setOpacity(0.5);
    
    int width = this->width();
    int height = this->height();
    
    painter.drawLine(0, height / 3, width, height / 3);
    painter.drawLine(0, 2 * height / 3, width, 2 * height / 3);

    
    painter.drawLine(width / 3, 0, width / 3, height);
    painter.drawLine(2 * width / 3, 0, 2 * width / 3, height);
    
}
void DesignPattern_TicTacToe::onButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());


    if (button) {
        
        QLabel* label = new QLabel(this);
        label->setFont(QFont("Arial", 150));
        label->setAlignment(Qt::AlignCenter);
        uint8_t x,y;
        if (button->pos().x()==0)
        {
            x = 0;
        }
        else if (button->pos().x() == width()/3)
        {
            x = 1;
        }
        else if (button->pos().x() == 2*width() / 3)
        {
            x = 2;
        }
        if (button->pos().y() == 0)
        {
            y = 0;
        }
        else if (button->pos().y() == height() / 3)
        {
            y = 1;
        }
        else if (button->pos().y() == 2 * height() / 3)
        {
            y = 2;
        }

        if (game.m_currentPlayer->GetSymbol() == 'X') {
            
            label->setText("X");
            game.m_board.AddSymbol('X', game.m_board, std::make_pair(x,y));
        }
        else if(game.m_currentPlayer->GetSymbol()=='O') {
           
            label->setText("O");
            game.m_board.AddSymbol('O', game.m_board, std::make_pair(x, y));

        }
        label->setFixedSize(button->size());
        label->move(button->pos() + QPoint(button->width() / 2 - label->width() / 2,
            button->height() / 2 - label->height() / 2));
        
        label->adjustSize();
        label->show();
      
        button->deleteLater();

        if (game.CheckGameStatus() == true)
        {
            QMessageBox::information(nullptr, "Game Result", "Player won");
            this->close();
        }
        game.ChangePlayer();
        if (game.m_board.GetAvailableCoordinates().empty())
        {
            QMessageBox::information(nullptr, "Game Result", "No more moves");
            this->close();
        }
    }
    
}

DesignPattern_TicTacToe::~DesignPattern_TicTacToe()
{}
