#include "replaygamedialog.h"
#include "ui_replaygamedialog.h"
#include <QDebug>

ReplayGameDialog::ReplayGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplayGameDialog),
    currentMoveIndex(0),
    nextButtonPressCount(0),
    previousButtonPressCount(0)
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
        label->setStyleSheet("border: 1px solid black; font-size: 24px; background-color: #F5F5F5;"); // Styling for visibility
    }

    // Connect the buttons to their respective slots
    connect(ui->pushButton_next, &QPushButton::clicked, this, &ReplayGameDialog::on_pushButton_next_clicked);
    connect(ui->pushButton_previous, &QPushButton::clicked, this, &ReplayGameDialog::on_pushButton_previous_clicked);

    // Set button styles and icons
    ui->pushButton_next->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 10px; padding: 10px; }"
                                       "QPushButton:hover { background-color: #45a049; }");
    ui->pushButton_previous->setStyleSheet("QPushButton { background-color: #F44336; color: white; border-radius: 10px; padding: 10px; }"
                                           "QPushButton:hover { background-color: #D32F2F; }");

    QIcon nextIcon(":/icons/next_icon.png");
    QIcon previousIcon(":/icons/previous_icon.png");

    ui->pushButton_next->setIcon(nextIcon);
    ui->pushButton_next->setIconSize(QSize(24, 24));
    ui->pushButton_previous->setIcon(previousIcon);
    ui->pushButton_previous->setIconSize(QSize(24, 24));
}

ReplayGameDialog::~ReplayGameDialog()
{
    delete ui;
}

void ReplayGameDialog::setGameMoves(const std::vector<std::string>& gameMoves)
{
    moves = gameMoves;
    currentMoveIndex = 0;
    nextButtonPressCount = 0;
    previousButtonPressCount = 0;
    updateBoard();
}

void ReplayGameDialog::on_pushButton_next_clicked()
{
    nextButtonPressCount++;
    if (nextButtonPressCount >= 2) {
        nextButtonPressCount = 0;
        if (currentMoveIndex < moves.size()) {
            currentMoveIndex++;
            updateBoard();
        }
    }
}

void ReplayGameDialog::on_pushButton_previous_clicked()
{
    previousButtonPressCount++;
    if (previousButtonPressCount >= 2) {
        previousButtonPressCount = 0;
        if (currentMoveIndex > 0) {
            currentMoveIndex--;
            updateBoard();
        }
    }
}

void ReplayGameDialog::updateBoard()
{
    qDebug() << "update function start";

    int move[9];

    // Clear the board labels
    for (QLabel *label : boardLabels) {
        label->clear();
    }

    // Display moves up to the current index
    for (int i = 0; i < currentMoveIndex; i++) {
        move[i] = std::stoi(moves[i]); // Store the digit in the array and increment counter
        char playerSymbol = (i % 2 == 0) ? 'X' : 'O';
        boardLabels[move[i]]->setText(QString(playerSymbol));
    }
}
