#include "TicTacToeUI.h"


TicTacToeUI::TicTacToeUI(QWidget* parent)
    : QMainWindow(parent)
{
    srand(time(0));
    ui.setupUi(this);


    int width = this->width();
    int height = this->height();

    for (int i = 0; i < 9; ++i)
    {

        QPushButton* button = new QPushButton(this);
        buttons.push_back(button);
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

void TicTacToeUI::paintEvent(QPaintEvent* event)
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
    else
    {
        if (game.m_board.GetAvailableCoordinates().size() != 0)
        {
            if (auto computerPlayer = dynamic_cast<Computer*>(game.m_currentPlayer.get())) {


                int randomIndex = rand() % buttons.size();
                QPushButton* button = buttons[randomIndex];
                DrawLabel(button);

                update();
                buttons.erase(std::remove(buttons.begin(), buttons.end(), button), buttons.end());
                update();
                if (game.m_board.GetAvailableCoordinates().empty())
                {
                    QMessageBox::information(nullptr, "Game Result", "No more moves");
                    this->close();
                }


                if (game.CheckGameStatus() > -1)
                {
                    paintWinner(game.CheckGameStatus());
                    this->update();
                    QTimer::singleShot(1000, this, [=]() {
                        QMessageBox::information(nullptr, "Game Result", "Computer won");
                        this->close();
                        });
                }
                else {
                    game.ChangePlayer();
                }
                update();
            }
        }
    }
}
void TicTacToeUI::paintWinner(int i)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setOpacity(0.5);
    switch (i)
    {
    case 3:
        painter.drawLine(0, height() / 6, width(), height() / 6); // 1 linie
        update();
        break;
    case 4:
        painter.drawLine(0, height() / 2, width(), height() / 2); // 2 linie
        update();
        break;
    case 5:
        painter.drawLine(0, height() * 5 / 6, width(), height() * 5 / 6); // 3 linie
        update();
        break;
    case 0:
        painter.drawLine(width() / 6, 0, width() / 6, height()); // 1 coloana
        update();
        break;
    case 1:
        painter.drawLine(width() / 2, 0, width() / 2, height()); // 2 coloana
        update();
        break;
    case 2:
        painter.drawLine(width() * 5 / 6, 0, width() * 5 / 6, height()); // 3 coloana
        update();
        break;
    case 6:
        painter.drawLine(0, 0, width(), height()); // diag principala
        update();
        break;
    case 7:
        painter.drawLine(0, height(), width(), 0); // diag secundara
        update();
        break;
    default:
        break;
    }
}
void TicTacToeUI::onButtonClicked()
{

    QPushButton* button = qobject_cast<QPushButton*>(sender());


    if (button) {

        DrawLabel(button);

        buttons.erase(std::remove(buttons.begin(), buttons.end(), button), buttons.end());
        update();
        if (game.CheckGameStatus() > -1)
        {
            paintWinner(game.CheckGameStatus());
            this->update();
            QTimer::singleShot(1000, this, [=]() {
                QMessageBox::information(nullptr, "Game Result", "Player won");
                this->close();
                });
        }
        else
        {
            game.ChangePlayer();
        }
        if (game.m_board.GetAvailableCoordinates().empty())
        {
            QMessageBox::information(nullptr, "Game Result", "No more moves");
            this->close();
        }


    }
    update();
}


TicTacToeUI::~TicTacToeUI()
{}

std::pair<uint8_t, uint8_t> TicTacToeUI::Pickxy(QPushButton* button_aux)
{
    uint8_t x, y;
    if (button_aux->pos().x() == 0)
    {
        x = 0;
    }
    else if (button_aux->pos().x() == width() / 3)
    {
        x = 1;
    }
    else if (button_aux->pos().x() == 2 * width() / 3)
    {
        x = 2;
    }
    if (button_aux->pos().y() == 0)
    {
        y = 0;
    }
    else if (button_aux->pos().y() == height() / 3)
    {
        y = 1;
    }
    else if (button_aux->pos().y() == 2 * height() / 3)
    {
        y = 2;
    }
    return std::make_pair(x, y);
}

void TicTacToeUI::DrawLabel(QPushButton* button_aux)
{
    QLabel* label = new QLabel(this);
    label->setFont(QFont("Arial", 150));
    label->setAlignment(Qt::AlignCenter);
    if (game.m_currentPlayer->GetSymbol() == 'X') {

        label->setText("X");
        game.m_board.AddSymbol('X', Pickxy(button_aux));
    }
    else if (game.m_currentPlayer->GetSymbol() == 'O') {

        label->setText("O");
        game.m_board.AddSymbol('O', Pickxy(button_aux));

    }
    label->setFixedSize(button_aux->size());
    label->move(button_aux->pos() + QPoint(button_aux->width() / 2 - label->width() / 2,
        button_aux->height() / 2 - label->height() / 2));

    label->adjustSize();
    label->show();
    button_aux->deleteLater();

}
