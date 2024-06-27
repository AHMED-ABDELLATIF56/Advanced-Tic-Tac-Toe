// gamehistorydialog.h
#ifndef GAMEHISTORYDIALOG_H
#define GAMEHISTORYDIALOG_H

#include <QDialog>
#include <QString>
#include "database.h"

namespace Ui {
class GameHistoryDialog;
}

class GameHistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameHistoryDialog(QWidget *parent = nullptr, QString username = "");
    ~GameHistoryDialog();

private slots:
    void on_pushButton_viewHistory_clicked();
    void on_pushButton_replayGame_clicked();

private:
    Ui::GameHistoryDialog *ui;
    QString username;
    GameHistory *gameHistory;
    QString movesToString(const std::vector<std::string>& moves);
    void setupUIComponents();
    void displayHistory(const QString& username);
    std::string removeCommas(const std::string& movesString);
    int replayButtonPressCount;
};

#endif // GAMEHISTORYDIALOG_H
