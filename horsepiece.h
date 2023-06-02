#ifndef HORSEPIECE_H
#define HORSEPIECE_H

#include "chesspiece.h"

class HorsePiece : public ChessPiece
{
public:
    HorsePiece(QWidget *parent = nullptr, const Board &b = {}, PieceColour clr = BarrierColour);
    QList<Position> possibleMoves();
};

#endif // HORSEPIECE_H
