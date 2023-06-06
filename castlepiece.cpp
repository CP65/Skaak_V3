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
