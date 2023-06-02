#ifndef BISHOPPIECE_H
#define BISHOPPIECE_H

#include "chesspiece.h"

class BishopPiece : public ChessPiece
{
public:
    BishopPiece(QWidget *parent = nullptr, const Board &b = {}, PieceColour clr = BarrierColour);
    QList<Position> possibleMoves();
};

#endif // BISHOPPIECE_H
