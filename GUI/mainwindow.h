
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

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

    void on_pushButton_4_clicked();

    void on_pushButton_login_2_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
   Dialog*dialog;
};

