#include "game.h"
#include "result.h"
#include "mainwindow.h"
#include <stdlib.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
