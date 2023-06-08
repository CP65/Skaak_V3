#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <QWidget>
#include "chesspiece.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QMovie>
#include <QTimer>
#include <QPushButton>
#include <QLineEdit>


class ChessGame : public QWidget
{
    Q_OBJECT

public:
    ChessGame(QWidget *parent = nullptr);

    void showExplosion(float x, float y);

    QPushButton *newGameButton;
    QPushButton *restartButton;
    QPushButton *mainMenuButton;
    QLineEdit *lineEdit;

    int seconds1;
    int minutes1;
    int seconds2;
    int minutes2;

    void disable();
    void enable();

private:
    void mousePressEvent(QMouseEvent*);
    bool movePiece(Position&, Position&);
    void playBackgroundMusic();
    void playMetal();

    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;

    Board board;

    QList<ChessPiece*> takenPieces;
    QLabel *boardLabel;
    QLabel *turnLabel;
    QLabel *getRektLabel;
    QLabel *debugLabel;
    QLabel *explosionLabel;
    QLabel *timer2Label;
    QLabel *timer1Label;
    QMovie* explosion;

    // Show move circles
    QVector<QLabel*> possibleMoveLabels;

    PieceColour whoseTurnIsIt;
    Position selectedSource;
    Position selectedDestination;

    QMediaPlayer* mediaPlayer;        // Player for the lofi song
    QMediaPlayer* soundEffectPlayer;  // Player for the sound effect

    bool enabled;

//signals:
//    void finished();
//    void frameChanged(int);

//public slots:
//    void stop(int);

public slots:
   // void newGame();

private slots:
    void pieceClicked();
    void clearPossibleMoveLabels();
    void timertick();
    void timer1tick();
    void timer2tick();
    void restart();
    void newGame();
    void mainMenu();
    void handleTextEntered();
};
#endif // CHESSGAME_H
