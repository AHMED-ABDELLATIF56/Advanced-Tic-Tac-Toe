#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include "database.h" // Include your database header
#include "dialog.h"   // Include registration dialog header
#include "login.h"    // Assuming Dialog1 is your main application window/dialog after login

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getUsername() const;

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_1_clicked();
    void handleRegistrationSuccess();

private:
    Ui::MainWindow *ui;
    Database *database;
    QLabel *logoLabel; // Declare QLabel for logo

    // You can add more private members or methods as needed
};

#endif // MAINWINDOW_H
