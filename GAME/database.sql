-- Create Users Table
CREATE TABLE IF NOT EXISTS Users (
                                     id INTEGER PRIMARY KEY AUTOINCREMENT,
                                     username TEXT NOT NULL UNIQUE,
                                     password_hash TEXT NOT NULL,
                                     email TEXT NOT NULL UNIQUE
);

-- Create GameHistory Table
CREATE TABLE IF NOT EXISTS GameHistory (
                                           game_id INTEGER PRIMARY KEY AUTOINCREMENT,
                                           player1_id INTEGER,
                                           player2_id INTEGER,
                                           winner INTEGER,
                                           moves TEXT,
                                           timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
                                           FOREIGN KEY(player1_id) REFERENCES Users(id),
                                           FOREIGN KEY(player2_id) REFERENCES Users(id),
                                           FOREIGN KEY(winner) REFERENCES Users(id)
);