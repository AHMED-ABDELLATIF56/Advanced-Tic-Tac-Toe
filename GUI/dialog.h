#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "database.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(Database *db, QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void onAcceptClicked();
    void onCancelClicked();

signals:
    void registrationSuccess();

private:
    Ui::Dialog *ui;
    Database *database;
};

#endif // DIALOG_H
