#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QScreen *scr;
    scr = a.primaryScreen();
    //w.getScreen(a.primaryScreen());
    QObject::connect(scr, SIGNAL(geometryChanged(QRect)), &w, SLOT(update_screen()));

    return a.exec();
}
