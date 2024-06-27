#include "login.h"
#include "ui_login.h"
#include "twoplayer.h"
#include "aihard.h"
#include "medium.h"
#include "hard1.h"
#include "gamehistorydialog.h"
#include "database.h"
#include "mainwindow.h"
#include <QDebug>

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
{ MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
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
{ MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
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
{ MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
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
{MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());

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
