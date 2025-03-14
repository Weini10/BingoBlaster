#ifndef SERVERACCESS_H
#define SERVERACCESS_H

#include <QTcpSocket>
#include <QObject>

class ServerAccess : public QObject {
    Q_OBJECT

public:
    explicit ServerAccess(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);
    void sendPlayerRegistration(const QString &playerName);
    void requestPlayerData(const QString &playerName);

private slots:
    void onServerResponse();

private:
    QTcpSocket *socket;
};

#endif // SERVERACCESS_H
