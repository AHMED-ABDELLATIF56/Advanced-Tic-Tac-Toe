#ifndef TWOPLAYER_H
#define TWOPLAYER_H

#include <QDialog>
#include <QPushButton>
#include <vector>
#include <QString>
#include <array>
#include <QVector>

namespace Ui {
class twoplayer;
}

class twoplayer : public QDialog
{
    Q_OBJECT
friend class test ;
public:
    explicit twoplayer(QWidget *parent = nullptr,QString username = "");
    ~twoplayer();

private slots:
    void handlePlayerMove(int index);

private:
    Ui::twoplayer *ui;
    QString username;
    bool playerX;
    std::array<QPushButton*, 9> pushButton_array;
    QVector<char> board;

    void checkGameStatus();
    bool checkWinner(char player);
    bool isBoardFull();
    void resetGame();
    void connectButtons();
    void disconnectButtons();
    void saveGameHistory(const QString& username);

};

#endif // TWOPLAYER_H
