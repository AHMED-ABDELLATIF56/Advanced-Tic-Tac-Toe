#ifndef REPLAYGAMEDIALOG_H
#define REPLAYGAMEDIALOG_H

#include <QDialog>
#include <vector>
#include <string>
#include <QLabel>

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

private:
    Ui::ReplayGameDialog *ui;
    std::vector<QLabel*> boardLabels; // Vector to hold references to the QLabel objects
};

#endif // REPLAYGAMEDIALOG_H
