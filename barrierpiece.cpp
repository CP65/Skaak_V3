#include "barrierpiece.h"

BarrierPiece::BarrierPiece(QWidget *parent)
    : ChessPiece(parent)
{
    pieceType = Barrier;
    pieceColour = BarrierColour;
    hide();
}
