#include "rankings.h"
#include <iostream>
using namespace std;

Rankings::Rankings()
{
    //cout << "Constructor: skryf iets\n";
    scoresFile.setFileName("Leaderboard.txt");
    if (scoresFile.open(QIODevice::ReadOnly))
    {
        //cout << "Constructor: file open\n";
        while (!scoresFile.atEnd())
        {
            QByteArray line = scoresFile.readLine().trimmed();
            int pos = line.indexOf("\t");
            if (pos != -1)
            {
                QByteArray p1 = line.mid(0, pos);
                QByteArray p2 = line.mid(pos+1);
                //cout << "Constructor read line: " << p1.toStdString() << " " << p2.toStdString() << endl;
                scores.insert(p1.toInt(), p2);
            }
        }
    }
    scoresFile.close();
}

void Rankings::addScore(QByteArray naam, int punt)
{
    scores.insert(punt, naam);

    if (scoresFile.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        //cout << "addScore: file open\n";
        int n = 1;
        QMapIterator<int, QByteArray> i(scores);
        i.toBack();
        while (i.hasPrevious())
        {
            i.previous();
            QByteArray line;
            line.append(QByteArray::number(i.key()));
            line.append("\t");
            line.append(i.value());
            line.append("\n");
            scoresFile.write(line);
            if (n >= 10)
                break;

            ++n;
        }
    }
    scoresFile.close();
}
