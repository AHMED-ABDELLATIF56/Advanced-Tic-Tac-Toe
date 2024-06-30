#include "ai.h"
#include "ui_ai.h"

AI::AI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AI)
{
    ui->setupUi(this); 
}

AI::~AI()
{
    delete ui;
