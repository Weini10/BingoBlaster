#ifndef OVERLAY_H
#define OVERLAY_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

const int SIZE = 5; // Größe des Gitters

class Overlay : public QWidget {
    Q_OBJECT

public:
    explicit Overlay(QWidget *parent = nullptr);
    void generateNumbers();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    int grid[SIZE][SIZE];    // Gitter mit Zahlen
    bool marked[SIZE][SIZE]; // Markierte Zellen
    int score;               // Punktzahl

    void checkForBonus(); // Prüft vollständige Reihen und Spalten für Bonuspunkte
};

#endif // OVERLAY_H
