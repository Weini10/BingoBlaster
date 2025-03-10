#ifndef widget_H
#define widget_H
#pragma once
#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void onEingebenClicked();// Slot für den Login-Button
    void zeigeSpielerInfo();
private:
    Ui::widget *ui;

    bool isValidServerID(const QString &serverID);  // Methode zur Server ID Validierung
};

#endif // widget_H
