#include "pionpiece.h"

PionPiece::PionPiece(QWidget *parent, const Board &b, PieceColour clr)
    : ChessPiece(parent, b, clr)
{
    pieceType = Pion;
    // todo for all derived classes: make it show a nice 100x100 pixmap of the piece in the correct
    // colour instead of this text.
    setPixmap(pieceColour == Black ? QPixmap("swartPion.png").scaled(40, 40) :
                                          QPixmap("witPion.png").scaled(40, 40));
}

QList<Position> PionPiece::possibleMoves()
{
    // Search down for black and up for white, as black pions can only move down and white ones up.
    // Coordinate 0, 0 is top left, playable area starts at 2,2
    // so bigger y values go down and bigger x values go right.
    Position p;
    QList<Position> moves;
    if (pieceColour == Black)
    {
        if (board[x][y+1] == nullptr)
        {
            p.x = x;
            p.y = y+1;
            moves.append(p);
        }
        if (board[x-1][y+1] && (board[x-1][y+1]->colour() == White))
        {
            p.x = x-1;
            p.y = y+1;
            moves.append(p);
        }
        if (board[x+1][y+1] && (board[x+1][y+1]->colour() == White))
        {
            p.x = x+1;
            p.y = y+1;
            moves.append(p);
        }
        if ((timesMoved == 0) && (board[x][y+1] == nullptr))
        {
            if (board[x][y+2] == nullptr)
            {
                p.x = x;
                p.y = y+2;
                moves.append(p);
            }
            if (board[x-1][y+2] && (board[x-1][y+2]->colour() == White))
            {
                p.x = x-1;
                p.y = y+2;
                moves.append(p);
            }
            if (board[x+1][y+2] && (board[x+1][y+2]->colour() == White))
            {
                p.x = x+1;
                p.y = y+2;
                moves.append(p);
            }
        }
    }
    else if (pieceColour == White)
    {
        if (board[x][y-1] == nullptr)
        {
            p.x = x;
            p.y = y-1;
            moves.append(p);
        }
        if (board[x-1][y-1] && (board[x-1][y-1]->colour() == Black))
        {
            p.x = x-1;
            p.y = y-1;
            moves.append(p);
        }
        if (board[x+1][y-1] && (board[x+1][y-1]->colour() == Black))
        {
            p.x = x+1;
            p.y = y-1;
            moves.append(p);
        }
        if ((timesMoved == 0) && (board[x][y-1] == nullptr))
        {
            if (board[x][y-2] == nullptr)
            {
                p.x = x;
                p.y = y-2;
                moves.append(p);
            }
            if (board[x-1][y-2] && (board[x-1][y-2]->colour() == Black))
            {
                p.x = x-1;
                p.y = y-2;
                moves.append(p);
            }
            if (board[x+1][y-2] && (board[x+1][y-2]->colour() == Black))
            {
                p.x = x+1;
                p.y = y-2;
                moves.append(p);
            }
        }
    }
    return moves;
}
