#include "chessgame.h"
#include "chesspiece.h"
#include "barrierpiece.h"
#include "pionpiece.h"
#include "horsepiece.h"
#include "bishoppiece.h"
#include "castlepiece.h"
#include "queenpiece.h"
#include "kingpiece.h"
#include "rankings.h"

#include <QPainter>
#include <QVBoxLayout>

int a = 0;
int z = 0;
int o = 0;
bool p = 0;

float x1 = 0;
float y1 = 0;
Rankings r;

ChessGame::ChessGame(QWidget *parent)
    : QWidget(parent)
{
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter your text");  // Set a placeholder text
    lineEdit->setMaxLength(100);  // Set a maximum length for the input
    QString enteredText = lineEdit->text();
    QByteArray text = enteredText.toUtf8();
    connect(lineEdit, SIGNAL(QLineEdit::returnPressed), this, SLOT(ChessGame::handleTextEntered()));

    //Rankings r;
    r.addScore("deeznuts", 69);

   // QPushButton *newGameButton = new QPushButton("NEW GAME", this);
    newGameButton = new QPushButton("NEW GAME", this);
    connect (newGameButton, &QPushButton::clicked, this, &ChessGame::newGame);
    newGameButton->setGeometry(550, 488, 400, 25);
    newGameButton->setStyleSheet("QPushButton {"
                                 "background-color: green;"
                                 "color: white;"
                                 "border_style: outset;"
                                 "border-width: 2px;"
                                 "border-radius: 10px;"
                                 "border-color: beige;"
                                 "font: bold 14px;"
                                 "padding: 6px; }"
                                 "QPushButton:hover {"
                                 "background-color: darkGreen; }"
                                 "QPushButton:pressed {"
                                 "background-color: red; }");

    //QPushButton *restartButton = new QPushButton("RESTART", this);
    restartButton = new QPushButton("RESTART", this);
    connect(restartButton, &QPushButton::clicked, this, &ChessGame::restart);
    restartButton->setGeometry(900, 470, 400, 25);
    restartButton->setStyleSheet("QPushButton {"
                                 "background-color: green;"
                                 "color: white;"
                                 "border_style: outset;"
                                 "border-width: 2px;"
                                 "border-radius: 10px;"
                                 "border-color: beige;"
                                 "font: bold 14px;"
                                 "padding: 6px; }"
                                 "QPushButton:hover {"
                                 "background-color: darkGreen; }"
                                 "QPushButton:pressed {"
                                 "background-color: red; }");
    restartButton->hide();

    mainMenuButton = new QPushButton("MAIN MENU", this);
    connect(mainMenuButton, &QPushButton::clicked, this, &ChessGame::mainMenu);
    mainMenuButton->setGeometry(900, 520, 400, 25);
    mainMenuButton->setStyleSheet("QPushButton {"
                                 "background-color: green;"
                                 "color: white;"
                                 "border_style: outset;"
                                 "border-width: 2px;"
                                 "border-radius: 10px;"
                                 "border-color: beige;"
                                 "font: bold 14px;"
                                 "padding: 6px; }"
                                 "QPushButton:hover {"
                                 "background-color: darkGreen; }"
                                 "QPushButton:pressed {"
                                 "background-color: red; }");
    mainMenuButton->hide();

    setFixedSize(1500, 1000);

    QPixmap background("background4.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(background.scaled(1500, 1000)));
    setAutoFillBackground(true);
    setPalette(palette);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timertick()));
    timer->setInterval(10);
    timer->start();

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(timer1tick()));
    timer1->setInterval(1000);
    timer1Label = new QLabel(this);
    timer1Label->setGeometry(900, 900, 200, 100);
    timer1Label->setText("White: 5:00");
    timer1Label->setStyleSheet("font-weight: bold;"
                               "font-size: 30px");
    timer1Label->hide();
    seconds1 = 0;
    minutes1 = 5;

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(timer2tick()));
    timer2->setInterval(1000);
    timer2Label = new QLabel(this);
    timer2Label->setGeometry(900, 0, 200, 100);
    timer2Label->setText("Black: 5:00");
    timer2Label->setStyleSheet("font-weight: bold;"
                               "font-size: 30px");
    timer2Label->hide();
    seconds2 = 0;
    minutes2 = 5;

    explosion = new QMovie("explosion.gif");
    explosionLabel = new QLabel(this);

    whoseTurnIsIt = White;
    selectedSource.x = 0;
    selectedSource.y = 0;
    selectedDestination.x = 0;
    selectedDestination.y = 0;

    getRektLabel = new QLabel(this);
    getRektLabel->setGeometry(500, 0, 200, 100);
    getRektLabel->setText("get rekt");
    getRektLabel->setStyleSheet("color: black;"
                           "font-size: 20px;"
                           "font-weight: bold;");
    getRektLabel->hide();


    boardLabel = new QLabel(this);
    boardLabel->setGeometry(70, 100, 800, 800);
    boardLabel->setPixmap(QPixmap("skaakBord2.png").scaled(800,800));
    // todo: make boardLabel show a nice 800x800 chess board image

    turnLabel = new QLabel(this);
    turnLabel->setGeometry(500, 0, 200, 100);
    turnLabel->setStyleSheet("color: black;"
                           "font-size: 20px;"
                           "font-weight: bold;");
    turnLabel->setText("White moves.\nClick piece to move.");


    debugLabel = new QLabel(this);
    debugLabel->setGeometry(0, 850, 800, 200);


    for (int i = 0; i < 12; ++i)
    {
        board[i][0] = new BarrierPiece(this);
        board[i][1] = new BarrierPiece(this);

        board[i][4] = nullptr;
        board[i][5] = nullptr;
        board[i][6] = nullptr;
        board[i][7] = nullptr;

        board[i][10] = new BarrierPiece(this);
        board[i][11] = new BarrierPiece(this);
    }

    board[2][2] = new CastlePiece(this, board, Black);
    board[2][2]->movePieceTo(2, 2);
    board[3][2] = new HorsePiece(this, board, Black);
    board[3][2]->movePieceTo(3, 2);
    board[4][2] = new BishopPiece(this, board, Black);
    board[4][2]->movePieceTo(4, 2);
    board[5][2] = new QueenPiece(this, board, Black);
    board[5][2]->movePieceTo(5, 2);
    board[6][2] = new KingPiece(this, board, Black);
    board[6][2]->movePieceTo(6, 2);
    board[7][2] = new BishopPiece(this, board, Black);
    board[7][2]->movePieceTo(7, 2);
    board[8][2] = new HorsePiece(this, board, Black);
    board[8][2]->movePieceTo(8, 2);
    board[9][2] = new CastlePiece(this, board, Black);
    board[9][2]->movePieceTo(9, 2);

    board[2][9] = new CastlePiece(this, board, White);
    board[2][9]->movePieceTo(2, 9);
    board[3][9] = new HorsePiece(this, board, White);
    board[3][9]->movePieceTo(3, 9);
    board[4][9] = new BishopPiece(this, board, White);
    board[4][9]->movePieceTo(4, 9);
    board[5][9] = new QueenPiece(this, board, White);
    board[5][9]->movePieceTo(5, 9);
    board[6][9] = new KingPiece(this, board, White);
    board[6][9]->movePieceTo(6, 9);
    board[7][9] = new BishopPiece(this, board, White);
    board[7][9]->movePieceTo(7, 9);
    board[8][9] = new HorsePiece(this, board, White);
    board[8][9]->movePieceTo(8, 9);
    board[9][9] = new CastlePiece(this, board, White);
    board[9][9]->movePieceTo(9, 9);

    for (int i = 2; i < 10; ++i)
    {
        board[0][i] = new BarrierPiece(this);
        board[1][i] = new BarrierPiece(this);

        board[i][3] = new PionPiece(this, board, Black);
        board[i][3]->movePieceTo(i, 3);

        board[i][8] = new PionPiece(this, board, White);
        board[i][8]->movePieceTo(i, 8);

        board[10][i] = new BarrierPiece(this);
        board[11][i] = new BarrierPiece(this);

        connect(board[i][2], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][3], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][8], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][9], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
    }

    boardLabel->hide();
    debugLabel->hide();
    turnLabel->hide();

    for (int i = 2; i < 10; ++i)
    {
        board[i][3]->hide();
        board[i][2]->hide();
        board[i][8]->hide();
        board[i][9]->hide();
    }
}

void ChessGame::handleTextEntered()
{
   r.addScore("halloooooooooooooooooo", 69);
}

void ChessGame::timer1tick()
{

  if(seconds1 == 0 && minutes1 > 0)
  {
      minutes1 = minutes1 - 1;
      seconds1 = 59;
  }

  if(seconds1 < 10)
  {
      timer1Label->setText("White: " + QString::number(minutes1) + ":0" + QString::number(seconds1));
  }
  else if(seconds1 >= 10)
  {
       timer1Label->setText("White: " + QString::number(minutes1) + ":" + QString::number(seconds1));
  }

  if(minutes1 <= 0 && seconds1 <= 0)
  {
      timer1Label->setText("Time is up!");
      timer1->stop();
      disable();
  }

  seconds1 = seconds1 - 1;
}

void ChessGame::timer2tick()
{
    if(seconds2 == 0)
    {
        minutes2 = minutes2 - 1;
        seconds2 = 59;
    }

    if(minutes2 == 0 && seconds2 == 0)
    {
        timer2Label->setText("Time is up!");
    }

    if(seconds2 < 10)
    {
        timer2Label->setText("Black: " + QString::number(minutes2) + ":0" + QString::number(seconds2));
    }
    else if(seconds2 >= 10)
    {
         timer2Label->setText("Black: " + QString::number(minutes2) + ":" + QString::number(seconds2));
    }

    if(minutes2 <= 0 && seconds2 <= 0)
    {
        timer2Label->setText("Time is up!");
        timer2->stop();
        disable();
    }

    seconds2 = seconds2 - 1;
}

void ChessGame::disable()
{
  enabled = 0;
}

void ChessGame::enable()
{
  enabled = 1;
}

void ChessGame::newGame()
{
    newGameButton->hide();  //awe dit werk
    boardLabel->show();
    timer1Label->show();
    timer1->start();
    timer2Label->show();
    enable();
    //timer2->start();

    if(p == 0)
    {
        playBackgroundMusic();
    }

    debugLabel->show();
    turnLabel->show();
    restartButton->show();
    mainMenuButton->show();

    for (int i = 2; i < 10; ++i)
    {
        board[i][3]->show();
        board[i][2]->show();
        board[i][8]->show();
        board[i][9]->show();
    }
}

void ChessGame::restart()
{
    newGameButton->hide();
    enable();

    minutes1 = 5;
    seconds1 = 0;
    timer1Label->setText("White: " + QString::number(minutes1) + ":0" + QString::number(seconds1));
    timer1->start();

    minutes2 = 5;
    seconds2 = 0;
    timer2Label->setText("Black: " + QString::number(minutes2) + ":0" + QString::number(seconds2));
    timer2->stop();

    whoseTurnIsIt = White;
    selectedSource.x = 0;
    selectedSource.y = 0;
    selectedDestination.x = 0;
    selectedDestination.y = 0;

    turnLabel->setText("White moves.\nClick piece to move.");

    for (int i = 2; i < 10; ++i)
    {
        for (int j = 2; j < 10; ++j)
        {
            if(board[i][j] != nullptr)
            {
                board[i][j]->hide();
                board[i][j]->deleteLater();
                board[i][j] = nullptr;
            }
        }

    }

    board[2][2] = new CastlePiece(this, board, Black);
    board[2][2]->movePieceTo(2, 2);
    board[3][2] = new HorsePiece(this, board, Black);
    board[3][2]->movePieceTo(3, 2);
    board[4][2] = new BishopPiece(this, board, Black);
    board[4][2]->movePieceTo(4, 2);
    board[5][2] = new QueenPiece(this, board, Black);
    board[5][2]->movePieceTo(5, 2);
    board[6][2] = new KingPiece(this, board, Black);
    board[6][2]->movePieceTo(6, 2);
    board[7][2] = new BishopPiece(this, board, Black);
    board[7][2]->movePieceTo(7, 2);
    board[8][2] = new HorsePiece(this, board, Black);
    board[8][2]->movePieceTo(8, 2);
    board[9][2] = new CastlePiece(this, board, Black);
    board[9][2]->movePieceTo(9, 2);

    board[2][9] = new CastlePiece(this, board, White);
    board[2][9]->movePieceTo(2, 9);
    board[3][9] = new HorsePiece(this, board, White);
    board[3][9]->movePieceTo(3, 9);
    board[4][9] = new BishopPiece(this, board, White);
    board[4][9]->movePieceTo(4, 9);
    board[5][9] = new QueenPiece(this, board, White);
    board[5][9]->movePieceTo(5, 9);
    board[6][9] = new KingPiece(this, board, White);
    board[6][9]->movePieceTo(6, 9);
    board[7][9] = new BishopPiece(this, board, White);
    board[7][9]->movePieceTo(7, 9);
    board[8][9] = new HorsePiece(this, board, White);
    board[8][9]->movePieceTo(8, 9);
    board[9][9] = new CastlePiece(this, board, White);
    board[9][9]->movePieceTo(9, 9);

    for (int i = 2; i < 10; ++i)
    {

        board[i][3] = new PionPiece(this, board, Black);
        board[i][3]->movePieceTo(i, 3);
        board[i][3]->show();

        board[i][8] = new PionPiece(this, board, White);
        board[i][8]->movePieceTo(i, 8);
        board[i][8]->show();

        board[i][2]->show();
        board[i][9]->show();

        connect(board[i][2], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][3], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][8], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][9], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
    }

}

void ChessGame::mainMenu()
{
    newGameButton->hide();
    enable();

    whoseTurnIsIt = White;
    selectedSource.x = 0;
    selectedSource.y = 0;
    selectedDestination.x = 0;
    selectedDestination.y = 0;

    turnLabel->setText("White moves.\nClick piece to move.");

    for (int i = 2; i < 10; ++i)
    {
        for (int j = 2; j < 10; ++j)
        {
            if(board[i][j] != nullptr)
            {
                board[i][j]->hide();
                board[i][j]->deleteLater();
                board[i][j] = nullptr;
            }
        }

    }

    board[2][2] = new CastlePiece(this, board, Black);
    board[2][2]->movePieceTo(2, 2);
    board[3][2] = new HorsePiece(this, board, Black);
    board[3][2]->movePieceTo(3, 2);
    board[4][2] = new BishopPiece(this, board, Black);
    board[4][2]->movePieceTo(4, 2);
    board[5][2] = new QueenPiece(this, board, Black);
    board[5][2]->movePieceTo(5, 2);
    board[6][2] = new KingPiece(this, board, Black);
    board[6][2]->movePieceTo(6, 2);
    board[7][2] = new BishopPiece(this, board, Black);
    board[7][2]->movePieceTo(7, 2);
    board[8][2] = new HorsePiece(this, board, Black);
    board[8][2]->movePieceTo(8, 2);
    board[9][2] = new CastlePiece(this, board, Black);
    board[9][2]->movePieceTo(9, 2);

    board[2][9] = new CastlePiece(this, board, White);
    board[2][9]->movePieceTo(2, 9);
    board[3][9] = new HorsePiece(this, board, White);
    board[3][9]->movePieceTo(3, 9);
    board[4][9] = new BishopPiece(this, board, White);
    board[4][9]->movePieceTo(4, 9);
    board[5][9] = new QueenPiece(this, board, White);
    board[5][9]->movePieceTo(5, 9);
    board[6][9] = new KingPiece(this, board, White);
    board[6][9]->movePieceTo(6, 9);
    board[7][9] = new BishopPiece(this, board, White);
    board[7][9]->movePieceTo(7, 9);
    board[8][9] = new HorsePiece(this, board, White);
    board[8][9]->movePieceTo(8, 9);
    board[9][9] = new CastlePiece(this, board, White);
    board[9][9]->movePieceTo(9, 9);

    for (int i = 2; i < 10; ++i)
    {

        board[i][3] = new PionPiece(this, board, Black);
        board[i][3]->movePieceTo(i, 3);
        board[i][3]->show();

        board[i][8] = new PionPiece(this, board, White);
        board[i][8]->movePieceTo(i, 8);
        board[i][8]->show();

        board[i][2]->show();
        board[i][9]->show();

        connect(board[i][2], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][3], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][8], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
        connect(board[i][9], SIGNAL(iWasClicked()), this, SLOT(pieceClicked()));
    }

    boardLabel->hide();
    debugLabel->hide();
    turnLabel->hide();
    restartButton->hide();
    mainMenuButton->hide();
    newGameButton->show();

    for (int i = 2; i < 10; ++i)
    {
        board[i][3]->hide();
        board[i][2]->hide();
        board[i][8]->hide();
        board[i][9]->hide();
    }

    p = 1;
}

void ChessGame::showExplosion(float x, float y)
{
    explosionLabel->setGeometry(x, y, 110, 100);
    explosionLabel->setMovie(explosion);
    explosionLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // Make the label click-through
    explosionLabel->show();
    explosionLabel->raise();
    explosion->start();
    z = 1;
}

void ChessGame::timertick()
{
    if(z == 1)
    {

        if(explosion->currentFrameNumber() >= 25)
        {
            explosion->stop();
            explosionLabel->hide();
            turnLabel->show();
            getRektLabel->hide();
            z = 2;
        }
    }

    if(o == 1)
    {
        if(soundEffectPlayer->state() == soundEffectPlayer->StoppedState)
        {
            mediaPlayer->play();
            o = 0;
        }
    }

}

void ChessGame::playBackgroundMusic()
{
    mediaPlayer = new QMediaPlayer(this);
    // Set up the media content for the lofi song
    QMediaContent lofiSongContent(QUrl("paganini_1.mp3"));
    mediaPlayer->setMedia(lofiSongContent);
    mediaPlayer->setVolume(20);

    // Connect the mediaStatusChanged signal to the handleSoundEffectFinished slot
    //connect(mediaPlayer, soundEffectPlayer->mediaStatusChanged, this, ChessGame::resumeBackground());

    mediaPlayer->play();
}

void ChessGame::playMetal()
{
    turnLabel->hide();
    getRektLabel->show();
    soundEffectPlayer = new QMediaPlayer(this);
    QMediaContent soundEffectContent(QUrl("pieceTakenMusic.mp3"));
    soundEffectPlayer->setMedia(soundEffectContent);
    soundEffectPlayer->setVolume(50);
    // Play the sound effect
    mediaPlayer->pause();
    soundEffectPlayer->play();

    o = 1;
}

void ChessGame::pieceClicked()
{
    if(enabled == 1)

{
    clearPossibleMoveLabels();

    ChessPiece *clickedPiece = (ChessPiece*)sender();

    debugLabel->setText("Clicked piece at " + QString::number(clickedPiece->boardX()) +
                        ", " + QString::number(clickedPiece->boardY()) + "\nMoves: ");
    QList<Position> moves = clickedPiece->possibleMoves();
    QListIterator<Position> mvIter(moves);
    while (mvIter.hasNext())
    {
        Position p = mvIter.next();
        debugLabel->setText(debugLabel->text() + QString::number(p.x) + ", " + QString::number(p.y) + " || ");

        // Drawing possible moves on the board only if it is correct player's turn
        if ((clickedPiece->colour() == White && whoseTurnIsIt == White) ||
                (clickedPiece->colour() == Black && whoseTurnIsIt == Black))
        {
            QLabel* possibleMoveLabel = new QLabel(boardLabel);
            possibleMoveLabel->resize(50, 50);

            QPixmap pixmap(50, 50);
            pixmap.fill(Qt::transparent);
            QPainter painter(&pixmap);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setPen(Qt::NoPen);

            // Check if it is a capture move
            bool isCapture = false;
            if (board[p.x][p.y])
            {
                if ((board[p.x][p.y]->colour() == White && clickedPiece->colour() == Black) ||
                    (board[p.x][p.y]->colour() == Black && clickedPiece->colour() == White))
                {
                    isCapture = true;
                }
            }

            if (isCapture)
            {
                painter.setBrush(QColor(255, 0, 0, 128));
            }
            else
            {
                painter.setBrush(QColor(0, 0, 0, 128));
            }

            if (!takenPieces.contains(clickedPiece))
            {
                painter.drawEllipse(0,0,50,50);
            }

            possibleMoveLabel->setPixmap(pixmap);

            QPoint widgetPos = QPoint((p.x - 2.5) * clickedPiece->xwidth + clickedPiece->xoffset - 0 - possibleMoveLabel->width()/2,
                                     (p.y - 2.5) * clickedPiece->ywidth + clickedPiece->yoffset - 0 - possibleMoveLabel->height()/2);

            possibleMoveLabel->move(widgetPos);
            possibleMoveLabel->raise();
            possibleMoveLabel->show();

            possibleMoveLabels.append(possibleMoveLabel);
        }
    }

    // No destination selected and we click on our own colour piece
    if (!selectedDestination.x && whoseTurnIsIt == clickedPiece->colour())
    {
        selectedSource.x = clickedPiece->boardX();
        selectedSource.y = clickedPiece->boardY();
        turnLabel->setText(turnLabel->text() + "\nClick destination.");
    }
    // Source selected, no destination selected, next click on opposite colour piece (cannot click on barrier pieces, hence != sufficient here)
    else if (selectedSource.x && !selectedDestination.x && whoseTurnIsIt != clickedPiece->colour())
    {
        selectedDestination.x = clickedPiece->boardX();
        selectedDestination.y = clickedPiece->boardY();
        movePiece(selectedSource, selectedDestination);
        //showExplosion(selectedDestination.x, selectedDestination.y);
    }
    debugLabel->setText(debugLabel->text() + "\nsx " + QString::number(selectedSource.x) + " sy " + QString::number(selectedSource.y) +
                                         " dx " + QString::number(selectedDestination.x) + " dy " + QString::number(selectedDestination.y));

}
}

// New - delete if N/A
void ChessGame::clearPossibleMoveLabels()
{

    for (QLabel* label : possibleMoveLabels)
    {
        delete label;
    }
    possibleMoveLabels.clear();
}

void ChessGame::mousePressEvent(QMouseEvent *e)
{
    if(enabled)
    {


    // suck these constants out of the barrier piece at [0][0] which will always be there.
    // this is not necessarily elegant, but I do not want to duplicate these constants.
    // think of a more elegant way if this bothers you. (it should)
    float xoffset = board[0][0]->xoffset;
    float yoffset = board[0][0]->yoffset;
    float xwidth = board[0][0]->xwidth;
    float ywidth = board[0][0]->ywidth;

    if ((e->button() == Qt::LeftButton) && (e->x() >= xoffset) && (e->x() <= xoffset+8*xwidth)
         && (e->y() >= yoffset) && (e->y() <= yoffset+8*ywidth))
    {
        // New delete if N/A
        clearPossibleMoveLabels();

        float clickx = ((e->x()-xoffset)/xwidth+2)+0.3;
        float clicky = (e->y()-yoffset)/ywidth+2;

        x1 = e->x();
        y1 = e->y();
        debugLabel->setText("Clicked on empty board square " + QString::number(clickx) +
                            ", " + QString::number(clicky));
        debugLabel->setText(debugLabel->text() + "\nEmpty space has no moves.");
        debugLabel->setText(debugLabel->text() + "\nsx " + QString::number(selectedSource.x) + " sy " + QString::number(selectedSource.y) +
                            " dx " + QString::number(selectedDestination.x) + " dy " + QString::number(selectedDestination.y));

        // If we selected a source but not a destination, clicking an empty block means we select it as destination
        if (selectedSource.x && !selectedDestination.x)
            {
            selectedDestination.x = clickx;
            selectedDestination.y = clicky;
            movePiece(selectedSource, selectedDestination);
        }
    }
   }
}

 int whiteTakenx = 875;
 int blackTakenx = 875;

bool ChessGame::movePiece(Position &source, Position &destination)
{
    // New - delete if N/A
    clearPossibleMoveLabels();

    // The visible board (piece widgets) and invisible state of the board inside member "board" must always be kept in sync.

    // This function might look like overkill, but we must code defensively so that lying to this function due to errors in
    // other places will not break or crash the program unnecessarily.
    bool moved = false;

    // Only move if there is something to move at source, nullptr dereference will crash the program.
    if (board[source.x][source.y])
    {
        // Test if destination exists in source possible moves.
        // We must abort the move if it is invalid.
        QList<Position> moves = board[source.x][source.y]->possibleMoves();
        QListIterator<Position> mvIter(moves);
        bool invalidMove = true;
        while (mvIter.hasNext())
        {
            Position p = mvIter.next();
            if (p == destination)
            {
                invalidMove = false;
                break;
            }
        }
        if (invalidMove)
        {
            // Start selecting from scratch
            selectedSource.x = 0;
            selectedDestination.x = 0;
            return false;
        }

        // Should we get this far, we have a valid move.
        // If there is something to take at the destination, take it.
        if (board[destination.x][destination.y])
        {
            // Verify opposite colours
            if ((board[destination.x][destination.y]->colour() == White && board[source.x][source.y]->colour() == Black) ||
                (board[destination.x][destination.y]->colour() == Black && board[source.x][source.y]->colour() == White))
            {

                // Remove taken piece
                takenPieces.append(board[destination.x][destination.y]);
                //Play sound effect
                playMetal();

                //Show explosion
                x1 = (destination.x*100) - 150;
                y1 = (destination.y*100) - 120;

                QString stringValue = QString::number(x1);
                QString stringValue1 = QString::number(y1);
                debugLabel->setText(debugLabel->text() + "x1 = " + stringValue);
                debugLabel->setText(debugLabel->text() + "y1 = " + stringValue1);

//                showExplosion(destination.x*75, destination.y*90);
                showExplosion(x1, y1);



                //move taken pieces to the side
                 if ((board[destination.x][destination.y]->colour() == White))
                 {
                     whiteTakenx = whiteTakenx + 50;
                     board[destination.x][destination.y]->move(whiteTakenx, 100);
                 }

                 if ((board[destination.x][destination.y]->colour() == Black))
                 {
                     blackTakenx = blackTakenx + 50;
                     board[destination.x][destination.y]->move(blackTakenx, 800);
                 }

                // Move and update the widget (ChessPiece*)
                board[source.x][source.y]->movePieceTo(destination.x, destination.y);
                // Update board
                board[destination.x][destination.y] = board[source.x][source.y];
                board[source.x][source.y] = nullptr;

                moved = true;
            }
        }
        // Otherwise if destination is empty, just move there
        else
        {
            // Move and update the widget (ChessPiece*)
            board[source.x][source.y]->movePieceTo(destination.x, destination.y);
            // Update board
            board[destination.x][destination.y] = board[source.x][source.y];
            board[source.x][source.y] = nullptr;

            moved = true;
        }
    }

    // Reset move input on calling movePiece() whether it was successful or not, so that user can retry if necessary
    // Only necessary to invalidate one, we choose and use x
    selectedSource.x = 0;
    selectedDestination.x = 0;

    // Switch sides if move was successful
    if (moved)
    {
        if (whoseTurnIsIt == White)
        {
            timer1->stop();
            timer2->start();
            whoseTurnIsIt = Black;
            turnLabel->setText("Black moves.\nClick piece to move.");
        }
        else
        {
            timer2->stop();
            timer1->start();
            whoseTurnIsIt = White;
            turnLabel->setText("White moves.\nClick piece to move.");
        }
    }

    // In case someone cares
    return moved;
}
