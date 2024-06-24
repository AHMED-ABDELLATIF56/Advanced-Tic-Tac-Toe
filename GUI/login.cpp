#include "login.h"
#include "ui_login.h"
#include "twoplayer.h"
#include "aihard.h"
#include "hard1.h"

Dialog1::Dialog1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog1)
    , twoPlayerWindow(nullptr) // Initialize the member variable
    , aiHardWindow(nullptr)    // Initialize the member variable
    , hardWindow(nullptr)      // Initialize the member variable
{
    ui->setupUi(this);
    connect(ui->pushButton_two_player, &QPushButton::clicked, this, &Dialog1::on_pushButton_two_player_clicked);
    connect(ui->pushButton_AI_hard, &QPushButton::clicked, this, &Dialog1::on_pushButton_AI_hard_clicked);
    connect(ui->pushButton_AI_easy, &QPushButton::clicked, this, &Dialog1::on_pushButton_AI_easy_clicked);

    // Initialize the board
    board = std::vector<char>(9, ' ');
}

Dialog1::~Dialog1()
{
    delete ui;
    if (twoPlayerWindow) {
        delete twoPlayerWindow; // Ensure the window is deleted when Dialog1 is destroyed
    }
    if (aiHardWindow) {
        delete aiHardWindow; // Ensure the window is deleted when Dialog1 is destroyed
    }
    if (hardWindow) {
        delete hardWindow; // Ensure the window is deleted when Dialog1 is destroyed
    }
}

void Dialog1::on_pushButton_two_player_clicked()
{
    if (!twoPlayerWindow) { // Only create a new window if it doesn't exist
        twoPlayerWindow = new twoplayer(this);
    }
    twoPlayerWindow->show();
    twoPlayerWindow->raise(); // Bring the window to the front
    twoPlayerWindow->activateWindow(); // Give the window focus
}

void Dialog1::on_pushButton_AI_easy_clicked()
{
    if (!aiHardWindow) { // Only create a new window if it doesn't exist
        aiHardWindow = new aihard(this);
    }
    aiHardWindow->show();
    aiHardWindow->raise(); // Bring the window to the front
    aiHardWindow->activateWindow(); // Give the window focus
}

void Dialog1::on_pushButton_AI_hard_clicked()
{
    if (!hardWindow) { // Only create a new window if it doesn't exist
        hardWindow = new hard1(this);
    }
    hardWindow->show();
    hardWindow->raise(); // Bring the window to the front
    hardWindow->activateWindow(); // Give the window focus
}


void Dialog1::on_pushButton_history_clicked()
{
    // History button logic (if any)
}

