#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <QWidget>
#include "chesspiece.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QCoreApplication>

class ChessGame : public QWidget
{
    Q_OBJECT

public:
    ChessGame(QWidget *parent = nullptr);



private:
    void mousePressEvent(QMouseEvent*);
    bool movePiece(Position&, Position&);

    Board board;

    QList<ChessPiece*> takenPieces;
    QLabel *boardLabel;
    QLabel *turnLabel;
    QLabel *debugLabel;

    // Show move circles
    QVector<QLabel*> possibleMoveLabels;

    PieceColour whoseTurnIsIt;
    Position selectedSource;
    Position selectedDestination;

    QMediaPlayer* mediaPlayer;        // Player for the lofi song
    QMediaPlayer* soundEffectPlayer;  // Player for the sound effect

private slots:
    void pieceClicked();
    void clearPossibleMoveLabels();
    void handleSoundEffectFinished()
    {
            // Resume playing the lofi song
            mediaPlayer->play();
    }
};
#endif // CHESSGAME_H
