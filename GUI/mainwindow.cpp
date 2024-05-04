//mainwindow.cpp

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>

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

<<<<<<< Updated upstream
void MainWindow::on_pushButton_4_clicked()
{
    // Assuming `Dialog` is the registration dialog
    Dialog *dialog = new Dialog(this);
    dialog->show();
}

void MainWindow::on_pushButton_1_clicked()
=======
void MainWindow::on_pushButton_login_clicked()
>>>>>>> Stashed changes
{
    QString username=ui->lineEdit_username->text();
     QString password=ui->lineEdit_password->text();
    if (username=="text"&&password=="text"){

         QMessageBox::information(this,"login","user name and password are correct");
         hide();
         dialog=new Dialog(this);
         dialog->show();
     }
    else
         QMessageBox::warning(this,"login","user name and password are not correct");


}
