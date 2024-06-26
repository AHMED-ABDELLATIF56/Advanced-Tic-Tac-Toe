#include "mainwindow.h"
#include "twoplayer.h"
#include "login.h"
#include <QApplication>
#include <QElapsedTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QElapsedTimer timer;

    // Measure application initialization time
    timer.start();
    QApplication a(argc, argv);
    qint64 initTime = timer.elapsed();
    qDebug() << "Application initialization took" << initTime << "milliseconds";

    // Measure MainWindow creation and show time
    timer.restart();
    MainWindow w;
    w.show();
    qint64 mainWindowTime = timer.elapsed();
    qDebug() << "MainWindow creation and show took" << mainWindowTime << "milliseconds";

    // Execute the application
    return a.exec();
}
