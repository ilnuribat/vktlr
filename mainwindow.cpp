#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDate>
#include <string>
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    setTime();
    firstTime = 0;
    update_screen();
    QTimer *timer;
    timer = new QTimer();
    timer->start(60 * 1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(setTime()));
    coeff = 0.92;//костыль!
}

void MainWindow::init()
{

    int Months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    QString NameOfMonths[12] = {"Января", "Февраля", "Марта", "Апреля", "Мая", "Июня",
                "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря"};
    QFile file(":/data.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString line = stream.readAll();

    file.close();
    QDate qdate;
    qdate = qdate.currentDate();
    int Y = qdate.year(), M = qdate.month(), D = qdate.day();
    int days = 0;
    for(int i = 0; i < M - 1; i++)
        days += Months[i];
    days += D;
    QString date;
    date += Y;
    if(days == 0) days ++;
    QString sline = line.mid(32 * (days - 1), 32);

    QString sbh, sbhf, oyl, iki, ak, yat;
    sbh =sline.left(5);
    sbhf = sline.mid(5, 5);
    oyl = sline.mid(10, 5);
    iki = sline.mid(15,5);
    ak = sline.mid(20, 5);
    yat = sline.mid(25,5);

    ui->sbh->setText(sbh);
    ui->sbhf->setText(sbhf);
    ui->oyl->setText(oyl);
    ui->iki->setText(iki);
    ui->ak->setText(ak);
    ui->yat->setText(yat);
    ui->TodaysDate->setText(NameOfMonths[M - 1]);
    ui->day->setNum(D);
}

int MainWindow::getMinutes(QString time){
    return 60 * time.left(2).toInt() + time.mid(3,2).toInt();
}

void MainWindow::setTime()
{

    QTime qt;
    qt = qt.currentTime();
    int M = qt.minute(), H = qt.hour();

    int currentMin = H * 60 + M;

    int minutes[7];
    minutes[0] = getMinutes(ui->sbh->text());
    minutes[1] = getMinutes(ui->sbhf->text());
    minutes[2] = getMinutes(ui->oyl->text());
    minutes[3] = getMinutes(ui->iki->text());
    minutes[4] = getMinutes(ui->ak->text());
    minutes[5] = minutes[4] + 120;
    minutes[6] = 23 * 60 + minutes[0];//до утреннего сколько осталось

    int i = 0;
    while(currentMin > minutes[i])
        i++;
    int beforeMin = minutes[i] - currentMin;
    int BMin = beforeMin % 60, BH = beforeMin / 60;
    QString bMin, bH;
    bMin.setNum(BMin);
    bH.setNum(BH);

    if(BMin < 10)
        bMin.push_front("0");
    if(BH < 10)
        bH.push_front("0");

    ui->TimeToEnd->setText(bH + ":" + bMin);
}

void MainWindow::update_screen()
{
    w = QApplication::primaryScreen()->availableSize().width();
    h = QApplication::primaryScreen()->availableSize().height();
    double density = QApplication::primaryScreen()->physicalDotsPerInch();
    firstTime ++;
    fontSize = 8 * w / density;
    qDebug() << "Font Size = " << fontSize;
    setFontTime(fontSize);
    fontSize = 6 * w / density;
    setFontOther(fontSize);

    qDebug() << "number of upgrades: " << firstTime;
    qDebug() << "width :" << w << " Height : " << h;
    qDebug() << "Physical_X: " << QApplication::primaryScreen()->physicalDotsPerInchX();
    qDebug() << "Logical_Y: " << QApplication::primaryScreen()->logicalDotsPerInchX();

    if(firstTime == -1){
        ui->gridLayoutWidget->setGeometry(QRect(0, 0, w * coeff, h * coeff));
        ui->fon->setGeometry(QRect(0, 0, w, h));
    }
    else {
        ui->gridLayoutWidget->setGeometry(QRect(0, 0, h * coeff, w * coeff));
        ui->fon->setGeometry(QRect(0, 0, h, w));
    }

    if(firstTime == 2)
        w = h;

    if(w > h)//portrait
    {
        ui->fon->setPixmap(QPixmap("://PortraitCheetah.jpg"));
    }
    else {
        ui->fon->setPixmap(QPixmap("://landScapeCheetah1.jpg"));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFontTime(int font)
{
    ui->ak->setFont(QFont("MS Shell Dlg 2", font));
    ui->iki->setFont(QFont("MS Shell Dlg 2", font));
    ui->yat->setFont(QFont("MS Shell Dlg 2", font));
    ui->sbh->setFont(QFont("MS Shell Dlg 2", font));
    ui->sbhf->setFont(QFont("MS Shell Dlg 2", font));
    ui->oyl->setFont(QFont("MS Shell Dlg 2", font));
    ui->TimeToEnd->setFont(QFont("MS Shell Dlg 2", font));
    ui->TodaysDate->setFont(QFont("MS Shell Dlg 2", font));
    ui->day->setFont(QFont("MS Shell Dlg 2", font));
}

void MainWindow::setFontOther(int font)
{
    ui->label_7->setFont(QFont("MS Shell Dlg 2", font));
    ui->label_8->setFont(QFont("MS Shell Dlg 2", font));
    ui->label_9->setFont(QFont("MS Shell Dlg 2", font));
    ui->label_10->setFont(QFont("MS Shell Dlg 2", font));
    ui->label_11->setFont(QFont("MS Shell Dlg 2", font));
    ui->label_12->setFont(QFont("MS Shell Dlg 2", font));
    ui->label_14->setFont(QFont("MS Shell Dlg 2", font));
    ui->label_17->setFont(QFont("MS Shell Dlg 2", font));
   // ui->exit->setFont(QFont("MS Shell Dlg 2", font));

}

void MainWindow::swap(int &a, int &b)
{
    int p = a;
    a = b;
    b = p;
}

QString MainWindow::Orientation(Qt::ScreenOrientation orientation)
{
    switch (orientation) {
            case Qt::PrimaryOrientation           : return "Primary";
            case Qt::LandscapeOrientation         : return "Landscape";
            case Qt::PortraitOrientation          : return "Portrait";
            case Qt::InvertedLandscapeOrientation : return "Inverted landscape";
            case Qt::InvertedPortraitOrientation  : return "Inverted portrait";
            default                               : return "Unknown";
        }
}
