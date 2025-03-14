#include "Datenbank.h"
#include <QDebug>

Datenbank::~Datenbank() {
    // Speicher aufräumen, da wir die counter-Objekte auf der Heap-Allokierung erstellt haben
    qDeleteAll(spielerDaten);
}

bool Datenbank::registriereSpieler(const QString& name) {
    if (spielerExistiert(name)) {
        qDebug() << "Spieler mit dem Namen" << name << "existiert bereits!";
        return false;
    }

    // Einen neuen counter für den Spieler erstellen und zur Datenbank hinzufügen
    spielerDaten[name] = new counter(name);
    return true;
}

counter* Datenbank::holeSpieler(const QString& name) {
    if (spielerExistiert(name)) {
        return spielerDaten.value(name);
    }
    qDebug() << "Spieler" << name << "nicht gefunden!";
    return nullptr;
}

bool Datenbank::spielerExistiert(const QString& name) const {
    return spielerDaten.contains(name);
}
