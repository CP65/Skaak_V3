#include "castlepiece.h"

CastlePiece::CastlePiece(QWidget *parent, const Board &b, PieceColour clr)
    : ChessPiece(parent, b, clr)
{
    pieceType = Castle;
    //setText(pieceColour == Black ? "Swart\nKasteel" : "Wit\nKasteel");
    setPixmap(pieceColour == Black ? QPixmap("swartKasteel.png").scaled(40, 40) :
                                          QPixmap("witKasteel.png").scaled(40, 40));
}

QList<Position> CastlePiece::possibleMoves()
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

 /*
 //-------------------------------------------------------------checks down:

//     if(board[x][y+1]->colour() == oppositeColour)
//     {
//         p.x = x;
//         p.y = y+1;
//         moves.append(p);
//     }

//     else if(board[x][y+1]->colour() == pieceColour)
//     {

//     }

//        else if(board[x][y+1] == nullptr)
//        {
//            p.x = x;
//            p.y = y+1;
//            moves.append(p);
//            if(board[x][y+2]->colour() == oppositeColour)
//            {
//                p.x = x;
//                p.y = y+2;
//                moves.append(p);
//            }
//            else if(board[x][y+2]->colour() == pieceColour)
//            {

//            }

//            else if(board[x][y+2] == nullptr)
//            {
//                p.x = x;
//                p.y = y+2;
//                moves.append(p);
//                if(board[x][y+3]->colour() == oppositeColour)
//                {
//                    p.x = x;
//                    p.y = y+3;
//                    moves.append(p);
//                }
//                else if(board[x][y+3]->colour() == pieceColour)
//                {

//                }

//                else if(board[x][y+3] == nullptr)
//                {
//                    p.x = x;
//                    p.y = y+3;
//                    moves.append(p);
//                    if(board[x][y+4]->colour() == oppositeColour)
//                    {
//                        p.x = x;
//                        p.y = y+4;
//                        moves.append(p);
//                    }
//                    else if(board[x][y+4]->colour() == pieceColour)
//                    {

//                    }

//                    else if(board[x][y+4] == nullptr)
//                    {
//                        p.x = x;
//                        p.y = y+4;
//                        moves.append(p);
//                        if(board[x][y+5]->colour() == oppositeColour)
//                        {
//                            p.x = x;
//                            p.y = y+5;
//                            moves.append(p);
//                        }
//                        else if(board[x][y+5]->colour() == pieceColour)
//                        {

//                        }

//                        else if(board[x][y+5] == nullptr)
//                        {
//                            p.x = x;
//                            p.y = y+5;
//                            moves.append(p);
//                            if(board[x][y+6]->colour() == oppositeColour)
//                            {
//                                p.x = x;
//                                p.y = y+6;
//                                moves.append(p);
//                            }
//                            else if(board[x][y+6]->colour() == pieceColour)
//                            {

//                            }

//                            else if(board[x][y+6] == nullptr)
//                            {
//                                p.x = x;
//                                p.y = y+6;
//                                moves.append(p);
//                                if(board[x][y+7]->colour() == oppositeColour)
//                                {
//                                    p.x = x;
//                                    p.y = y+7;
//                                    moves.append(p);
//                                }
//                                else if(board[x][y+7]->colour() == pieceColour)
//                                {

//                                }

//                                else if(board[x][y+7] == nullptr)
//                                {
//                                    p.x = x;
//                                    p.y = y+7;
//                                    moves.append(p);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }

////---------------------------------------------------------------checks up:
//     if(board[x][y-1]->colour() == oppositeColour)
//     {
//         p.x = x;
//         p.y = y-1;
//         moves.append(p);
//     }
//     else if(board[x][y-1]->colour() == pieceColour)
//     {

//     }

//        else if (board[x][y-1] == nullptr)
//        {
//            p.x = x;
//            p.y = y-1;
//            moves.append(p);
//            if(board[x][y-2]->colour() == oppositeColour)
//            {
//                p.x = x;
//                p.y = y-2;
//                moves.append(p);
//            }
//            else if(board[x][y-2]->colour() == pieceColour)
//            {

//            }

//            else if(board[x][y-2] == nullptr)
//            {
//                p.x = x;
//                p.y = y-2;
//                moves.append(p);
//                if(board[x][y-3]->colour() == oppositeColour)
//                {
//                    p.x = x;
//                    p.y = y-3;
//                    moves.append(p);
//                }
//                else if(board[x][y-3]->colour() == pieceColour)
//                {

//                }

//                else if(board[x][y-3] == nullptr)
//                {
//                    p.x = x;
//                    p.y = y-3;
//                    moves.append(p);
//                    if(board[x][y-4]->colour() == oppositeColour)
//                    {
//                        p.x = x;
//                        p.y = y-4;
//                        moves.append(p);
//                    }
//                    else if(board[x][y-4]->colour() == pieceColour)
//                    {

//                    }

//                    else if(board[x][y-4] == nullptr)
//                    {
//                        p.x = x;
//                        p.y = y-4;
//                        moves.append(p);
//                        if(board[x][y-5]->colour() == oppositeColour)
//                        {
//                            p.x = x;
//                            p.y = y-5;
//                            moves.append(p);
//                        }
//                        else if(board[x][y-5]->colour() == pieceColour)
//                        {

//                        }

//                        else if(board[x][y-5] == nullptr)
//                        {
//                            p.x = x;
//                            p.y = y-5;
//                            moves.append(p);
//                            if(board[x][y-6]->colour() == oppositeColour)
//                            {
//                                p.x = x;
//                                p.y = y-6;
//                                moves.append(p);
//                            }
//                            else if(board[x][y-6]->colour() == pieceColour)
//                            {

//                            }

//                            else if(board[x][y-6] == nullptr)
//                            {
//                                p.x = x;
//                                p.y = y-6;
//                                moves.append(p);
//                                if(board[x][y-7]->colour() == oppositeColour)
//                                {
//                                    p.x = x;
//                                    p.y = y-7;
//                                    moves.append(p);
//                                }
//                                else if(board[x][y-7]->colour() == pieceColour)
//                                {

//                                }

//                                else if(board[x][y-7] == nullptr)
//                                {
//                                    p.x = x;
//                                    p.y = y-7;
//                                    moves.append(p);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }


////---------------------------------------------------------------checks left:
//     if(board[x-1][y]->colour() == oppositeColour)
//          {
//              p.x = x-1;
//              p.y = y;
//              moves.append(p);
//          }
//     else if(board[x-1][y]->colour() == pieceColour)
//     {

//     }

//             else if (board[x-1][y] == nullptr)
//             {
//                 p.x = x-1;
//                 p.y = y;
//                 moves.append(p);
//                 if(board[x-2][y]->colour() == oppositeColour)
//                 {
//                     p.x = x-2;
//                     p.y = y;
//                     moves.append(p);
//                 }
//                 else if(board[x-2][y]->colour() == pieceColour)
//                 {

//                 }

//                 else if(board[x-2][y] == nullptr)
//                 {
//                     p.x = x-2;
//                     p.y = y;
//                     moves.append(p);
//                     if(board[x-3][y]->colour() == oppositeColour)
//                     {
//                         p.x = x-3;
//                         p.y = y;
//                         moves.append(p);
//                     }
//                     else if(board[x-3][y]->colour() == pieceColour)
//                     {

//                     }

//                     else if(board[x-3][y] == nullptr)
//                     {
//                         p.x = x-3;
//                         p.y = y;
//                         moves.append(p);
//                         if(board[x-4][y]->colour() == oppositeColour)
//                         {
//                             p.x = x-4;
//                             p.y = y;
//                             moves.append(p);
//                         }
//                         else if(board[x-4][y]->colour() == pieceColour)
//                         {

//                         }

//                         else if(board[x-4][y] == nullptr)
//                         {
//                             p.x = x-4;
//                             p.y = y;
//                             moves.append(p);
//                             if(board[x-5][y]->colour() == oppositeColour)
//                             {
//                                 p.x = x-5;
//                                 p.y = y;
//                                 moves.append(p);
//                             }
//                             else if(board[x-5][y]->colour() == pieceColour)
//                             {

//                             }

//                             else if(board[x-5][y] == nullptr)
//                             {
//                                 p.x = x-5;
//                                 p.y = y;
//                                 moves.append(p);
//                                 if(board[x-6][y]->colour() == oppositeColour)
//                                 {
//                                     p.x = x-6;
//                                     p.y = y;
//                                     moves.append(p);
//                                 }
//                                 else if(board[x-6][y]->colour() == pieceColour)
//                                 {

//                                 }

//                                 else if(board[x-6][y] == nullptr)
//                                 {
//                                     p.x = x-6;
//                                     p.y = y;
//                                     moves.append(p);
//                                     if(board[x-7][y]->colour() == oppositeColour)
//                                     {
//                                         p.x = x-7;
//                                         p.y = y;
//                                         moves.append(p);
//                                     }
//                                     else if(board[x-7][y]->colour() == pieceColour)
//                                     {

//                                     }

//                                     else if(board[x-7][y] == nullptr)
//                                     {
//                                         p.x = x-7;
//                                         p.y = y;
//                                         moves.append(p);
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }

////---------------------------------------------------------------checks right:

//     if(board[x+1][y]->colour() == oppositeColour)
//          {
//              p.x = x+1;
//              p.y = y;
//              moves.append(p);
//          }
//     else if(board[x+1][y]->colour() == pieceColour)
//     {

//     }

//             else if (board[x+1][y] == nullptr)
//             {
//                 p.x = x+1;
//                 p.y = y;
//                 moves.append(p);
//                 if(board[x+2][y]->colour() == oppositeColour)
//                 {
//                     p.x = x+2;
//                     p.y = y;
//                     moves.append(p);
//                 }
//                 else if(board[x+2][y]->colour() == pieceColour)
//                 {

//                 }

//                 else if(board[x+2][y] == nullptr)
//                 {
//                     p.x = x+2;
//                     p.y = y;
//                     moves.append(p);
//                     if(board[x+3][y]->colour() == oppositeColour)
//                     {
//                         p.x = x+3;
//                         p.y = y;
//                         moves.append(p);
//                     }
//                     else if(board[x+3][y]->colour() == pieceColour)
//                     {

//                     }

//                     else if(board[x+3][y] == nullptr)
//                     {
//                         p.x = x+3;
//                         p.y = y;
//                         moves.append(p);
//                         if(board[x+4][y]->colour() == oppositeColour)
//                         {
//                             p.x = x+4;
//                             p.y = y;
//                             moves.append(p);
//                         }
//                         else if(board[x+4][y]->colour() == pieceColour)
//                         {

//                         }

//                         else if(board[x+4][y] == nullptr)
//                         {
//                             p.x = x+4;
//                             p.y = y;
//                             moves.append(p);
//                             if(board[x+5][y]->colour() == oppositeColour)
//                             {
//                                 p.x = x+5;
//                                 p.y = y;
//                                 moves.append(p);
//                             }
//                             else if(board[x+5][y]->colour() == pieceColour)
//                             {

//                             }

//                             else if(board[x+5][y] == nullptr)
//                             {
//                                 p.x = x+5;
//                                 p.y = y;
//                                 moves.append(p);
//                                 if(board[x+6][y]->colour() == oppositeColour)
//                                 {
//                                     p.x = x+6;
//                                     p.y = y;
//                                     moves.append(p);
//                                 }
//                                 else if(board[x+6][y]->colour() == pieceColour)
//                                 {

//                                 }

//                                 else if(board[x+6][y] == nullptr)
//                                 {
//                                     p.x = x+6;
//                                     p.y = y;
//                                     moves.append(p);
//                                     if(board[x+7][y]->colour() == oppositeColour)
//                                     {
//                                         p.x = x+7;
//                                         p.y = y;
//                                         moves.append(p);
//                                     }
//                                     else if(board[x+7][y]->colour() == pieceColour)
//                                     {

//                                     }

//                                     else if(board[x+7][y] == nullptr)
//                                     {
//                                         p.x = x+7;
//                                         p.y = y;
//                                         moves.append(p);
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }








//        if (board[x-1][y+1] && (board[x-1][y+1]->colour() == White))
//        {
//            p.x = x-1;
//            p.y = y+1;
//            moves.append(p);
//        }
//        if (board[x+1][y+1] && (board[x+1][y+1]->colour() == White))
//        {
//            p.x = x+1;
//            p.y = y+1;
//            moves.append(p);
//        }
//        if (timesMoved == 0)
//        {
//            if (board[x][y+2] == nullptr)
//            {
//                p.x = x;
//                p.y = y+2;
//                moves.append(p);
//            }
//            if (board[x-1][y+2] && (board[x-1][y+2]->colour() == White))
//            {
//                p.x = x-1;
//                p.y = y+2;
//                moves.append(p);
//            }
//            if (board[x+1][y+2] && (board[x+1][y+2]->colour() == White))
//            {
//                p.x = x+1;
//                p.y = y+2;
//                moves.append(p);
//            }
//        }
*/

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


    return moves;
}
