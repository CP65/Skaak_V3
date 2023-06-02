#include "bishoppiece.h"

BishopPiece::BishopPiece(QWidget *parent, const Board &b, PieceColour clr)
    : ChessPiece(parent, b, clr)
{
    pieceType = Bishop;
    //setText(pieceColour == Black ? "Swart\nLoper" : "Wit\nLoper");
    setPixmap(pieceColour == Black ? QPixmap("swartLoper.png").scaled(40, 40) :
                                          QPixmap("witLoper.png").scaled(40, 40));
}

QList<Position> BishopPiece::possibleMoves()
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

    //----------------------------------------------regs af:
    for(int i = 1; i <= 7; i++)
    {
       if(board[x+i][y+i] == nullptr)
       {
           p.x = x+i;
           p.y = y+i;
           moves.append(p);
       }
       else if(board[x+i][y+i]->colour() == oppositeColour)
       {
           p.x = x+i;
           p.y = y+i;
           moves.append(p);
           break;
       }
       else
       {
           break;
       }
    }

   //----------------------------------------------regs op:
    for(int i = 1; i <= 7; i++)
    {
       if(board[x+i][y-i] == nullptr)
       {
           p.x = x+i;
           p.y = y-i;
           moves.append(p);
       }
       else if(board[x+i][y-i]->colour() == oppositeColour)
       {
           p.x = x+i;
           p.y = y-i;
           moves.append(p);
           break;
       }
       else
       {
           break;
       }
    }


    //----------------------------------------------links af:
     for(int i = 1; i <= 7; i++)
     {
        if(board[x-i][y+i] == nullptr)
        {
            p.x = x-i;
            p.y = y+i;
            moves.append(p);
        }
        else if(board[x-i][y+i]->colour() == oppositeColour)
        {
            p.x = x-i;
            p.y = y+i;
            moves.append(p);
            break;
        }
        else
        {
            break;
        }
     }


     //----------------------------------------------links op:
      for(int i = 1; i <= 7; i++)
      {
         if(board[x-i][y-i] == nullptr)
         {
             p.x = x-i;
             p.y = y-i;
             moves.append(p);
         }
         else if(board[x-i][y-i]->colour() == oppositeColour)
         {
             p.x = x-i;
             p.y = y-i;
             moves.append(p);
             break;
         }
         else
         {
             break;
         }
      }



    return moves;
}
