#include "counter.h"
#include <QCoreApplication>
#include <QDebug>

using namespace std;
int counter::pershighScore = 0;
QMap<QString, int> counter::globalhighScore;

counter::counter(const QString& name) : playerName(name), score(0) {}

void counter::addPoints(int points) {
    score += points;
    if (score > pershighScore) {
        updatepersHighScore(score);
    }
    updateGlobalhighScore(playerName, score);
}

int counter::getScore() const {
    return score;
}

int counter::getpersHighScore() {
    return pershighScore;
}

void counter::updatepersHighScore(int newScore) {
    pershighScore = newScore;
}

void counter::updateGlobalhighScore(const QString& name, int score) {
    globalhighScore[name] = score;
}

int counter::getGlobalhighScore(const QString& name) {
    return globalhighScore.value(name, 0);
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    counter player1("Mika"); // 41 und 42 durch die logins zu ersetzen
    counter player2("Tim");

    player1.addPoints(10); // 44,45,46 nur bespiele: müssen natürlich von außen bespielbar sein
    player2.addPoints(20);
    player1.addPoints(15);

    qDebug() << "Mikas Score:" << player1.getScore();
    qDebug() << "Tims Score:" << player2.getScore();
    qDebug() << "Persöhnlicher High Score:" << counter::getpersHighScore();
    cout << "Mikas Score:" << player1.getScore();
    cout << "Tims Score:" << player2.getScore();
    cout << "Persöhnlicher High Score:" << counter::getpersHighScore();

                                           return a.exec();
}
