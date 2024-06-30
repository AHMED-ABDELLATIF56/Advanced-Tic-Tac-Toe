#ifndef MEDIUM_H
#define MEDIUM_H

#include <QDialog>
#include <QVector>
#include <QPushButton>
#include "database.h"

namespace Ui {
class medium;
}

class medium : public QDialog
{
    Q_OBJECT
    friend class test;
public:
    explicit medium(QWidget *parent = nullptr,QString username = "");
    ~medium();

private slots:
    void handlePlayerMove(int index);
    void aiMove();
    void checkGameStatus();
    bool checkWinner(char player);
    bool isBoardFull();
    int findBestMove();
    void resetGame();
    void saveGameHistory(const QString& username);
private:
    Ui::medium *ui;
     QString username;
    QVector<QPushButton*> pushButton_array;
    QVector<char> board;
    bool playerX;
     Database *database;
};

#endif // MEDIUM_H

