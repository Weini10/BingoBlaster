#pragma once;
#include <iostream>
#include <QString>

class counter
{
private:
    QString playerName;
    int score;
    static int pershighScore;
    static QMap<QString, int> globalhighScore;
public:
    explicit counter(const QString& name);

    void addPoints(int points);
    int getScore() const;
    static int getpersHighScore();
    static void updatepersHighScore(int newScore);
    static void updateGlobalhighScore(const QString& name, int score);
    static int getGlobalhighScore(const QString& name);

};
