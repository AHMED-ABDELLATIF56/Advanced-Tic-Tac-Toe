#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QDebug>

class Database : public QObject
{
    Q_OBJECT

public:
    explicit Database(const QString& usersFile, QObject *parent = nullptr);
    QMap<QString, QString> loadUsers();
    void saveUser(const QString& username, const QString& password);
    bool signUp(const QString& username, const QString& password);
    bool signIn(const QString& username, const QString& password);
    void saveGameHistory(const QString& player1, const QString& player2, const QString& winner, const QString& moves);


private:
    QString usersFile;
};

#endif // DATABASE_H
