#ifndef AI_H
#define AI_H

#include <QDialog>

namespace Ui {
class AI;
}

class AI : public QDialog
{
    Q_OBJECT

public:
    explicit AI(QWidget *parent = nullptr);
    ~AI();

private:
    Ui::AI *ui;
};

#endif // AI_H
