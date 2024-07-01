#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Dialog1::Dialog1(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::Dialog1),
    username(username),
    twoPlayerWindow(nullptr),
    aiHardWindow(nullptr),
    mediumWindow(nullptr),
    hardWindow(nullptr),
    gameHistory(nullptr)
{
    ui->setupUi(this);



    // Set stylesheets for buttons
    ui->pushButton_two_player->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 10px; padding: 10px; }"
                                             "QPushButton:hover { background-color: #45a049; }");
    ui->pushButton_AI_hard->setStyleSheet("QPushButton { background-color: #FF5722; color: white; border-radius: 10px; padding: 10px; }"
                                          "QPushButton:hover { background-color: #E64A19; }");
    ui->pushButton_AI_easy->setStyleSheet("QPushButton { background-color: #FFC107; color: white; border-radius: 10px; padding: 10px; }"
                                          "QPushButton:hover { background-color: #FFB300; }");
    ui->pushButton_AI_medium->setStyleSheet("QPushButton { background-color: #03A9F4; color: white; border-radius: 10px; padding: 10px; }"
                                            "QPushButton:hover { background-color: #0288D1; }");
    ui->pushButton_history->setStyleSheet("QPushButton { background-color: #9E9E9E; color: white; border-radius: 10px; padding: 10px; }"
                                          "QPushButton:hover { background-color: #757575; }");

    // Set icon for buttons
    QIcon twoPlayerIcon(":/new/prefix1/icons/two_player_icon.png");
    QIcon aiEasyIcon(":/new/prefix1/icons/ai_easy_icon.jpg");
    QIcon aiMediumIcon(":/new/prefix1/icons/ai_easy_icon.jpg");
    QIcon aiHardIcon(":/new/prefix1/icons/ai_easy_icon.jpg");
    QIcon historyIcon(":/new/prefix1/icons/history_icon.png");

    ui->pushButton_two_player->setIcon(twoPlayerIcon);
    ui->pushButton_two_player->setIconSize(QSize(24, 24));
    ui->pushButton_AI_easy->setIcon(aiEasyIcon);
    ui->pushButton_AI_easy->setIconSize(QSize(24, 24));
    ui->pushButton_AI_medium->setIcon(aiMediumIcon);
    ui->pushButton_AI_medium->setIconSize(QSize(24, 24));
    ui->pushButton_AI_hard->setIcon(aiHardIcon);
    ui->pushButton_AI_hard->setIconSize(QSize(24, 24));
    ui->pushButton_history->setIcon(historyIcon);
    ui->pushButton_history->setIconSize(QSize(24, 24));

    // Connect buttons to slots
    connect(ui->pushButton_two_player, &QPushButton::clicked, this, &Dialog1::on_pushButton_two_player_clicked);
    connect(ui->pushButton_AI_hard, &QPushButton::clicked, this, &Dialog1::on_pushButton_AI_hard_clicked);
    connect(ui->pushButton_AI_easy, &QPushButton::clicked, this, &Dialog1::on_pushButton_AI_easy_clicked);
    connect(ui->pushButton_AI_medium, &QPushButton::clicked, this, &Dialog1::on_pushButton_AI_medium_clicked);
    connect(ui->pushButton_history, &QPushButton::clicked, this, &Dialog1::on_pushButton_viewHistory_clicked);
}

Dialog1::~Dialog1()
{
    delete ui;
    if (twoPlayerWindow) delete twoPlayerWindow;
    if (aiHardWindow) delete aiHardWindow;
    if (mediumWindow) delete mediumWindow;
    if (hardWindow) delete hardWindow;
    if (gameHistory) delete gameHistory;
}

void Dialog1::on_pushButton_two_player_clicked()
{
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (mainWindow) {
        QString username = mainWindow->getUsername();
        if (!twoPlayerWindow) {
            twoPlayerWindow = new twoplayer(this, username);
        }
    }
    twoPlayerWindow->show();
    twoPlayerWindow->raise();
    twoPlayerWindow->activateWindow();
}

void Dialog1::on_pushButton_AI_easy_clicked()
{
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (mainWindow) {
        QString username = mainWindow->getUsername();
        if (!aiHardWindow) {
            aiHardWindow = new aihard(this, username);
        }
    }
    aiHardWindow->show();
    aiHardWindow->raise();
    aiHardWindow->activateWindow();
}

void Dialog1::on_pushButton_AI_medium_clicked()
{
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (mainWindow) {
        QString username = mainWindow->getUsername();
        if (!mediumWindow) {
            mediumWindow = new medium(this, username);
        }
    }
    mediumWindow->show();
    mediumWindow->raise();
    mediumWindow->activateWindow();
}

void Dialog1::on_pushButton_AI_hard_clicked()
{
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (mainWindow) {
        QString username = mainWindow->getUsername();
        if (!hardWindow) {
            hardWindow = new hard1(this, username);
        }
    }
    hardWindow->show();
    hardWindow->raise();
    hardWindow->activateWindow();
}

void Dialog1::on_pushButton_viewHistory_clicked()
{
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    if (mainWindow) {
        QString username = mainWindow->getUsername();
        gameHistory = new GameHistoryDialog(this, username);
    }
    gameHistory->show();
    gameHistory->raise();
    gameHistory->activateWindow();
}
