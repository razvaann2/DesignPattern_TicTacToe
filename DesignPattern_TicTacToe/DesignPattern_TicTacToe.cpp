#include "DesignPattern_TicTacToe.h"
#include "Player.h"
#include "Game.h"
#include <qmessagebox.h>
#include <qtimer.h>

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
    if (game.CheckGameStatus() > -1)
    {
        paintWinner(game.CheckGameStatus());
    }
}
void DesignPattern_TicTacToe::paintWinner(int i)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setOpacity(0.5);
    switch (i)
    {
    case 3:
        painter.drawLine(0, height() / 6, width(), height() / 6); // first row
        update();
        break;
    case 4:
        painter.drawLine(0, height() / 2, width(), height() / 2); // second row
        update();
        break;
    case 5:
        painter.drawLine(0, height() * 5 / 6, width(), height() * 5 / 6); // third row
        update();
        break;
    case 0:
        painter.drawLine(width() / 6, 0, width() / 6, height()); // first column
        update();
        break;
    case 1:
        painter.drawLine(width() / 2, 0, width() / 2, height()); // second column
        update();
        break;
    case 2:
        painter.drawLine(width() * 5 / 6, 0, width() * 5 / 6, height()); // third column
        update();
        break;
    case 6:
        painter.drawLine(0, 0, width(), height()); // diagonal from top left to bottom right
        update();
        break;
    case 7:
        painter.drawLine(0, height(), width(), 0); // diagonal from bottom left to top right
        update();
        break;
    default:
        break;
    }
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
        update();
        if (game.CheckGameStatus() > -1)
        {
            paintWinner(game.CheckGameStatus());
            this->update(); 
           /* QTimer::singleShot(1000, this, [=]() {
                QMessageBox::information(nullptr, "Game Result", "Player won");
                this->close();
                });*/
        }
        game.ChangePlayer();
        if (game.m_board.GetAvailableCoordinates().empty())
        {
            QMessageBox::information(nullptr, "Game Result", "No more moves");
            this->close();
        }
        update();
    }
    update();
}


DesignPattern_TicTacToe::~DesignPattern_TicTacToe()
{}
