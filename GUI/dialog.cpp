#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QIcon>

Dialog::Dialog(Database *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    database(db)
{
    ui->setupUi(this);



    // Set stylesheets for line edits
    ui->lineEdit_username->setStyleSheet("QLineEdit { border: 2px solid #4CAF50; border-radius: 5px; padding: 5px; }");
    ui->lineEdit_password->setStyleSheet("QLineEdit { border: 2px solid #4CAF50; border-radius: 5px; padding: 5px; }");

    // Set stylesheets for buttons
    ui->pushButton_accept->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 10px; padding: 10px; }"
                                         "QPushButton:hover { background-color: #45a049; }");
    ui->pushButton_cancel->setStyleSheet("QPushButton { background-color: #f44336; color: white; border-radius: 10px; padding: 10px; }"
                                         "QPushButton:hover { background-color: #e53935; }");

    // Set icon for accept button
    QIcon acceptIcon(":/new/prefix1/icons/register.png");
    ui->pushButton_accept->setIcon(acceptIcon);
    ui->pushButton_accept->setIconSize(QSize(24, 24));

    // Connect accept and cancel buttons
    connect(ui->pushButton_accept, &QPushButton::clicked, this, &Dialog::onAcceptClicked);
    connect(ui->pushButton_cancel, &QPushButton::clicked, this, &Dialog::onCancelClicked);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onAcceptClicked()
{
    QString username = ui->lineEdit_username->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Registration", "Username and password cannot be empty.");
        return;
    }

    // Attempt to sign up user using Database class
    if (database->signUp(username, password)) {
        emit registrationSuccess();
        accept(); // Close the dialog
    } else {
        QMessageBox::warning(this, "Registration", "Failed to register user. Username may already exist.");
    }
}

void Dialog::onCancelClicked()
{
    reject(); // Close the dialog without registration
}
