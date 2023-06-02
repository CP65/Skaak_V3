#ifndef KINGPIECE_H
#define KINGPIECE_H

#include "chesspiece.h"

class KingPiece : public ChessPiece
{
public:
    KingPiece(QWidget *parent = nullptr, const Board &b = {}, PieceColour clr = BarrierColour);
    QList<Position> possibleMoves();
};

#endif // KINGPIECE_H
