#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h" // Include Database header
#include "dialog.h"   // Include registration dialog header

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void usernameEntered(const QString& username); // Signal to emit the entered username


private slots:
    void on_pushButton_4_clicked(); // Sign-up button clicked
    void on_pushButton_1_clicked(); // Sign-in button clicked
    void handleRegistrationSuccess(); // Slot to handle successful registration

private:
    Ui::MainWindow *ui;
    Database *database; // Database instance
};

#endif // MAINWINDOW_H
