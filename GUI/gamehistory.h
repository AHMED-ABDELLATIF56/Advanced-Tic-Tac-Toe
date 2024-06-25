#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QObject>
#include <QString>
#include <QVector>

struct GameRecord {
    QString player1;
    QString player2;
    QString winner;
    QVector<QString> moves;
};

class GameHistory : public QObject {
    Q_OBJECT

public:
    explicit GameHistory(const QString& gameHistoryFile, QObject *parent = nullptr);

    void saveGameHistory( const QString& winner, const QString& moves);
    QVector<GameRecord> parseGameHistory();
    QVector<GameRecord> viewGameHistory(const QString& username);
    void displayBoard(const QVector<QString>& moves);

private:
    QString gameHistoryFile;
};

#endif // GAMEHISTORY_H

