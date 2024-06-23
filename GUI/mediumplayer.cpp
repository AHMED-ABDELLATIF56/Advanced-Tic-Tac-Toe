#include "mediumplayer.h"
#include "mediumplayer.h"

mediumplayer::mediumplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediumplayer),
    playerX(true)

mediumplayer::~mediumplayer() {
    delete ui;
}
