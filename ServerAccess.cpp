#include "ServerAccess.h"

ServerAccess::ServerAccess(QObject *parent) : QObject(parent) {
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &ServerAccess::onReadyRead);
    connect(socket, &QTcpSocket::errorOccurred, this, &ServerAccess::onErrorOccurred);
}

ServerAccess::~ServerAccess() {
    delete socket;
}

void ServerAccess::connectToServer(const QString &host, quint16 port) {
    socket->connectToHost(host, port);
}

void ServerAccess::sendData(const QString &data) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(data.toUtf8());
    }
}

QString ServerAccess::receiveData() {
    return socket->readAll();
}

void ServerAccess::onReadyRead() {
    emit dataReceived(socket->readAll());
}

void ServerAccess::onErrorOccurred(QAbstractSocket::SocketError error) {
    emit connectionError(socket->errorString());
}
