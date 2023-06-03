#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <QWidget>
#include "chesspiece.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QMovie>

class ChessGame : public QWidget
{
    Q_OBJECT

public:
    ChessGame(QWidget *parent = nullptr);
    void showExplosion(int x, int y);


private:
    void mousePressEvent(QMouseEvent*);
    bool movePiece(Position&, Position&);

    Board board;

    QList<ChessPiece*> takenPieces;
    QLabel *boardLabel;
    QLabel *turnLabel;
    QLabel *debugLabel;
    QMovie* explosion;

    // Show move circles
    QVector<QLabel*> possibleMoveLabels;

    PieceColour whoseTurnIsIt;
    Position selectedSource;
    Position selectedDestination;

    QMediaPlayer* mediaPlayer;        // Player for the lofi song
    QMediaPlayer* soundEffectPlayer;  // Player for the sound effect

signals:
    void finished();
    void frameChanged(int);

//public slots:
//    void stop(int);

private slots:
    void pieceClicked();
    void clearPossibleMoveLabels();
    void playBackgroundMusic();
    void playMetal();
};
#endif // CHESSGAME_H
