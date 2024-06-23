#ifndef BOARD1_H
#define BOARD1_H

#include <QDialog>

namespace Ui {
class board1;
}

class board1 : public QDialog
{
    Q_OBJECT

public:
    explicit board1(QWidget *parent = nullptr);
    ~board1();

private:
    Ui::board1 *ui;
};

#endif // BOARD1_H
