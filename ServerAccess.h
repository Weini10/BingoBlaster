#ifndef SERVERACCESS_H
#define SERVERACCESS_H

#include <QTcpSocket>
#include <QObject>

class ServerAccess : public QObject {
    Q_OBJECT
    
private:
    QTcpSocket *socket;
    
public:
    explicit ServerAccess(QObject *parent = nullptr);
    ~ServerAccess();
    
    void connectToServer(const QString &host, quint16 port);
    void sendData(const QString &data);
    QString receiveData();
    
signals:
    void dataReceived(const QString &data);
    void connectionError(const QString &error);
    
private slots:
    void onReadyRead();
    void onErrorOccurred(QAbstractSocket::SocketError error);
};

#endif // SERVERACCESS_H
