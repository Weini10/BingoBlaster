// Datenbank.h
#pragma once
#include <QString>
#include <QMap>
#include "counter.h"

class Datenbank {
private:
    QMap<QString, counter*> spielerDaten;

public:
    Datenbank() = default;
    ~Datenbank();

    bool registriereSpieler(const QString& name);
    counter* holeSpieler(const QString& name);
    bool spielerExistiert(const QString& name) const;
};
