# Snake and Ladder Game

This is a simple console-based Snake and Ladder game implemented in C++. The game supports 1-4 players, including an AI opponent for single-player mode.

## **Features**

- **Multiplayer Support**: Play with up to 4 players.
- **AI Opponent**: If you're playing alone, an AI opponent will join the game.
- **Snakes and Ladders**: Randomly placed snakes and ladders to make the game exciting.
- **Interactive Board**: The game board is displayed after every move, showing player positions, snakes, and ladders.
- **Dice Roll**: Players roll a virtual dice to move forward on the board.

## **How to Play**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Manav2905/Snake-and_Ladder_game.git
   cd Snake-and_Ladder_game

2. **Compile the Code**:
   ```bash
   g++ -o Snake_and_ladder_game Snake_and_ladder_game.cpp


3. **Run the Game**:
   ```bash
   ./Snake_and_ladder_game


**Follow the Prompts**:

- Enter the number of players (1-4).

- Enter the names of the players.

- Press Enter to roll the dice on your turn.

- The game will display the board after each move and announce if a player encounters a snake or ladder.


**Winning the Game**:

- The first player to reach or exceed position 100 wins the game.


**Code Structure**:

- Player Class: Represents a player with a name and position on the board.
= SnakeAndLadder Class: Manages the game board, snakes, ladders, and game logic.
- Main Function: Handles player input, dice rolling, and game flow.


**Customization**:

- You can modify the positions of snakes and ladders in the SnakeAndLadder class constructor.
- Adjust the AI delay in the main function by changing the this_thread::sleep_for duration.


**Dependencies**:

- C++ Standard Library.
- No external libraries are required.
