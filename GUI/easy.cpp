// easy.cpp
/*#include "easy.h"
#include "ui_easy.h"
#include <vector>
#include <cstdlib>

easy::easy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::easy)
{
    ui->setupUi(this);

    // Connect all push buttons to their respective slots
    connect(ui->pushButton, &QPushButton::clicked, this, &easy::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &easy::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &easy::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &easy::on_pushButton_4_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &easy::on_pushButton_5_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &easy::on_pushButton_6_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &easy::on_pushButton_7_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &easy::on_pushButton_8_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &easy::on_pushButton_9_clicked);


}

easy::~easy()
{
    delete ui;
}



void easy::on_pushButton_clicked()
{
    handleButtonClick(ui->pushButton);
}

void easy::on_pushButton_2_clicked()
{
    handleButtonClick(ui->pushButton_2);
}

void easy::on_pushButton_3_clicked()
{
    handleButtonClick(ui->pushButton_3);
}

void easy::on_pushButton_4_clicked()
{
    handleButtonClick(ui->pushButton_4);
}

void easy::on_pushButton_5_clicked()
{
    handleButtonClick(ui->pushButton_5);
}

void easy::on_pushButton_6_clicked()
{
    handleButtonClick(ui->pushButton_6);
}

void easy::on_pushButton_7_clicked()
{
    handleButtonClick(ui->pushButton_7);
}

void easy::on_pushButton_8_clicked()
{
    handleButtonClick(ui->pushButton_8);
}

void easy::on_pushButton_9_clicked()
{
    handleButtonClick(ui->pushButton_9);
}

void easy::handleButtonClick(QPushButton *button)
{
    if (button) {
        // Check if the button is empty
        if (button->text().isEmpty()) {
            // Set the button text based on the current player
            button->setText(playerX ? "X" : "O");

            // Check win condition after each move
            checkWinCondition();

            // Toggle player turn
            playerX = !playerX;
        }
    }
}

void easy::checkWinCondition()
{
    // Horizontal check
    for (int i = 0; i < 3; ++i) {
        // Cast the widgets to QPushButton before accessing text()
        QPushButton* button1 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, 0)->widget());
        QPushButton* button2 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, 1)->widget());
        QPushButton* button3 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, 2)->widget());

        if (button1 && button2 && button3 &&
            button1->text() == button2->text() &&
            button1->text() == button3->text() &&
            !button1->text().isEmpty()) {
            QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(button1->text()));
            resetGame();
            return;
        }
    }

    // Vertical check
    for (int i = 0; i < 3; i++) {
        // Cast the widgets to QPushButton before accessing text()
        QPushButton* button1 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0, i)->widget());
        QPushButton* button2 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(1, i)->widget());
        QPushButton* button3 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(2, i)->widget());

        if (button1 && button2 && button3 &&
            button1->text() == button2->text() &&
            button1->text() == button3->text() &&
            !button1->text().isEmpty()) {
            QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(button1->text()));
            resetGame();
            return;
        }
    }

    // Diagonal check
    QPushButton* button02 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0, 2)->widget());
    QPushButton* button11 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(1, 1)->widget());
    QPushButton* button20 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(2, 0)->widget());

    if (button02 && button11 && button20 &&
        button02->text() == button11->text() &&
        button02->text() == button20->text() &&
        !button02->text().isEmpty()) {
        QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(button02->text()));
        resetGame();
        return;
    }


    // Check for a draw
    bool draw = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QWidget* widget = ui->gridLayout->itemAtPosition(i, j)->widget();
            if (QPushButton* button = qobject_cast<QPushButton*>(widget)) {
                if (button->text().isEmpty()) {
                    draw = false;
                    break;
                }
            }
        }
    }
    if (draw) {
        QMessageBox::information(this, "Game Over", "It's a draw!");
        resetGame();
    }

}

void easy::resetGame()
{
    // Clear button texts
    for (int i = 0; i < ui->gridLayout->rowCount(); ++i) {
        for (int j = 0; j < ui->gridLayout->columnCount(); ++j) {
            QPushButton* button = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            if (button) {
                button->setText("");
            }
        }
    }
}*/

