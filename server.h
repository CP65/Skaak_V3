#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QStringList>
#include <QSet>

class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

public slots:
    void readPendingDatagrams();

private:
    QUdpSocket *socket;
    QStringList moves;
    QSet<QHostAddress> connectedClients;
};

#endif // SERVER_H
