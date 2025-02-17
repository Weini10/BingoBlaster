#include "Overlay.h"
#include <QRandomGenerator>

Overlay::Overlay(QWidget *parent) : QWidget(parent) {
    generateNumbers();
}

void Overlay::generateNumbers() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = QRandomGenerator::global()->bounded(1, 100);
        }
    }
}

void Overlay::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.setPen(Qt::black);

    int cellSize = width() / SIZE;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            QRect rect(j * cellSize, i * cellSize, cellSize, cellSize);
            painter.drawRect(rect);

            if (marked[i][j]) {
                painter.fillRect(rect, Qt::blue);
            }
            painter.drawText(rect, Qt::AlignCenter, QString::number(grid[i][j]));
        }
    }
}

void Overlay::mousePressEvent(QMouseEvent *event) {
    int cellSize = width() / SIZE;
    int row = event->y() / cellSize;
    int col = event->x() / cellSize;

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        marked[row][col] = !marked[row][col];
        update();
    }
}





