#include <QApplication>
#include <QDebug>
#include "Datenbank.h"
#include "ServerAccess.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

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
        std::cout << "Mikas Score:" << player1->getScore();
    }

    if (player2) {
        player2->addPoints(20);
       std::cout << "Tims Score:" << player2->getScore();
    }

    // Zeige die höchsten Punktestände
    std::cout  << "Persönlicher High Score:" << counter::getpersHighScore();

        // Server verbinden
        ServerAccess server;
    server.connectToServer("127.0.0.1", 12345);

    return app.exec();
}


















