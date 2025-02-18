#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <map>      // for snakes and ladders positions
#include <vector>   // for storing the board
#include <thread>   // for AI delay and adding game realism
#include <chrono>   // Required for using std::this_thread::sleep_for to introduce delays
using namespace std;

class Player {
public:
    string name;
    int position;
    
    Player(string playerName) {
        name = playerName;
        position = 1; // All players start at position 1
    }

    void move(int diceRoll) {
        position += diceRoll;
        if (position > 100) {
            position = 100;  // Prevent moving beyond the last square
        }
    }
};


class SnakeAndLadder {
private:
    map<int, int> snakes; // Key: snake head, Value: snake tail
    map<int, int> ladders; // Key: ladder bottom, Value: ladder top
    int finalPosition;
    
public:
    SnakeAndLadder(int boardSize) {
        finalPosition = boardSize;
        
        // Example snakes and ladders (you can modify as per need)
        snakes[16] = 6;
        snakes[47] = 26;
        snakes[49] = 11;
        snakes[56] = 53;
        snakes[62] = 19;
        snakes[87] = 24;
        ladders[3] = 22;
        ladders[5] = 8;
        ladders[20] = 29;
        ladders[27] = 84;
        ladders[72] = 91;
        ladders[77] = 96;
    }

    void displayBoard(Player& player1, Player& player2) {
        cout << "Snake :**" <<" ," << "Ladder:##"<<endl<<"\nCurrent Board:  \n";
        for (int i = 100; i > 0; i -= 10) {
            for (int j = i; j > i - 10; --j) {
                if (j == player1.position && j == player2.position) {
                    cout << "|P1P2";  // Both players on the same square
                } else if (j == player1.position) {
                    cout << "| P1 ";
                } else if (j == player2.position) {
                    cout << "| P2 ";
                } else if (snakes.find(j) != snakes.end()) {
                    cout << "| **" <<" ";  // Represent a snake with 'S'
                } else if (ladders.find(j) != ladders.end()) {
                    cout << "| ##" <<" ";  // Represent a ladder with 'L'
                } else {
                    printf("|%3d ", j);  // Regular square number
                }
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
    
    void checkForSnakesAndLadders(Player &player) {
        if (snakes.find(player.position) != snakes.end()) {
            cout << player.name << " got bitten by a snake! Sliding down from " << player.position;
            player.position = snakes[player.position];
            cout << " to " << player.position << endl;
        } else if (ladders.find(player.position) != ladders.end()) {
            cout << player.name << " climbed a ladder! Moving up from " << player.position;
            player.position = ladders[player.position];
            cout << " to " << player.position << endl;
        }
    }
    
    bool isGameOver(Player &player) {
        return player.position >= finalPosition;
    }
};

int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    srand(time(0));  // Seed for random number generation

    int boardSize = 100;
    SnakeAndLadder game(boardSize);

    int numPlayers;
    cout << "Enter number of players (1-4): ";
    cin >> numPlayers;
    cin.ignore(); // Clear input buffer

    vector<Player> players;
    for (int i = 1; i <= numPlayers; i++) {
        string playerName;
        cout << "Enter Player " << i << " Name: ";
        getline(cin, playerName);
        players.push_back(Player(playerName));
    }

    // If only one player, adding AI opponent
    if (numPlayers == 1) {
        players.push_back(Player("AI Player"));
        numPlayers++;
    }

    int currentPlayerIndex = 0;

    while (true) {
        game.displayBoard(players[0], players[1]);  // Display board at the start of each turn
        Player &currentPlayer = players[currentPlayerIndex];

        cout << currentPlayer.name << "'s turn. Press enter to roll the dice...";
        if (currentPlayer.name == "AI Player") {
            this_thread::sleep_for(chrono::seconds(1)); // Adding delay 
        } else {
            cin.ignore();
        }

        int diceRoll = rollDice();
        cout << currentPlayer.name << " rolled a " << diceRoll << endl;
        currentPlayer.move(diceRoll);
        cout << currentPlayer.name << " moved to position " << currentPlayer.position << endl;

        game.checkForSnakesAndLadders(currentPlayer);

        if (game.isGameOver(currentPlayer)) {
            cout << currentPlayer.name << " has won the game!" << endl;
            break;
        }

        // Move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % numPlayers;
    }

    return 0;
}