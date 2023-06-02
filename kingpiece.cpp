#include "kingpiece.h"

KingPiece::KingPiece(QWidget *parent, const Board &b, PieceColour clr)
    : ChessPiece(parent, b, clr)
{
    pieceType = King;
    //setText(pieceColour == Black ? "Swart\nKoning" : "Wit\nKoning");
    setPixmap(pieceColour == Black ? QPixmap("swartKoning.png").scaled(40, 40) :
                                              QPixmap("witKoning.png").scaled(40, 40));

}

QList<Position> KingPiece::possibleMoves()
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

    // Op
    if (board[x][y+1] == nullptr)
    {
        p.x = x;
        p.y = y+1;
        moves.append(p);
    }
    else if(board[x][y+1]->colour() == oppositeColour)
    {
        p.x = x;
        p.y = y+1;
        moves.append(p);
    }
    else
    {

    }

    // Af
    if (board[x][y-1] == nullptr)
    {
        p.x = x;
        p.y = y-1;
        moves.append(p);
    }
    else if(board[x][y-1]->colour() == oppositeColour)
    {
        p.x = x;
        p.y = y-1;
        moves.append(p);
    }
    else
    {

    }

    // Regs
    if (board[x+1][y] == nullptr)
    {
        p.x = x+1;
        p.y = y;
        moves.append(p);
    }
    else if(board[x+1][y]->colour() == oppositeColour)
    {
        p.x = x+1;
        p.y = y;
        moves.append(p);
    }
    else
    {

    }

    // Links
    if (board[x-1][y] == nullptr)
    {
        p.x = x-1;
        p.y = y;
        moves.append(p);
    }
    else if(board[x-1][y]->colour() == oppositeColour)
      {
          p.x = x-1;
          p.y = y;
          moves.append(p);
      }
      else
      {

      }

    // Regs af
    if (board[x+1][y+1] == nullptr)
    {
        p.x = x+1;
        p.y = y+1;
        moves.append(p);
    }
    else if(board[x+1][y+1]->colour() == oppositeColour)
      {
          p.x = x+1;
          p.y = y+1;
          moves.append(p);
      }
      else
      {

      }

    // Regs op
    if (board[x+1][y-1] == nullptr)
    {
        p.x = x+1;
        p.y = y-1;
        moves.append(p);
    }
    else if(board[x+1][y-1]->colour() == oppositeColour)
      {
          p.x = x+1;
          p.y = y-1;
          moves.append(p);
      }
      else
      {

      }

    // Links af
    if (board[x-1][y+1] == nullptr)
    {
        p.x = x-1;
        p.y = y+1;
        moves.append(p);
    }
    else if(board[x-1][y+1]->colour() == oppositeColour)
      {
          p.x = x-1;
          p.y = y+1;
          moves.append(p);
      }
      else
      {

      }

    // Links op
    if (board[x-1][y-1] == nullptr)
    {
        p.x = x-1;
        p.y = y-1;
        moves.append(p);
    }
    else if(board[x-1][y-1]->colour() == oppositeColour)
      {
          p.x = x-1;
          p.y = y-1;
          moves.append(p);
      }
      else
      {

      }

    return moves;
}
