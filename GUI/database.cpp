#include "database.h"

Database::Database(const QString& usersFile, QObject *parent)
    : QObject(parent), usersFile(usersFile)
{
    // Constructor initializes with files
}

QMap<QString, QString> Database::loadUsers()
{
    QMap<QString, QString> users;
    QFile file(usersFile);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open users file for reading.";
        return users;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.length() == 2) {
            QString username = parts[0];
            QString password = parts[1];
            users.insert(username, password);
        }
    }

    file.close();
    return users;
}

void Database::saveUser(const QString& username, const QString& password)
{
    QFile file(usersFile);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open users file for writing.";
        return;
    }

    QTextStream out(&file);
    out << username << ":" << password << '\n';

    file.close();
}

bool Database::signUp(const QString& username, const QString& password)
{
    QMap<QString, QString> users = loadUsers();

    if (users.contains(username)) {
        qDebug() << "Username already exists. Please choose another one.";
        return false;
    }

    saveUser(username, password);
    qDebug() << "Sign up successful!";
    return true;
}

bool Database::signIn(const QString& username, const QString& password)
{
    QMap<QString, QString> users = loadUsers();

    if (!users.contains(username)) {
        qDebug() << "Username not found.";
        return false;
    }

    if (users.value(username) == password) {
        qDebug() << "Sign in successful!";
        return true;
    } else {
        qDebug() << "Incorrect password.";
        return false;
    }
}
