# Cross-Block Game

Cross-Block is a turn-based strategy board game for two players: Crosser (Red) and Blocker (Blue). The goal of this project is to simulate the Cross-Block game in a console-based application with human and AI player support.

---

# 📋 Game Description

- The game is played on an m x m board, where m >= 3 and m <= 10.

- Players take turns simultaneously placing markers:

  - Crosser (C) aims to form a continuous path from the left edge to the right edge.

  - Blocker (B) attempts to block the Crosser from achieving this.

- If both players pick the same cell, Blocker wins the contest for that cell.

- The game ends when:

  - The Crosser forms a valid path (C-path).

  - The board is full and no path exists for the Crosser.
 
    <img width="525" alt="Screen Shot 2025-03-23 at 18 45 55" src="https://github.com/user-attachments/assets/23095da4-d04d-4ade-9a2b-f5937fb6d9c8" />


---

# 🎯 Objectives

This game has multiple tasks:

- Human vs Human / AI Gameplay

- Random AI for both Crosser and Blocker

- Smart AI using custom strategies

- General AI using Monte Carlo algorithms

- C-path detection via DFS algorithm

--- 

# 🧠 AI Features

- Random Player: Places valid moves randomly.

- Smart Crosser: Attempts to create a left-to-right C-path.

- Smart Blocker: Predicts Crosser's path and blocks it.

- Monte Carlo Player: Uses simulation-based approach to decide the best move.

--- 

# 🛠 Technologies

- Language: C++

- No graphics: The board is displayed in text format.
