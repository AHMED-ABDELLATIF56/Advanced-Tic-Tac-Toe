#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"Dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
<<<<<<< Updated upstream

    void on_pushButton_4_clicked();

    void on_pushButton_1_clicked();

=======
    void on_pushButton_login_clicked();
>>>>>>> Stashed changes

private:
    Ui::MainWindow *ui;
   Dialog*dialog;
};
#endif // MAINWINDOW_H
