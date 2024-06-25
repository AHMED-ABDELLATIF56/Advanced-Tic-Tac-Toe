#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "dialog.h" // Include registration dialog header
#include "login.h" // Assuming Dialog1 is your main application window/dialog after login

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize Database instance with the path to the users file
    database = new Database("users.txt", this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    // Open registration dialog (Dialog)
    Dialog dialog(database); // Pass Database instance to dialog constructor
    connect(&dialog, &Dialog::registrationSuccess, this, &MainWindow::handleRegistrationSuccess);
    if (dialog.exec() == QDialog::Accepted) {
        qDebug() << "Registration dialog closed.";
    } else {
        qDebug() << "Registration cancelled or failed.";
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Attempt to sign in with provided username and password
    if (database->signIn(username, password)) {
        // Sign-in successful, open main application window (Dialog1)
        Dialog1 *dialog1 = new Dialog1(this);
        dialog1->show();
        hide(); // Hide the login window
    } else {
        // Sign-in failed, show error message
        QMessageBox::warning(this, "Login", "Username and password are not correct");
    }
}

void MainWindow::handleRegistrationSuccess()
{
    qDebug() << "Registration successful!";
    // Handle post-registration logic here if needed
}
