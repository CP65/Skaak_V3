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

class ChessGame : public QWidget
{
    Q_OBJECT

public:
    ChessGame(QWidget *parent = nullptr);
    void showExplosion(float x, float y);

    QPushButton *newGameButton;


private:
    void mousePressEvent(QMouseEvent*);
    bool movePiece(Position&, Position&);
    void playBackgroundMusic();
    void playMetal();

  //  QPushButton *newGameButton;

    QTimer* timer;

    Board board;

    QList<ChessPiece*> takenPieces;
    QLabel *boardLabel;
    QLabel *turnLabel;
    QLabel *debugLabel;
    QLabel *explosionLabel;
    QMovie* explosion;

    // Show move circles
    QVector<QLabel*> possibleMoveLabels;

    PieceColour whoseTurnIsIt;
    Position selectedSource;
    Position selectedDestination;

    QMediaPlayer* mediaPlayer;        // Player for the lofi song
    QMediaPlayer* soundEffectPlayer;  // Player for the sound effect

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
    void restart();
    void newGame();
};
#endif // CHESSGAME_H
