#include "twoplayer.h"
#include "ui_twoplayer.h"

twoplayer::twoplayer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::twoplayer)
{
    ui->setupUi(this);
}

twoplayer::~twoplayer()
{
    delete ui;
}
