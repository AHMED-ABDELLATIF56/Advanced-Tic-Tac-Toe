#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(Database *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    database(db)
{
    ui->setupUi(this);

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
