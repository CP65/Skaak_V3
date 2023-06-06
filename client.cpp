#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, &QUdpSocket::readyRead, this, &Client::handleDataReceived);
}

void Client::connectToServer(QString ipAddress, quint16 port)
{
    serverAddress = ipAddress;
    serverPort = port;
}

void Client::sendData(QByteArray data)
{
    udpSocket->writeDatagram(data, QHostAddress(serverAddress), serverPort);
}

void Client::disconnectFromServer()
{
    // No need to explicitly disconnect from a UDP server
}

void Client::handleDataReceived()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        emit dataReceived(datagram);
    }
}

// Add the following line to the client.cpp file
Q_DECLARE_METATYPE(QByteArray)
