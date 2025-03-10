
#include "ui_widget.h"
#include "Datenbank.h"  // Einbinden der Datenbank-Klasse
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), datenbank(new Datenbank())
{
    ui->setupUi(this);

    // Button Click Event verbinden
    connect(ui->eingebenButton, &QPushButton::clicked, this, &Widget::onEingebenClicked);
}

QWidget::~QWidget()
{


}

void QWidget::onEingebenClicked()
{
    QString spielerName = ui->EingabePlainTextEdit->toPlainText(); // Text aus dem QPlainTextEdit

    if (spielerName.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Der Spielername darf nicht leer sein.");
        return;
    }

    // Registriere den Spieler in der "Datenbank"
    if (datenbank->registriereSpieler(spielerName)) {
        ui->statusLabel->setText("Spieler erfolgreich registriert!");
        ui->statusLabel->setStyleSheet("color: green;");  // Erfolg in grün
    } else {
        ui->statusLabel->setText("Spieler existiert bereits.");
        ui->statusLabel->setStyleSheet("color: red;");  // Fehler in rot
    }
}

void Widget::zeigeSpielerInfo(const QString& name)
{
    counter* spieler = datenbank->holeSpieler(name);
    if (spieler) {
        qDebug() << "Spieler Name: " << spieler->getName();
        qDebug() << "Spieler Punkte: " << spieler->getPunkte();
    } else {
        qDebug() << "Spieler nicht gefunden!";
    }
}
