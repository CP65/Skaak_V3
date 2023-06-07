#include "chesspiece.h"

bool Position::operator==(Position const &rhs) const
{
    if ((x == rhs.x) && (y == rhs.y))
        return true;
    return false;
}

ChessPiece::ChessPiece(QWidget *parent, const Board &b, PieceColour clr)
    : QLabel(parent), pieceColour(clr), board(b)
{
    timesMoved = -1; // Piece moved once into position before game starts
    x = 0;
    y = 0;
    setFixedSize(xwidth, ywidth);
}

void ChessPiece::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        emit iWasClicked();
}

QList<Position> ChessPiece::possibleMoves()
{
    // Returns empty list for generic non-existing ChessPiece piece which should not exist.
    // This class acts as a template only so that it can be used as a type representing different chess pieces.
    // Re-implement appropriately in all derived classes.
    QList<Position> moves;
    return moves;
}

void ChessPiece::movePieceTo(float xx, float yy)
{
    // Helper function to move chess piece according to board[][] coordinates.

    x = xx;
    y = yy;
    move((x-2)*xwidth+xoffset, (y-2)*ywidth+yoffset);
    ++timesMoved;
}

int ChessPiece::moveCount()
{
    return timesMoved;
}

int ChessPiece::boardX()
{
    return x;
}

int ChessPiece::boardY()
{
    return y;
}

PieceColour ChessPiece::colour()
{
    return pieceColour;
}

PieceType ChessPiece::type()
{
    return pieceType;
}


