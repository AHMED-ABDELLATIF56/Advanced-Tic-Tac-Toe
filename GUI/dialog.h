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
friend class test ;
public:
    explicit Dialog(Database *db, QWidget *parent = nullptr);
    ~Dialog();

signals:
    void registrationSuccess();

private slots:
    void onAcceptClicked();
    void onCancelClicked();

private:
    Ui::Dialog *ui;
    Database *database;
};

#endif // DIALOG_H
