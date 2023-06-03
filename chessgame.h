#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <QWidget>
#include "chesspiece.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>

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

    // New stuff for showing moves - delete if N/A
    QVector<QLabel*> possibleMoveLabels;


    PieceColour whoseTurnIsIt;
    Position selectedSource;
    Position selectedDestination;

private slots:
    void pieceClicked();
    // New - delete if N/A
    void clearPossibleMoveLabels();
};
#endif // CHESSGAME_H
