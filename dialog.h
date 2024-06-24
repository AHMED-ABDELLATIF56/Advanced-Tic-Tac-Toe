#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_label_linkActivated(const QString &link);
    void on_pushButton_clicked();
    void on_Dialog_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
