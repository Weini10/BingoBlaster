#include <QApplication>
#include "Overlay.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Overlay overlay;
    overlay.resize(500, 500);
    overlay.show();
    return app.exec();
}
