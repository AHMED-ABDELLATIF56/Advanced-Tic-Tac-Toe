#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

#include <vector>
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:


    void on_pushButton_two_player_clicked();

    void on_pushButton_AI_hard_clicked();

    void on_pushButton_AI_easy_clicked();

    void on_pushButton_history_clicked();

private:
    Ui::Dialog1 *ui;
    std::vector<char> board;
};

#endif // LOGIN_H

