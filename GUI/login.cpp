//login.cpp
#include "login.h"
#include "ui_login.h"
#include <QMainWindow>
#include "twoplayer.h"
Dialog1::Dialog1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog1)
{
    ui->setupUi(this);
   connect(ui->pushButton_two_player, &QPushButton::clicked, this, &Dialog1::on_pushButton_two_player_clicked);
}

Dialog1::~Dialog1()
{
    delete ui;
}






void Dialog1::on_pushButton_two_player_clicked()
{   twoplayer *Twoplayer = new twoplayer(this);
    Twoplayer->show();
}


void Dialog1::on_pushButton_AI_hard_clicked()
{

}


void Dialog1::on_pushButton_AI_medium_clicked()
{

}


void Dialog1::on_pushButton_AI_easy_clicked()
{

}




void Dialog1::on_pushButton_history_clicked()
{

}

