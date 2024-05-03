#ifndef TWOPLAYER_H
#define TWOPLAYER_H

#include <QDialog>

namespace Ui {
class twoplayer;
}

class twoplayer : public QDialog
{
    Q_OBJECT

public:
    explicit twoplayer(QWidget *parent = nullptr);
    ~twoplayer();

private:
    Ui::twoplayer *ui;
};

#endif // TWOPLAYER_H
