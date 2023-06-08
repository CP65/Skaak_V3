#include "chessgame.h"
#include "rankings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Rankings r;
    ChessGame w;
    w.show();

    return a.exec();
}
