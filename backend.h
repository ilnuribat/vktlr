#ifndef BACKEND_H
#define BACKEND_H

#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QDate>
#include <QTime>
#include <qvector.h>
#include <QFile>
#include <QTextStream>

class backEnd : public QQuickItem
{
    Q_OBJECT
public:
    explicit backEnd(QQuickItem *parent = 0);

private:
    QQmlApplicationEngine engine;
    QObject * mainWindow;
    QObject * listTimes;
    QObject *toolTime;
    QObject *tillTheEnd;
    void init();
    QVector<QString> NameOfMonths;
    QVector<QString> times;
    void setTillTheEnd();
    void set6Times();
    QDate qDate;
    int convert(QString str);
signals:

public slots:

};

#endif // BACKEND_H
