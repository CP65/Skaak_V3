#include "server.h"
#include <QDebug>

Server::Server(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::Any, 7755);
    connect(socket, &QUdpSocket::readyRead, this, &Server::readPendingDatagrams);
}

Server::~Server()
{
}

void Server::readPendingDatagrams()
{
    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        qDebug() << "Received data from: " << sender.toString();

        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        // Process the received move and update the chess game
        // processMove(datagram);

        // Store the move in the list of moves
        moves.append(datagram);

        // Add the sender's address to the set of connected clients
        connectedClients.insert(sender);

        // Broadcast the move to all connected clients
        foreach (const QHostAddress &address, connectedClients) {
            socket->writeDatagram(datagram, address, senderPort);
        }
    }
}
