#ifndef SERVERACCESS_H
#define SERVERACCESS_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>

class ServerAccess : public QWidget {
    Q_OBJECT

private:
    QTcpSocket *socket;

public:
    explicit ServerAccess(QWidget *parent = nullptr);
    ~ServerAccess();

    void connectToServer(const QString &host, quint16 port);
    void sendPlayerRegistration(const QString &playerName);
    void requestPlayerData(const QString &playerName);

private slots:
    void onServerResponse();
};

#endif // SERVERACCESS_H
