#ifndef REPLAYGAMEDIALOG_H
#define REPLAYGAMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <vector>
#include <string>

namespace Ui {
class ReplayGameDialog;
}

class ReplayGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplayGameDialog(QWidget *parent = nullptr);
    ~ReplayGameDialog();
    void setGameMoves(const std::vector<std::string>& moves);

private slots:
    void on_pushButton_next_clicked();
    void on_pushButton_previous_clicked();

private:
    Ui::ReplayGameDialog *ui;
    std::vector<QLabel*> boardLabels;
    std::vector<std::string> moves;
    int currentMoveIndex;
    int nextButtonPressCount;
    int previousButtonPressCount;
    void updateBoard();
};

#endif // REPLAYGAMEDIALOG_H
