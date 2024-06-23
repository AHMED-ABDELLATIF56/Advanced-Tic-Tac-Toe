#ifndef MEDIUMPLAYER_H
#define MEDIUMPLAYER_H

#include <vector>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class mediumplayer; }
QT_END_NAMESPACE

class mediumplayer : public QDialog
{
    Q_OBJECT

public:
    explicit mediumplayer(QWidget *parent = nullptr);
    ~mediumplayer();

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

private:
    Ui::mediumplayer *ui;
    bool playerX; // Declaration of playerX as a member variable
    void handleButtonClick(QPushButton *button);
    void checkWinCondition();
    void resetGame();
};

#endif // MEDIUMPLAYER_H
