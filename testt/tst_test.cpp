#include <QtTest>
#include <QApplication>
#include <QMessageBox>
#include <QLineEdit>
#include <QSignalSpy>
#include <QPushButton>
#include <QFile>
#include <QtWidgets>
#include "../aihard.h"
#include "../database.h"
#include "../dialog.h"
#include "../gamehistorydialog.h"
#include "../hard1.h"
#include "../login.h"
#include "../mainwindow.h"
#include "../medium.h"
#include "../twoplayer.h"

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

private:
    QApplication* app;  // Pointer to QApplication instance
    Database* db;
    const QString testUsersFile = "test_users.txt";
      Dialog* dialog;
    GameHistoryDialog* gameHistoryDialog;

    QString testGameHistoryFile;



private slots:
    void initTestCase() {
        // Initialize QApplication instance
        int argc = 0;
        char* argv[] = {};
        app = new QApplication(argc, argv);
        QFile file(testUsersFile);
        file.remove();

        db = new Database(testUsersFile);
        dialog = new Dialog(db);

        testGameHistoryFile = "test_game_history.txt";

        // Prepare a test database and game history file

        QFile::remove(testGameHistoryFile);

        gameHistoryDialog = new GameHistoryDialog(nullptr, "testuser");


    }

    void cleanupTestCase() {
        // Cleanup QApplication instance
        delete app;
        delete db;
        delete dialog;

        // Clean up test files after tests are done
        QFile file(testUsersFile);
        file.remove();
        QFile::remove(testUsersFile);
        QFile::remove(testGameHistoryFile);
    }
     // tests for aihard
    void testHandlePlayerMove_data()
    {
        QTest::addColumn<int>("index");
        QTest::addColumn<bool>("expectedSet");
        QTest::addColumn<char>("expectedBoardState");

        // Add test cases here
        QTest::newRow("Empty button") << 0 << true << 'X';  // Example: Expected playerX set to true and board[0] set to 'X'
        QTest::newRow("Occupied button") << 0 << true << ' ';  // Example: Expected playerX set to true and board[0] should not change
    }
    //***************************************tests for hard***************************************
    void testHandlePlayerMove()
    {
        QFETCH(int, index);
        QFETCH(bool, expectedSet);
        QFETCH(char, expectedBoardState);

        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Verify initial state
        QVERIFY(game.board[index] == ' '); // Initial state check for board[index]
        QVERIFY(game.playerX == true); // Initial state check for playerX

        // Make a move on the specified button index
        game.handlePlayerMove(index);

        // Verify after the move
       // QCOMPARE(game.board[index], expectedBoardState); // Check if board state is updated correctly
        // QVERIFY(game.playerX != expectedSet); // Check if player turn toggles correctly

        // Add more assertions as needed
    }
    void testAiMove()
    {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        int initialEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');

        game.aiMove();

        int finalEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');
        QVERIFY(finalEmptyCells == initialEmptyCells - 1); // Check if AI made a move

       // QVERIFY(game.playerX == true); // AI move should not toggle player turn
    }

    void testCheckGameStatus()
    {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test for player X win
        game.board[0] = 'X';
        game.board[1] = 'X';
        game.board[2] = 'X';
        QVERIFY(game.checkWinner('X'));
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over

        // Test for player O win
        game.resetGame();
        game.board[0] = 'O';
        game.board[1] = 'O';
        game.board[2] = 'O';
        QVERIFY(game.checkWinner('O'));
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over

        // Test for tie
        game.resetGame();
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        game.board[3] = 'X';
        game.board[4] = 'O';
        game.board[5] = 'O';
        game.board[6] = 'O';
        game.board[7] = 'X';
        game.board[8] = 'X';
        QVERIFY(game.isBoardFull());
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over
    }

    void testCheckWinner()
    {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test for player X win
        game.board[0] = 'X';
        game.board[1] = 'X';
        game.board[2] = 'X';
        QVERIFY(game.checkWinner('X'));

        // Test for player O win
        game.resetGame();
        game.board[3] = 'O';
        game.board[4] = 'O';
        game.board[5] = 'O';
        QVERIFY(game.checkWinner('O'));

        // Test for no winner
        game.resetGame();
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        QVERIFY(!game.checkWinner('X'));
        QVERIFY(!game.checkWinner('O'));
    }

    void testIsBoardFull()
    {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test with empty board
        QVERIFY(!game.isBoardFull());

        // Test with full board
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        game.board[3] = 'X';
        game.board[4] = 'O';
        game.board[5] = 'O';
        game.board[6] = 'O';
        game.board[7] = 'X';
        game.board[8] = 'X';
        QVERIFY(game.isBoardFull());

        // Test with partially filled board
        game.resetGame();
        QVERIFY(!game.isBoardFull());
    }

    void testFindBestMove()
    {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test multiple moves to verify randomness and validity
        for (int i = 0; i < 10; ++i) {
            int move = game.findBestMove();
            QVERIFY(move >= 0 && move < 9);
            QVERIFY(game.board[move] == ' '); // Ensure the move is to an empty cell
        }
    }

    void testResetGame()
    {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Make some moves
        game.board[0] = 'X';
        game.board[4] = 'O';
        game.playerX = false;

        game.resetGame();

        // Verify board reset
        QVERIFY(std::all_of(std::begin(game.board), std::end(game.board), [](char cell) { return cell == ' '; }));

        // Verify player turn reset
        QVERIFY(game.playerX == true);
    }
     //********** **************************tests for meduim ***************************************
    void testMediumHandlePlayerMove()
    {
         medium game;
        game.resetGame(); // Ensure the game starts in a clean state

        int initialEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');

        // Test for valid move
        game.handlePlayerMove(0);
       // QVERIFY(std::count(std::begin(game.board), std::end(game.board), ' ') == initialEmptyCells - 1);

        // Test for invalid move (button already occupied)
        game.handlePlayerMove(0);
       // QVERIFY(std::count(std::begin(game.board), std::end(game.board), ' ') == initialEmptyCells - 1); // Board state should remain unchanged

        // Test if AI moves after player's valid move
        game.playerX = true;
        game.handlePlayerMove(1);
        QVERIFY(!std::all_of(std::begin(game.board), std::end(game.board), [](char cell) { return cell == ' '; }));
    }

    void testMediumAiMove()
    {
       medium game;
        game.resetGame(); // Ensure the game starts in a clean state

        int initialEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');

        game.aiMove();

        int finalEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');
        QVERIFY(finalEmptyCells == initialEmptyCells - 1); // Check if AI made a move

       // QVERIFY(game.playerX == true); // AI move should not toggle player turn
    }

    void testMediumCheckGameStatus()
    {
         medium game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test for player X win
        game.board[0] = 'X';
        game.board[1] = 'X';
        game.board[2] = 'X';
        QVERIFY(game.checkWinner('X'));
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over

        // Test for player O win
        game.resetGame();
        game.board[0] = 'O';
        game.board[1] = 'O';
        game.board[2] = 'O';
        QVERIFY(game.checkWinner('O'));
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over

        // Test for tie
        game.resetGame();
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        game.board[3] = 'X';
        game.board[4] = 'O';
        game.board[5] = 'O';
        game.board[6] = 'O';
        game.board[7] = 'X';
        game.board[8] = 'X';
        QVERIFY(game.isBoardFull());
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over
    }

    void testMediumCheckWinner()
    {
         medium game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test for player X win
        game.board[0] = 'X';
        game.board[1] = 'X';
        game.board[2] = 'X';
        QVERIFY(game.checkWinner('X'));

        // Test for player O win
        game.resetGame();
        game.board[3] = 'O';
        game.board[4] = 'O';
        game.board[5] = 'O';
        QVERIFY(game.checkWinner('O'));

        // Test for no winner
        game.resetGame();
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        QVERIFY(!game.checkWinner('X'));
        QVERIFY(!game.checkWinner('O'));
    }

    void testMediumIsBoardFull()
    {
         medium game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test with empty board
        QVERIFY(!game.isBoardFull());

        // Test with full board
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        game.board[3] = 'X';
        game.board[4] = 'O';
        game.board[5] = 'O';
        game.board[6] = 'O';
        game.board[7] = 'X';
        game.board[8] = 'X';
        QVERIFY(game.isBoardFull());

        // Test with partially filled board
        game.resetGame();
        QVERIFY(!game.isBoardFull());
    }

    void testMediumFindBestMove()
    {
        medium game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test multiple moves to verify randomness and validity
        for (int i = 0; i < 10; ++i) {
            int move = game.findBestMove();
            QVERIFY(move >= 0 && move < 9);
            QVERIFY(game.board[move] == ' '); // Ensure the move is to an empty cell
        }
    }

    void testMediumResetGame()
    {
         medium game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Make some moves
        game.board[0] = 'X';
        game.board[4] = 'O';
        game.playerX = false;

        game.resetGame();

        // Verify board reset
        QVERIFY(std::all_of(std::begin(game.board), std::end(game.board), [](char cell) { return cell == ' '; }));

        // Verify player turn reset
        QVERIFY(game.playerX == true);
    }
    //****************************************** tests for easy ***************************************
    void testEasyHandlePlayerMove()
    {
        hard1 game;
        game.resetGame(); // Ensure the game starts in a clean state

        int initialEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');

        // Test for valid move
        game.handlePlayerMove(0);
       // QVERIFY(std::count(std::begin(game.board), std::end(game.board), ' ') == initialEmptyCells - 1);

        // Test for invalid move (button already occupied)
        game.handlePlayerMove(0);
       // QVERIFY(std::count(std::begin(game.board), std::end(game.board), ' ') == initialEmptyCells - 1); // Board state should remain unchanged

        // Test if AI moves after player's valid move
        game.playerX = true;
        game.handlePlayerMove(1);
        QVERIFY(!std::all_of(std::begin(game.board), std::end(game.board), [](char cell) { return cell == ' '; }));
    }

    void testEasyAiMove()
    {
        hard1 game;
        game.resetGame(); // Ensure the game starts in a clean state

        int initialEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');

        game.aiMove();

        int finalEmptyCells = std::count(std::begin(game.board), std::end(game.board), ' ');
        QVERIFY(finalEmptyCells == initialEmptyCells - 1); // Check if AI made a move

       // QVERIFY(game.playerX == true); // AI move should not toggle player turn
    }

    void testEasyCheckGameStatus()
    {
        hard1 game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test for player X win
        game.board[0] = 'X';
        game.board[1] = 'X';
        game.board[2] = 'X';
        QVERIFY(game.checkWinner('X'));
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over

        // Test for player O win
        game.resetGame();
        game.board[0] = 'O';
        game.board[1] = 'O';
        game.board[2] = 'O';
        QVERIFY(game.checkWinner('O'));
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over

        // Test for tie
        game.resetGame();
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        game.board[3] = 'X';
        game.board[4] = 'O';
        game.board[5] = 'O';
        game.board[6] = 'O';
        game.board[7] = 'X';
        game.board[8] = 'X';
        QVERIFY(game.isBoardFull());
        game.checkGameStatus();
        QVERIFY(game.playerX == true); // Verify player turn reset after game over
    }

    void testEasyCheckWinner()
    {
        hard1 game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test for player X win
        game.board[0] = 'X';
        game.board[1] = 'X';
        game.board[2] = 'X';
        QVERIFY(game.checkWinner('X'));

        // Test for player O win
        game.resetGame();
        game.board[3] = 'O';
        game.board[4] = 'O';
        game.board[5] = 'O';
        QVERIFY(game.checkWinner('O'));

        // Test for no winner
        game.resetGame();
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        QVERIFY(!game.checkWinner('X'));
        QVERIFY(!game.checkWinner('O'));
    }

    void testEasyIsBoardFull()
    {
        hard1 game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test with empty board
        QVERIFY(!game.isBoardFull());

        // Test with full board
        game.board[0] = 'X';
        game.board[1] = 'O';
        game.board[2] = 'X';
        game.board[3] = 'X';
        game.board[4] = 'O';
        game.board[5] = 'O';
        game.board[6] = 'O';
        game.board[7] = 'X';
        game.board[8] = 'X';
        QVERIFY(game.isBoardFull());

        // Test with partially filled board
        game.resetGame();
        QVERIFY(!game.isBoardFull());
    }

    void testEasyFindBestMove()
    {
        hard1 game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Test multiple moves to verify randomness and validity
        for (int i = 0; i < 10; ++i) {
            int move = game.findBestMove();
            QVERIFY(move >= 0 && move < 9);
            QVERIFY(game.board[move] == ' '); // Ensure the move is to an empty cell
        }
    }

    void testEasyResetGame()
    {
        hard1 game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Make some moves
        game.board[0] = 'X';
        game.board[4] = 'O';
        game.playerX = false;

        game.resetGame();

        // Verify board reset
        QVERIFY(std::all_of(std::begin(game.board), std::end(game.board), [](char cell) { return cell == ' '; }));

        // Verify player turn reset
        QVERIFY(game.playerX == true);
    }
    //****************************************** tests for twoplayer ***************************************
    void testTwoPlayerHandlePlayerMove() {
        twoplayer game;
        game.resetGame();

        // Simulate a move
        game.handlePlayerMove(0);
        QCOMPARE(game.board[0], 'X');
        QVERIFY(game.playerX == false); // Player turn should toggle

        // Simulate another move
        game.handlePlayerMove(1);
        QCOMPARE(game.board[1], 'O');
        QVERIFY(game.playerX == true); // Player turn should toggle

        // Attempt to make a move in an occupied cell
        game.handlePlayerMove(0);
        QCOMPARE(game.board[0], 'X'); // Board state should remain unchanged
    }



    void testTwoPlayerResetGame() {
        twoplayer game;
        game.resetGame();

        game.board[0] = 'X';
        game.board[4] = 'O';
        game.playerX = false;
        game.resetGame();

        QVERIFY(std::all_of(std::begin(game.board), std::end(game.board), [](char cell) { return cell == ' '; }));
        QVERIFY(game.playerX == true);
    }


     //****************************************** tests for game history ***************************************


    void gameHistorySaveGameHistory()
    {
        QString testFile = "test_game_history.txt";
        QFile::remove(testFile); // Ensure the file is not present before test

        GameHistory gameHistory(testFile.toStdString());

        std::vector<std::string> moves = {"0", "1", "2", "3", "4", "5"};
        gameHistory.saveGameHistory("player1", "player2", "player1", moves);

        // Verify the content
        QFile file(testFile);
        QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
        QTextStream in(&file);
        QString line = in.readLine();
        file.close();

        QVERIFY(!line.isEmpty());
        QVERIFY(line.contains("player1:player2:player1:0,1,2,3,4,5"));

        QFile::remove(testFile); // Clean up
    }

    void gameHistoryParseGameHistory()
    {
        QString testFile = "test_parse_game_history.txt";
        createSampleHistoryFile(testFile);

        GameHistory gameHistory(testFile.toStdString());
        std::vector<GameRecord> records = gameHistory.parseGameHistory();

        QCOMPARE(records.size(), 2);
        QCOMPARE(records[0].player1, std::string("player1"));
        QCOMPARE(records[0].player2, std::string("player2"));
        QCOMPARE(records[0].winner, std::string("player1"));
        QCOMPARE(records[0].moves, std::vector<std::string>({"0", "1", "2", "3", "4", "5"}));

        QCOMPARE(records[1].player1, std::string("player3"));
        QCOMPARE(records[1].player2, std::string("player4"));
        QCOMPARE(records[1].winner, std::string("player4"));
        QCOMPARE(records[1].moves, std::vector<std::string>({"0", "1", "2", "3", "4", "5"}));

        QFile::remove(testFile); // Clean up
    }



    void createSampleHistoryFile(const QString& filePath)
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "player1:player2:player1:0,1,2,3,4,5\n";
            out << "player3:player4:player4:0,1,2,3,4,5\n";
            file.close();
        }
    }
     //****************************************** tests for data base***************************************
    void testLoadUsers()
    {
        // Create a test users file with sample data
        QFile file(testUsersFile);
        QVERIFY(file.open(QIODevice::WriteOnly | QIODevice::Text));
        QTextStream out(&file);
        out << "user1:password1\n";
        out << "user2:password2\n";
        file.close();

        QMap<QString, QString> users = db->loadUsers();
        QCOMPARE(users.size(), 2);
        QCOMPARE(users.value("user1"), QString("password1"));
        QCOMPARE(users.value("user2"), QString("password2"));
    }

    void testSaveUser()
    {
        db->saveUser("testuser", "testpassword");

        QMap<QString, QString> users = db->loadUsers();
        QVERIFY(users.contains("testuser"));
        QCOMPARE(users.value("testuser"), QString("testpassword"));
    }

    void testSignUp()
    {
        QVERIFY(db->signUp("newuser", "newpassword"));
        QVERIFY(!db->signUp("newuser", "anotherpassword"));  // Should fail because user already exists

        QMap<QString, QString> users = db->loadUsers();
        QVERIFY(users.contains("newuser"));
        QCOMPARE(users.value("newuser"), QString("newpassword"));
    }

    void testSignIn()
    {
        db->saveUser("signinuser", "signinpassword");

        QVERIFY(db->signIn("signinuser", "signinpassword"));
        QVERIFY(!db->signIn("signinuser", "wrongpassword"));
        QVERIFY(!db->signIn("nonexistentuser", "password"));
    }

    void testSaveGameHistory()
    {
        QString player1 = "player1";
        QString player2 = "player2";
        QString winner = "player1";
        QString moves = "XOXOXOXOX";

        db->saveGameHistory(player1, player2, winner, moves);

        QFile file("game_history.txt");
        QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
        QTextStream in(&file);
        QString line = in.readLine();
        file.close();

       // QCOMPARE(line, QString("%1:%2:%3:%4").arg(player1, player2, winner, moves));
    }
    // ****************************************** tests for login***************************************

    void testAcceptButton_data()
    {
        QTest::addColumn<QString>("username");
        QTest::addColumn<QString>("password");
        QTest::addColumn<bool>("expectedSuccess");

        QTest::newRow("empty-username-password") << "" << "" << false;
        QTest::newRow("empty-username") << "" << "password" << false;
        QTest::newRow("empty-password") << "username" << "" << false;
        QTest::newRow("valid-signup") << "username" << "password" << true;
        QTest::newRow("duplicate-signup") << "username" << "password" << false;
    }

    void testAcceptButton()
    {
        QFETCH(QString, username);
        QFETCH(QString, password);
        QFETCH(bool, expectedSuccess);

        QLineEdit* usernameLineEdit = dialog->findChild<QLineEdit*>("lineEdit_username");
        QLineEdit* passwordLineEdit = dialog->findChild<QLineEdit*>("lineEdit_password");
        QPushButton* acceptButton = dialog->findChild<QPushButton*>("pushButton_accept");

        QVERIFY(usernameLineEdit != nullptr);
        QVERIFY(passwordLineEdit != nullptr);
        QVERIFY(acceptButton != nullptr);

        usernameLineEdit->setText(username);
        passwordLineEdit->setText(password);

        QSignalSpy spyAccept(acceptButton, &QPushButton::clicked);
        QMetaObject::invokeMethod(acceptButton, "click");

        if (expectedSuccess) {
            QVERIFY2(db->signIn(username, password), "Expected sign-in to succeed.");
        } else {
           //  QVERIFY2(!db->signIn(username, password), "Expected sign-in to fail.");
        }
    }

    void testCancelButton()
    {
        QPushButton* cancelButton = dialog->findChild<QPushButton*>("pushButton_cancel");
        QVERIFY(cancelButton != nullptr);

        QSignalSpy spyCancel(cancelButton, &QPushButton::clicked);
        QMetaObject::invokeMethod(cancelButton, "click");

        QCOMPARE(spyCancel.count(), 1);
        QVERIFY(dialog->result() == QDialog::Rejected);
    }
     // ****************************************** tests for dialog***************************************

    void dialogtestAcceptButton_data()
    {
        QTest::addColumn<QString>("username");
        QTest::addColumn<QString>("password");
        QTest::addColumn<bool>("expectedSuccess");

        QTest::newRow("empty-username-password") << "" << "" << false;
        QTest::newRow("empty-username") << "" << "password" << false;
        QTest::newRow("empty-password") << "username" << "" << false;
        QTest::newRow("valid-signup") << "username" << "password" << true;
        QTest::newRow("duplicate-signup") << "username" << "password" << false;
    }

    void dialogtestAcceptButton()
    {
        QFETCH(QString, username);
        QFETCH(QString, password);
        QFETCH(bool, expectedSuccess);

        QLineEdit* usernameLineEdit = dialog->findChild<QLineEdit*>("lineEdit_username");
        QLineEdit* passwordLineEdit = dialog->findChild<QLineEdit*>("lineEdit_password");
        QPushButton* acceptButton = dialog->findChild<QPushButton*>("pushButton_accept");

        usernameLineEdit->setText(username);
        passwordLineEdit->setText(password);

        QSignalSpy spy(dialog, &Dialog::registrationSuccess);
        QTest::mouseClick(acceptButton, Qt::LeftButton);

        bool success = (spy.count() > 0);
        // QCOMPARE(success, expectedSuccess);
    }

    void dialogtestCancelButton()
    {
        QPushButton* cancelButton = dialog->findChild<QPushButton*>("pushButton_cancel");

        QSignalSpy spy(dialog, &QDialog::rejected);
        QTest::mouseClick(cancelButton, Qt::LeftButton);

        bool canceled = (spy.count() > 0);
        QVERIFY(canceled);
    }
    // ****************************************** tests for gamehistory dialog***************************************
    void testMovesToString()
    {
        GameHistoryDialog dialog(nullptr, "testuser"); // Replace with actual constructor parameters

        std::vector<std::string> moves = {"move1", "move2", "move3"};
        QString expected = "move1,move2,move3";

        QString result = dialog.movesToString(moves); // Call movesToString() on dialog instance

        QCOMPARE(result, expected);
    }

    void testViewHistoryButtonClicked()
    {
        // Setup: Create a mock GameHistoryDialog instance with a known username and mock game history
        QString username = "testuser";
        GameHistoryDialog dialog(nullptr, username);

        // Assuming setupUIComponents() and displayHistory() are tested separately,
        // we focus on the click event handling here.

        // Simulate a click on the view history button
        dialog.on_pushButton_viewHistory_clicked();

        // Verify the table widget is populated with the expected game history for 'testuser'
        QTableWidget* tableWidget = dialog.findChild<QTableWidget*>("tableWidget_history");
        QVERIFY(tableWidget != nullptr);

        // Example: Check if the table widget contains expected rows and data
       // QCOMPARE(tableWidget->rowCount(), 2); // Assuming two mock game records

        // Additional assertions can be added based on your specific implementation
    }

    // ***************************************** tests for mainwindow*************************************
    void testRegistrationDialog()
    {
        MainWindow mainWindow;

        // Simulate clicking on the registration button
        QPushButton* registrationButton = mainWindow.findChild<QPushButton*>("pushButton_4");
        QVERIFY2(registrationButton != nullptr, "Registration button not found");

        QSignalSpy registrationSuccessSpy(&mainWindow, &MainWindow::handleRegistrationSuccess);

        QTest::mouseClick(registrationButton, Qt::LeftButton);

        // Check if registration dialog opens and succeeds

        // Check if handleRegistrationSuccess() slot was called
       // QCOMPARE(registrationSuccessSpy.count(), 1);
    }

    void testLogin()
    {
        MainWindow mainWindow;

        // Simulate entering username and password
        QLineEdit* usernameLineEdit = mainWindow.findChild<QLineEdit*>("lineEdit_username");
        QVERIFY2(usernameLineEdit != nullptr, "Username line edit not found");
        QLineEdit* passwordLineEdit = mainWindow.findChild<QLineEdit*>("lineEdit_password");
        QVERIFY2(passwordLineEdit != nullptr, "Password line edit not found");

        usernameLineEdit->setText("testuser");
        passwordLineEdit->setText("testpassword");

        // Simulate clicking on the login button
        QPushButton* loginButton = mainWindow.findChild<QPushButton*>("pushButton_1");
        QVERIFY2(loginButton != nullptr, "Login button not found");

        QTest::mouseClick(loginButton, Qt::LeftButton);

        // Check if Dialog1 (main application window after login) opens
        // Dialog1* dialog1 = qobject_cast<Dialog1*>(mainWindow.findChild<QDialog*>("Dialog1"));
        // QVERIFY2(dialog1 != nullptr, "Dialog1 not opened after login");

        // Check if username matches after login
       // QCOMPARE(dialog1->getUsername(), QString("testuser"));
    }

};


QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
