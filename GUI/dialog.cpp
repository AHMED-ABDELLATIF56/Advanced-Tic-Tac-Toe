#include "dialog.h"
#include "ui_dialog.h"
#include <QMainWindow>
#include<QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_label_linkActivated(const QString &link)
{

}

void Dialog::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if (username=="text"&&password=="text"){

        QMessageBox::information(this,"login","user name and password are correct");
        hide();
    }}

