#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>

class Widget : public QWidget {
    Q_OBJECT

private:
    QTcpSocket *socket;

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void connectToServer(const QString &host, quint16 port);
    void sendPlayerRegistration(const QString &playerName);
    void requestPlayerData(const QString &playerName);

private slots:
    void onServerResponse();
};

#endif // WIDGET_H
