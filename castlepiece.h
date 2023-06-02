#ifndef CASTLEPIECE_H
#define CASTLEPIECE_H

#include "chesspiece.h"

class CastlePiece : public ChessPiece
{
public:
    CastlePiece(QWidget *parent = nullptr, const Board &b = {}, PieceColour clr = BarrierColour);
    QList<Position> possibleMoves();
};

#endif // CASTLEPIECE_H
