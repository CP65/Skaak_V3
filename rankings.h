#ifndef RANKINGS_H
#define RANKINGS_H
#include <QMap>
#include <QByteArray>
#include <QFile>

class Rankings
{
public:
    Rankings();
    void addScore(QByteArray, int);
    QMultiMap<int, QByteArray> scores;
    QFile scoresFile;

private:

};

#endif // RANKINGS_H
