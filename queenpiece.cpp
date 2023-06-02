#include "queenpiece.h"

QueenPiece::QueenPiece(QWidget *parent, const Board &b, PieceColour clr)
    : ChessPiece(parent, b, clr)
{
    pieceType = Queen;
   // setText(pieceColour == Black ? "Swart\nKoningin" : "Wit\nKoningin");
    setPixmap(pieceColour == Black ? QPixmap("swartKoningin.png").scaled(40, 40) :
                                              QPixmap("witKoningin.png").scaled(40, 40));
}

QList<Position> QueenPiece::possibleMoves()
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

    // Check downward
        for (int i = y + 1; i <= y + 7; i++)
        {
            if (board[x][i] == nullptr)
            {
                p.x = x;
                p.y = i;
                moves.append(p);
            }
            else if (board[x][i]->colour() == oppositeColour) {
                p.x = x;
                p.y = i;
                moves.append(p);
                break;
            }
            else
            {
                break;
            }
        }

        // Check upward
        for (int i = y - 1; i >= y - 7; i--)
        {
            if (board[x][i] == nullptr)
            {
                p.x = x;
                p.y = i;
                moves.append(p);
            }
            else if (board[x][i]->colour() == oppositeColour) {
                p.x = x;
                p.y = i;
                moves.append(p);
                break;
            }
            else
            {
                break;
            }
        }

        // Check rightward
        for (int i = x + 1; i <= x + 7; i++)
        {
             if (board[i][y] == nullptr)
             {
                p.x = i;
                p.y = y;
                moves.append(p);
            } else if (board[i][y]->colour() == oppositeColour) {
                p.x = i;
                p.y = y;
                moves.append(p);
                break;
            }
             else
             {
                break;
             }
        }

        // Check leftward
        for (int i = x - 1; i >= x - 7; i--)
        {
            if (board[i][y] == nullptr)
            {
                p.x = i;
                p.y = y;
                moves.append(p);
            } else if (board[i][y]->colour() == oppositeColour) {
                p.x = i;
                p.y = y;
                moves.append(p);
                break;
            }
            else
            {
                break;
            }
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


  //------------------------------------------------------right down:

       if(board[x+1][y+1] == nullptr)
   {
       p.x = x+1;
       p.y = y+1;
       moves.append(p);

       if(board[x+2][y+2] == nullptr)
       {
           p.x = x+2;
           p.y = y+2;
           moves.append(p);

           if(board[x+3][y+3] == nullptr)
           {
               p.x = x+3;
               p.y = y+3;
               moves.append(p);

               if(board[x+4][y+4] == nullptr)
               {
                   p.x = x+4;
                   p.y = y+4;
                   moves.append(p);

                   if(board[x+5][y+5] == nullptr)
                   {
                       p.x = x+5;
                       p.y = y+5;
                       moves.append(p);

                       if(board[x+6][y+6] == nullptr)
                       {
                           p.x = x+6;
                           p.y = y+6;
                           moves.append(p);

                           if(board[x+7][y+7] == nullptr)
                           {
                               p.x = x+7;
                               p.y = y+7;
                               moves.append(p);
                           }
                       }
                   }
               }
           }
       }
   }
    return moves;
}
