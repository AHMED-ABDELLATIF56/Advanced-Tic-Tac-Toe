#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug> // Include for qDebug statements

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set window title and icon
    setWindowTitle("My Application");
    setWindowIcon(QIcon(":/icons/app_icon.png"));

    // Initialize Database instance with the path to the users file
    database = new Database("users.txt", this);


    // Set icons for buttons
    ui->pushButton_1->setIcon(QIcon(":/new/prefix1/icons/login.png"));
    ui->pushButton_4->setIcon(QIcon(":/new/prefix1/icons/register.png"));

    // Apply stylesheets for buttons and line edits
    ui->pushButton_1->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 10px; }"
                                    "QPushButton:hover { background-color: #45a049; }");

    ui->pushButton_4->setStyleSheet("QPushButton { background-color: #008CBA; color: white; border-radius: 10px; }"
                                    "QPushButton:hover { background-color: #0073aa; }");

    ui->lineEdit_username->setStyleSheet("QLineEdit { border: 2px solid #4CAF50; border-radius: 5px; padding: 2px; }");

    ui->lineEdit_password->setStyleSheet("QLineEdit { border: 2px solid #008CBA; border-radius: 5px; padding: 2px; }");

    // Debugging output
    qDebug() << "MainWindow initialized.";
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

QString MainWindow::getUsername() const
{
    return ui->lineEdit_username->text();
}
