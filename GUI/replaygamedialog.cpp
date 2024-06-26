#include "replaygamedialog.h"
#include "ui_replaygamedialog.h"

ReplayGameDialog::ReplayGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplayGameDialog)
{
    ui->setupUi(this);

    // Add references to the QLabel objects to the boardLabels vector
    boardLabels = {
        ui->label_1, ui->label_2, ui->label_3,
        ui->label_4, ui->label_5, ui->label_6,
        ui->label_7, ui->label_8, ui->label_9
    };

    // Optional: clear any existing text in the labels
    for (QLabel *label : boardLabels) {
        label->clear();
        label->setFixedSize(50, 50); // Set fixed size for labels
        label->setAlignment(Qt::AlignCenter); // Center-align text
        // Styling for visibility
        label->setStyleSheet("border: 1px solid black; font-size: 24px;");

    }
}

ReplayGameDialog::~ReplayGameDialog()
{
    delete ui;
}

void ReplayGameDialog::setGameMoves(const std::vector<std::string>& moves)
{
    qDebug() << "Setting game moves with size:" << moves.size();

    // Clear the board labels
    for (QLabel *label : boardLabels) {
        label->clear();
    }

    // Display all moves on the board
    for (int i = 0; i < moves.size(); ++i) {
        if (i >= boardLabels.size()) {
            qDebug() << "More moves than available labels. Cannot display all moves.";
            break;
        }

        const std::string& move = moves[i];

        if (move == "-") {
            continue; // Skip empty moves or moves that are just "-"
        }

        char player = move[0]; // 'X' or 'O'

        // Set text on the label corresponding to current move index
        boardLabels[i]->setText(QString(player));
    }
}



