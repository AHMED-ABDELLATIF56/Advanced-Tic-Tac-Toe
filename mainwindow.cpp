//mainwindow.cpp

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    // Assuming `Dialog` is the registration dialog
    Dialog *dialog = new Dialog(this);
    dialog->show();
}

void MainWindow::on_pushButton_1_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "text" && password == "text") {
        // Assuming `Dialog1` is the main application window/dialog after login
        Dialog1 *dialog1 = new Dialog1(this);
        dialog1->show();
        hide(); // Hide the login window
    } else {
        QMessageBox::warning(this, "Login", "Username and password are not correct");
    }
}



