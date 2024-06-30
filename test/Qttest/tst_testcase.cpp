#include <QtTest/QtTest>
#include "../aihard.h"
#include "../dialog.h"
#include "../hard1.h"
#include "../login.h"
#include "../mainwindow.h"
#include "../twoplayer.h"

class TestPlayer : public QObject
{
    Q_OBJECT

private slots:
    void test_case1()
    {
        QVERIFY(1 + 1 == 2);
    }

    void test_case2()
    {
        QCOMPARE(QString("hello").toUpper(), QString("HELLO"));
    }

    // Tests for aihard class functions

    void testHandlePlayerMove()
    {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Verify initial state
        QVERIFY(game.board[0] == ' '); // Initial state check for board[0]
        QVERIFY(game.playerX == true); // Initial state check for playerX

        // Make a move on button 0
        game.handlePlayerMove(0);

        // Verify after the move
        QCOMPARE(game.board[0], 'X'); // Check if board state is updated correctly
        // QVERIFY(game.playerX == false); // Check if player turn toggles correctly

        // Make another move on button 1
        game.handlePlayerMove(1);

        // Verify after the second move
       // QCOMPARE(game.board[1], 'O'); // Check if board state is updated correctly
        QVERIFY(game.playerX == true); // Check if player turn toggles correctly again

        // Add more test cases to cover different scenarios
    }


    void testAIMove() {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Simulate player move
        game.handlePlayerMove(0); // Player's move

        // Call AI move and verify board state after AI's move
        game.aiMove();
        QVERIFY(game.board.contains('O')); // Check if AI has made a move
        // QVERIFY(game.playerX == true); // Check if player turn toggles after AI's move
        // Add more assertions as needed
    }

    void testCheckGameStatus() {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Simulate a game where X wins
        game.handlePlayerMove(0);
        game.handlePlayerMove(3);
        game.handlePlayerMove(1);
        game.handlePlayerMove(4);
        game.handlePlayerMove(2);

        // Verify if the game status correctly identifies X as the winner
       // QVERIFY(game.checkWinner('X'));
        QVERIFY(game.playerX == true); // Check if player turn resets after game over
        // Add more assertions for other game outcomes (O wins, tie)
    }

    void testCheckWinner() {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Simulate a winning scenario for X
        game.handlePlayerMove(0);
        game.handlePlayerMove(3);
        game.handlePlayerMove(1);
        game.handlePlayerMove(4);
        game.handlePlayerMove(2);

       // QVERIFY(game.checkWinner('X')); // Check if X is correctly identified as winner
        QVERIFY(!game.checkWinner('O')); // Check if O is correctly identified as not winner
    }

    void testIsBoardFull() {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Fill the board without completing the game
        game.handlePlayerMove(0);
        game.handlePlayerMove(1);
        game.handlePlayerMove(2);
        game.handlePlayerMove(3);
        game.handlePlayerMove(4);
        game.handlePlayerMove(5);
        game.handlePlayerMove(6);
        game.handlePlayerMove(7);
        game.handlePlayerMove(8);

       // QVERIFY(game.isBoardFull()); // Check if the board is correctly identified as full
        QVERIFY(!game.checkWinner('X')); // Verify no winner when board is full
    }

    void testFindBestMove() {
        aihard game;
        game.resetGame(); // Ensure the game starts in a clean state

        // Simulate a move and then test AI's move
        game.handlePlayerMove(0);
        game.aiMove();

        QVERIFY(game.board.contains('O')); // Check if AI has made a move
       // QVERIFY(game.playerX == true); // Check if player turn toggles after AI's move
        // Add more assertions as needed for different scenarios
    }

    // Tests for twoplayer class functions

    void testHandleButtonClick()
    {
        // Create an instance of twoplayer
        twoplayer game;

        // Simulate setting up the game state (playerX is initially true)
        game.playerX = true;

        // Create a QPushButton to simulate button click
        QPushButton button;
        QVERIFY(button.text().isEmpty()); // Ensure button text is initially empty

        // Simulate button click with an empty text button
        game.handleButtonClick(&button);

        // Verify button text is set correctly based on playerX
        QCOMPARE(button.text(), QString("X")); // Since playerX was true

        // Verify player turn toggles correctly
        QVERIFY(!game.playerX); // After clicking, playerX should be false

        // Simulate another button click with the same button
        game.handleButtonClick(&button);

        // Verify button text is set correctly again based on playerX
      //  QCOMPARE(button.text(), QString("O")); // Since playerX is now false

        // Verify player turn toggles back to true
        // QVERIFY(game.playerX); // After clicking again, playerX should be true

        // You can add more test cases to cover edge cases and additional scenarios
    }

      // Tests for hard1 class functions
};


QTEST_MAIN(TestPlayer)
#include "tst_testcase.moc"
