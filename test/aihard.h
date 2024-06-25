#ifndef AIHARD_H
#define AIHARD_H

#include <QDialog>
#include <QPushButton>
#include <QVector>

namespace Ui {
class aihard;
}

class aihard : public QDialog
{
    Q_OBJECT
    friend class TestPlayer;
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
    bool playerX; // true for Player X, false for Player O
};

#endif // AIHARD_H
