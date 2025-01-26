#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayMap(char dungeon[5][5], int playerX, int playerY) {
    cout << "\nDungeon Map:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == playerX && j == playerY) {
                cout << "P "; // Player's position
            } else {
                cout << dungeon[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool fightMonster() {
    int playerHealth = 20, monsterHealth = 15;

    while (playerHealth > 0 && monsterHealth > 0) {
        int playerAttack = rand() % 5 + 1;
        int monsterAttack = rand() % 5 + 1;

        monsterHealth -= playerAttack;
        playerHealth -= monsterAttack;

        cout << "You dealt " << playerAttack << " damage. Monster health: " << monsterHealth << endl;
        cout << "Monster dealt " << monsterAttack << " damage. Your health: " << playerHealth << endl;

        if (monsterHealth <= 0) {
            cout << "You defeated the monster!\n";
            return true;
        }
        if (playerHealth <= 0) {
            cout << "You were defeated by the monster...\n";
            return false;
        }
    }
    return false;
}

int main()
 {
    srand(static_cast<unsigned>(time(0)));

    // Simple dungeon layout
    char dungeon[5][5] = {
        {' ', 'M', ' ', ' ', 'E'},
        {' ', 'W', ' ', 'M', ' '},
        {' ', ' ', 'T', ' ', ' '},
        {'M', ' ', ' ', 'W', ' '},
        {'S', ' ', ' ', 'M', ' '}
    };

    int playerX = 4, playerY = 0; // Starting position
    char move;

    cout << "Welcome to the Dungeon Game!\n";
    cout << "Your goal is to reach the exit (E).\n";
    cout << "Beware of monsters (M) and walls (W)!\n\n";

    while (true) {
        displayMap(dungeon, playerX, playerY);
        cout << "\nMove (W/A/S/D): ";
        cin >> move;

        int newX = playerX, newY = playerY;

        // Update position based on move
        if (move == 'W' || move == 'w') newX--;
        else if (move == 'S' || move == 's') newX++;
        else if (move == 'A' || move == 'a') newY--;
        else if (move == 'D' || move == 'd') newY++;
        else {
            cout << "Invalid input. Use W, A, S, or D.\n";
            continue;
        }

        // Check boundaries
        if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5) {
            cout << "You hit the edge of the dungeon. Try another direction.\n";
            continue;
        }

        // Update player position
        char tile = dungeon[newX][newY];
        if (tile == 'W') {
            cout << "You hit a wall. Choose another path.\n";
            continue;
        } else if (tile == 'M') {
            cout << "A monster appears!\n";
            if (!fightMonster()) {
                cout << "Game Over!\n";
                break;
            }
            dungeon[newX][newY] = ' '; // Remove monster after fight
        } else if (tile == 'T') {
            cout << "You found treasure!\n";
            dungeon[newX][newY] = ' '; // Remove treasure
        } else if (tile == 'E') {
            cout << "You found the exit! You win!\n";
            break;
        }

        // Move player
        playerX = newX;
        playerY = newY;
    }

    return 0;
}