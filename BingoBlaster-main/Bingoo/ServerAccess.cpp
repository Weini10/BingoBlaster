#include "ServerAccess.h"
#include <QDebug>

ServerAccess::ServerAccess(QObject *parent) : QObject(parent), socket(new QTcpSocket(this)) {
    connect(socket, &QTcpSocket::readyRead, this, &ServerAccess::onServerResponse);
}

void ServerAccess::connectToServer(const QString &host, quint16 port) {
    socket->connectToHost(host, port);
    if (!socket->waitForConnected(3000)) {
        qDebug() << "Verbindung fehlgeschlagen:" << socket->errorString();
    } else {
        qDebug() << "Erfolgreich mit Server verbunden.";
    }
}

void ServerAccess::sendPlayerRegistration(const QString &playerName) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QByteArray data = "REGISTER:" + playerName.toUtf8();
        socket->write(data);
    } else {
        qDebug() << "Nicht mit Server verbunden!";
    }
}

void ServerAccess::requestPlayerData(const QString &playerName) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QByteArray data = "GET_PLAYER:" + playerName.toUtf8();
        socket->write(data);
    } else {
        qDebug() << "Nicht mit Server verbunden!";
    }
}

void ServerAccess::onServerResponse() {
    QByteArray response = socket->readAll();
    qDebug() << "Antwort vom Server:" << response;
}
