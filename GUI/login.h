#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <vector>
#include "database.h"
#include "gamehistory.h"

namespace Ui {
class Dialog1;
}

class twoplayer; // Forward declaration
class aihard;
class hard1;
class medium;

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
public slots:
    void setUsername(const QString& username); // Slot to receive username


private slots:
    void on_pushButton_two_player_clicked();
    void on_pushButton_AI_hard_clicked();
    void on_pushButton_AI_easy_clicked();
    void on_pushButton_AI_medium_clicked();
    void on_pushButton_viewHistory_clicked(const QString& username);

private:
    Ui::Dialog1 *ui;
    twoplayer *twoPlayerWindow; // Add this line
    aihard *aiHardWindow;       // Add this line
    hard1 *hardWindow;          // Add this line
    medium *mediumWindow;          // Add this line
    std::vector<char> board;
    GameHistory *gameHistory;
};

#endif // LOGIN_H


