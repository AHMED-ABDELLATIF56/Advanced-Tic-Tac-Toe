#ifndef MEDIUM_H
#define MEDIUM_H

#include <QDialog>
#include <QVector>
#include <QPushButton>

namespace Ui {
class medium;
}

class medium : public QDialog
{
    Q_OBJECT

public:
    explicit medium(QWidget *parent = nullptr);
    ~medium();

private slots:
    void handlePlayerMove(int index);
    void aiMove();
    void checkGameStatus();
    bool checkWinner(char player);
    bool isBoardFull();
    int findBestMove();
    void resetGame();

private:
    Ui::medium *ui;
    QVector<QPushButton*> pushButton_array;
    QVector<char> board;
    bool playerX;

    // These functions are no longer needed, hence commented out in the source file
    // void connectButtons();
    // void disconnectButtons();
};

#endif // MEDIUM_H

