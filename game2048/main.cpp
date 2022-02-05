#include "game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game w;
    w.setFixedSize(500,580);
    w.setWindowTitle("2048");
   w.setWindowIcon(QIcon(":/new/prefix1/artboard_-_2048"));
   w.show();    return a.exec();
}
