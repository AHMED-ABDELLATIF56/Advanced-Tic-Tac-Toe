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

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void handleButtonClick(QPushButton *button);
    void checkWinCondition();
    void resetGame();

private:
    Ui::twoplayer *ui;
    bool playerX;

    void disconnectButtons();
    void connectButtons();
};

#endif // TWOPLAYER_H
