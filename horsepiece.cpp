#include "horsepiece.h"

HorsePiece::HorsePiece(QWidget *parent, const Board &b, PieceColour clr)
    : ChessPiece(parent, b, clr)
{
    pieceType = Horse;
   //setText(pieceColour == Black ? "Swart\nPerd" : "Wit\nPerd");
    setPixmap(pieceColour == Black ? QPixmap("swartPerd.png").scaled(40, 40) :
                                          QPixmap("witPerd.png").scaled(40, 40));

}

QList<Position> HorsePiece::possibleMoves()
{
    Position p;
    QList<Position> moves;

    PieceColour oppositeColour;

    if (pieceColour == Black)
    {
        oppositeColour = White;
    }
    else if (pieceColour == White)
    {
        oppositeColour = Black;
    }
    else
    {
        oppositeColour = BarrierColour;
    }

    // 2 regs, 1 op
    if (board[x+2][y-1] == nullptr)
    {
        p.x = x+2;
        p.y = y-1;
        moves.append(p);
    }
    else if (board[x+2][y-1] && board[x+2][y-1]->colour() == oppositeColour)
    {
        p.x = x+2;
        p.y = y-1;
        moves.append(p);
    }
    else
    {

    }

    // 2 regs, 1 af
    if (board[x+2][y+1] == nullptr)
    {
        p.x = x+2;
        p.y = y+1;
        moves.append(p);
    }
    else if (board[x+2][y+1] && board[x+2][y+1]->colour() == oppositeColour)
    {
        p.x = x+2;
        p.y = y+1;
        moves.append(p);
    }
    else
    {

    }

    // 2 af, 1 regs
    if (board[x+1][y+2] == nullptr)
    {
        p.x = x+1;
        p.y = y+2;
        moves.append(p);
    }
    else if (board[x+1][y+2] && board[x+1][y+2]->colour() == oppositeColour)
    {
        p.x = x+1;
        p.y = y+2;
        moves.append(p);
    }
    else
    {

    }

    // 2 af, 1 links
    if (board[x-1][y+2] == nullptr)
    {
        p.x = x-1;
        p.y = y+2;
        moves.append(p);
    }
    else if (board[x-1][y+2] && board[x-1][y+2]->colour() == oppositeColour)
    {
        p.x = x-1;
        p.y = y+2;
        moves.append(p);
    }
    else
    {

    }

    // 2 links, 1 af
    if (board[x-2][y+1] == nullptr)
    {
        p.x = x-2;
        p.y = y+1;
        moves.append(p);
    }
    else if (board[x-2][y+1] && board[x-2][y+1]->colour() == oppositeColour)
    {
        p.x = x-2;
        p.y = y+1;
        moves.append(p);
    }
    else
    {

    }

    // 2 links, 1 op
    if (board[x-2][y-1] == nullptr)
    {
        p.x = x-2;
        p.y = y-1;
        moves.append(p);
    }
    else if (board[x-2][y-1] && board[x-2][y-1]->colour() == oppositeColour)
    {
        p.x = x-2;
        p.y = y-1;
        moves.append(p);
    }
    else
    {

    }

    // 2 op, 1 links
    if (board[x-1][y-2] == nullptr)
    {
        p.x = x-1;
        p.y = y-2;
        moves.append(p);
    }
    else if (board[x-1][y-2] && board[x-1][y-2]->colour() == oppositeColour)
    {
        p.x = x-1;
        p.y = y-2;
        moves.append(p);
    }
    else
    {

    }

    // 2 op, 1 regs
    if (board[x+1][y-2] == nullptr)
    {
        p.x = x+1;
        p.y = y-2;
        moves.append(p);
    }
    else if (board[x+1][y-2] && board[x+1][y-2]->colour() == oppositeColour)
    {
        p.x = x+1;
        p.y = y-2;
        moves.append(p);
    }
    else
    {

    }


    return moves;
}
