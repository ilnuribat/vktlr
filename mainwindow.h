#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QScreen>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
    int getMinutes(QString time);
    int fontSize;
    int w, h;
    void setFontTime(int font);//размер шрифта для чисел
    void setFontOther(int font);//размер шрифта для остальных записей
    void swap(int &a, int &b);
    QString Orientation(Qt::ScreenOrientation orientation);
    QScreen *screen;
    void getScreen(QScreen *Screen)
    {
        this->screen = Screen;
    }
    int firstTime;
    double coeff;

private slots:
    void update_screen();
    void setTime();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
