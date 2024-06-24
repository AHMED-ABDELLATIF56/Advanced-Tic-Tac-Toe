#ifndef AIHARD_H
#define AIHARD_H

#include <QDialog>
#include <QVector>
#include <QPushButton>

namespace Ui {
class aihard;
}

class aihard : public QDialog
{
    Q_OBJECT

public:
    explicit aihard(QWidget *parent = nullptr);
    ~aihard();

private slots:
    void handlePlayerMove(int index);
    void aiMove();
    void checkGameStatus();
    bool checkWinner(char player);
    bool isBoardFull();
    int findBestMove();
    void resetGame();

private:
    Ui::aihard *ui;
    QVector<QPushButton*> pushButton_array;
    QVector<char> board;
    bool playerX;

    void connectButtons();
    void disconnectButtons();
};

#endif // AIHARD_H


