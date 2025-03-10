#include <QApplication>
#include "Overlay.h"
#include <QDebug>
#include "counter.h"
#include "Datenbank.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Overlay overlay;
    overlay.resize(500, 500);
    overlay.show();
    return app.exec();

    QCoreApplication a(argc, argv);

    // Erstelle eine Instanz der Datenbank
    Datenbank db;

    // Registriere zwei Spieler
    db.registriereSpieler("Mika");
    db.registriereSpieler("Tim");

    // Hole die Spieler-Objekte
    counter* player1 = db.holeSpieler("Mika");
    counter* player2 = db.holeSpieler("Tim");

    if (player1) {
        player1->addPoints(10);
        qDebug() << "Mikas Score:" << player1->getScore();
    }

    if (player2) {
        player2->addPoints(20);
        qDebug() << "Tims Score:" << player2->getScore();
    }

    // Zeige die höchsten Punktestände
    qDebug() << "Persönlicher High Score:" << counter::getpersHighScore();

                                              return a.exec();
}


















