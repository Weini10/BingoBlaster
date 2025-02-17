#ifndef OVERLAY_H
#define OVERLAY_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <vector>

class Overlay : public QWidget {
    Q_OBJECT
private:
    static const int SIZE = 3;
    int grid[SIZE][SIZE];
    bool marked[SIZE][SIZE] = {false};

public:
    Overlay(QWidget *parent = nullptr);
    void generateNumbers();
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // OVERLAY_H
