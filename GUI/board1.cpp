#include "board1.h"
#include "ui_board1.h"

board1::board1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::board1)
{
    ui->setupUi(this);
}

board1::~board1()
{
    delete ui;
}
