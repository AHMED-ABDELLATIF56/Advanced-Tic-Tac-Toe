#ifndef PLAYERMAKEMOVE_H
#define PLAYERMAKEMOVE_H

#include <QDialog>

namespace Ui {
class playerMakeMove;
}

class playerMakeMove : public QDialog
{
    Q_OBJECT

public:
    explicit playerMakeMove(QWidget *parent = nullptr);
    ~playerMakeMove();

private:
    Ui::playerMakeMove *ui;
};

#endif // PLAYERMAKEMOVE_H
