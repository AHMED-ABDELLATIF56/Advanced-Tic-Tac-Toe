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
friend class test ;
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
struct GameRecord {
    std::string player1;
    std::string player2;
    std::string winner;
    std::vector<std::string> moves;
};

class GameHistory {
public:
    GameHistory(const std::string& gameHistoryFile);
    void saveGameHistory(const std::string& player1, const std::string& player2, const std::string& winner, const std::vector<std::string>& moves);
    std::vector<GameRecord> parseGameHistory();
    void viewGameHistory(const std::string& username);
    static QString movesToString(const std::vector<std::string>& moves);
private:
    std::string gameHistoryFile;
    void displayBoard(const std::vector<std::string>& moves);
};

#endif // DATABASE_H
