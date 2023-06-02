#ifndef PIONPIECE_H
#define PIONPIECE_H

#include "chesspiece.h"

class PionPiece : public ChessPiece
{
public:
    PionPiece(QWidget *parent = nullptr, const Board &b = {}, PieceColour clr = BarrierColour);
    QList<Position> possibleMoves();
};

#endif // PIONPIECE_H
