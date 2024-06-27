#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include "gamehistorydialog.h"
#include "twoplayer.h"
#include "aihard.h"
#include "hard1.h"
#include "medium.h"

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT
friend class test ;
public:
    explicit Dialog1(QWidget *parent = nullptr, QString username = "");
    ~Dialog1();

private slots:
    void on_pushButton_two_player_clicked();
    void on_pushButton_AI_easy_clicked();
    void on_pushButton_AI_medium_clicked();
    void on_pushButton_AI_hard_clicked();
    void on_pushButton_viewHistory_clicked();

private:
    Ui::Dialog1 *ui;
    QString username;
    twoplayer *twoPlayerWindow;
    aihard *aiHardWindow;
    medium *mediumWindow;
    hard1 *hardWindow;
    GameHistoryDialog *gameHistory;
};

#endif // DIALOG1_H
