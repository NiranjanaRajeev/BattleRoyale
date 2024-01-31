## Battle Royale Game in C

This project is a console-based Battle Royale game written in C. It features a grid-based board where players move around and engage in battles using a rock-paper-scissors mechanic. The game continues until only one player remains.

### Key Features

1. **Dynamic Board and Player Initialization**: The game initializes with a user-defined number of players and board size. Players are randomly placed on the board at the start.

2. **Player Structure**: Each player is defined by a structure (`player`) with attributes like name, life points, and coordinates (x, y) on the board.

3. **Game Mechanics**:
   - **Movement**: Players move to a random adjacent unoccupied tile each turn.
   - **Combat**: When players are adjacent, they engage in a rock-paper-scissors battle. The loser loses a life point.
   - **Elimination**: Players are eliminated when their life points reach zero.

4. **Logging**: All game actions, including player movements, battle outcomes, and player eliminations, are logged to a file (`game_log.txt`) for post-game analysis.

5. **Board Display**: The game board is displayed in the console after each player's move, showing players' positions and the board's boundaries.

6. **Game Loop**: The game continues in turns until only one player is left on the board, who is then declared the winner.

### Project Structure

- `main.c`: Contains the main game loop and high-level game logic.
- `functions.c`: Implements the core game functionalities like player movement, combat logic, board display, and logging.
- `functions.h`: Header file declaring the player structure and function prototypes used in the game.

### Development Approach

- **Modular Design**: The game logic is broken down into multiple functions for readability and maintainability.
- **Dynamic Memory Management**: Players are stored in a dynamically allocated array, allowing flexibility in the number of players.
- **File I/O**: External files are used for player names and logging game actions.
- **Global Variables**: Used for storing the number of players, board dimensions, and a shared message buffer.

### How to Play

1. Compile the code and run the executable with three arguments: number of players, board length, and board width.
2. Follow the game progress in the console and `game_log.txt`.

The arguments number of players , board length and board width are defined in the launch.json file in the "args":
The names for players are taken from names.txt where 100 names are stored.
