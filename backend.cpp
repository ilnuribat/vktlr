#include "backend.h"

backEnd::backEnd(QQuickItem *parent) :
    QQuickItem(parent)
{
    NameOfMonths.push_back("index=0");
    NameOfMonths.push_back("Января");
    NameOfMonths.push_back("Февраля");
    NameOfMonths.push_back("Марта");
    NameOfMonths.push_back("Апреля");
    NameOfMonths.push_back("Мая");
    NameOfMonths.push_back("Июня");
    NameOfMonths.push_back("Июля");
    NameOfMonths.push_back("Августа");
    NameOfMonths.push_back("Сентября");
    NameOfMonths.push_back("Октября");
    NameOfMonths.push_back("Ноября");
    NameOfMonths.push_back("Декабря");
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    mainWindow = engine.rootObjects().value(0);
    listTimes = mainWindow->findChild<QObject*>("listTimes");
    toolTime = mainWindow->findChild<QObject*>("toolTime");
    tillTheEnd = mainWindow->findChild<QObject*>("tillTheEnd");
    qDate = qDate.currentDate();
    init();
    set6Times();
    setTillTheEnd();
}

/*
 * инициализиция, проставление даты
*/
void backEnd::init()
{
    toolTime->setProperty("text", QString(QString::number(qDate.day()) + " " + NameOfMonths[qDate.month()]));
}

void backEnd::set6Times()
{
    QFile file(":/data.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString allLines = stream.readAll();
    file.close();
    int currentDay = qDate.dayOfYear();
    QString sline = allLines.mid(32 * (currentDay - 1), 32);
    QVariantMap map;
    map.insert("time", sline.left(5));
    map.insert("name", "Начало 1");
    QMetaObject::invokeMethod(listTimes, "append", Q_ARG(QVariant, QVariant::fromValue(map)));\
    times.push_back(sline.left(5));
    for(int i = 1; i < 6; i ++)
    {
        times.push_back(sline.mid(i * 5, 5));
        map.insert("time", sline.mid(i * 5, 5));
        map.insert("name", i != 1 ? (QString("Начало ") + QString::number(i)) : "Конец 1");
        QMetaObject::invokeMethod(listTimes, "append", Q_ARG(QVariant, QVariant::fromValue(map)));
    }
}

int backEnd::convert(QString str)
{
    QString h = str.left(2), m = str.right(2);
    return h.toInt() * 60 + m.toInt();
}

void backEnd::setTillTheEnd()
{
    QTime qTime = QTime::currentTime();
    int minutesFromStartOfDay = qTime.msecsSinceStartOfDay() / 60000;
    QVector<int> timesINT;
    for(int i = 0; i < 6; i ++)
    {
        timesINT.push_back(convert(times[i]));
    }

    //Примерно следующее утро
    timesINT.push_back(timesINT[0] + 24*60);

    //Выравнивание. Последний полет летом после полуночи наступает
    if(timesINT[5] < timesINT[4])
        timesINT[5] += 60*24;
    int i = 0;
    while(minutesFromStartOfDay > timesINT[i])
        i ++;
    int mtillTheEnd = timesINT[i] - minutesFromStartOfDay;
    QString hours = "", mins = "";
    if(mtillTheEnd / 60 < 10) hours = "0";
    if(mtillTheEnd % 60 < 10) mins = "0";
    QString shour = QString::number(mtillTheEnd / 60), smin = QString::number(mtillTheEnd % 60);
    hours.append(shour);
    mins.append(smin);
    tillTheEnd->setProperty("text", hours + ":" + mins);
    //QString(QString::number(mtillTheEnd / 60) + ":" + QString::number(mtillTheEnd % 60)));
}
