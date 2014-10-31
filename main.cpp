#include <QApplication>
#include <QQmlApplicationEngine>
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    new backEnd();
    return app.exec();
}
