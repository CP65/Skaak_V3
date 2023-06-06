#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QString>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void connectToServer(QString ipAddress, quint16 port);
    void disconnectFromServer();
    void sendData(QByteArray data);

signals:
    void dataReceived(const QByteArray &data);

private slots:
    void handleDataReceived();

private:
    QUdpSocket *udpSocket;
    QString serverAddress;
    quint16 serverPort;
};

#endif // CLIENT_H
