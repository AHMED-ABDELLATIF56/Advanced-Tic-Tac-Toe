//login.cpp
#include "login.h"
#include "ui_login.h"
#include <QMainWindow>
#include "twoplayer.h"
#include "aihard.h"
#include "ui_aihard.h"
#include "hard1.h"
#include "ui_hard1.h"

Dialog1::Dialog1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    connect(ui->pushButton_two_player, &QPushButton::clicked, this, &Dialog1::on_pushButton_two_player_clicked);

    connect(ui->pushButton_AI_hard, &QPushButton::clicked, this, &Dialog1::on_pushButton_AI_hard_clicked);
    connect(ui->pushButton_AI_easy, &QPushButton::clicked, this, &Dialog1::on_pushButton_AI_easy_clicked);


    // Initialize the board
    board = std::vector<char>(9, ' ');
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
    hard1 *Hard1 = new hard1(this);
    Hard1->show();

}




void Dialog1::on_pushButton_AI_easy_clicked()
{
    aihard *Aihard = new aihard(this);
    Aihard->show();
}





void Dialog1::on_pushButton_history_clicked()
{

}

