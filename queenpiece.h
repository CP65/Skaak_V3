#ifndef QUEENPIECE_H
#define QUEENPIECE_H

#include "chesspiece.h"

class QueenPiece : public ChessPiece
{
public:
    QueenPiece(QWidget *parent = nullptr, const Board &b = {}, PieceColour clr = BarrierColour);
    QList<Position> possibleMoves();
};

#endif // QUEENPIECE_H
