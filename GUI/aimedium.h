
// aimedium.h
#include "medium.h"
#ifndef AIMEDIUM_H
#define AIMEDIUM_H

#include <QDialog>
#include <vector>


#include <QPushButton>
namespace Ui {
class AImedium;
}

class AImedium : public QDialog {
    Q_OBJECT

public:
    explicit AImedium(QWidget *parent = nullptr);
    ~AImedium();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

private:
    Ui::AImedium *ui;
    std::vector<char> board;
   // medium aiPlayer=medium('o'); // Instance of medium class for AI moves

    void handleButtonClick(QPushButton *button);
    void updateBoardState(int position, char symbol);
    bool checkForWin(char symbol);
    bool checkForDraw();
    void makeMove(); // Declaration of makeMove function
};

#endif // AIMEDIUM_H
