#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <QWidget>
#include "chesspiece.h"

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


    PieceColour whoseTurnIsIt;
    Position selectedSource;
    Position selectedDestination;

private slots:
    void pieceClicked();
};
#endif // CHESSGAME_H
