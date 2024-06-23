// aimedium.cpp

#include "aimedium.h"
#include "ui_aimedium.h"
#include <QPushButton>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

AImedium::AImedium(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AImedium)
{
    ui->setupUi(this);
    board = std::vector<char>(9, ' '); // Initialize board with empty spaces

    // Connect all push buttons to their respective slots
    connect(ui->pushButton, &QPushButton::clicked, this, &AImedium::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &AImedium::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &AImedium::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &AImedium::on_pushButton_4_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &AImedium::on_pushButton_5_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &AImedium::on_pushButton_6_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &AImedium::on_pushButton_7_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &AImedium::on_pushButton_8_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &AImedium::on_pushButton_9_clicked);

    // Seed random number generator for AI move
    std::srand(std::time(nullptr));
}

AImedium::~AImedium()
{
    delete ui;
}

void AImedium::on_pushButton_clicked()
{
     handleButtonClick(ui->pushButton);
}


void AImedium::on_pushButton_2_clicked()
{
     handleButtonClick(ui->pushButton_2);
}


void AImedium::on_pushButton_3_clicked()
{
     handleButtonClick(ui->pushButton_3);
}


void AImedium::on_pushButton_4_clicked()
{
     handleButtonClick(ui->pushButton_4);
}


void AImedium::on_pushButton_5_clicked()
{
     handleButtonClick(ui->pushButton_5);
}


void AImedium::on_pushButton_6_clicked()
{
     handleButtonClick(ui->pushButton_6);
}


void AImedium::on_pushButton_7_clicked()
{
    handleButtonClick(ui->pushButton_7);
}


void AImedium::on_pushButton_8_clicked()
{
     handleButtonClick(ui->pushButton_8);
}


void AImedium::on_pushButton_9_clicked()
{
     handleButtonClick(ui->pushButton_9);
}

