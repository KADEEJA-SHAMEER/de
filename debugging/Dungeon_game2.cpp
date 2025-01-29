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

void generateDungeon(char dungeon[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dungeon[i][j] = ' ';
        }
    }
    dungeon[4][0] = 'S'; // Start position
    dungeon[0][4] = 'E'; // Fixed Exit Position
    
    for (int i = 0; i < 3; i++) {
        int x, y;
        do {
            x = rand() % 5;
            y = rand() % 5;
        } while (dungeon[x][y] != ' ' || (x == 0 && y == 4));
        dungeon[x][y] = 'M'; // Monsters
    }
    for (int i = 0; i < 3; i++) {
        int x, y;
        do {
            x = rand() % 5;
            y = rand() % 5;
        } while (dungeon[x][y] != ' ' || (x == 0 && y == 4));
        dungeon[x][y] = 'W'; // Walls
    }
    int x, y;
    do {
        x = rand() % 5;
        y = rand() % 5;
    } while (dungeon[x][y] != ' ' || (x == 0 && y == 4));
    dungeon[x][y] = 'T'; // Treasure
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

int main() {
    srand(static_cast<unsigned>(time(0)));
    char dungeon[5][5];
    int playerX = 4, playerY = 0; // Starting position
    char move;
    cout << "Welcome to the Dungeon Game!\n";
    cout << "Your goal is to reach the exit (E).\n";
    cout << "Beware of monsters (M) and walls (W)!\n\n";
    
    while (true) {
        generateDungeon(dungeon);
        displayMap(dungeon, playerX, playerY);
        cout << "\nMove (W/A/S/D): ";
        cin >> move;
        int newX = playerX, newY = playerY;
        if (move == 'W' || move == 'w') newX--;
        else if (move == 'S' || move == 's') newX++;
        else if (move == 'A' || move == 'a') newY--;
        else if (move == 'D' || move == 'd') newY++;
        else {
            cout << "Invalid input. Use W, A, S, or D.\n";
            continue;
        }
        if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5) {
            cout << "You hit the edge of the dungeon. Try another direction.\n";
            continue;
        }
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
            dungeon[newX][newY] = ' ';
        } else if (tile == 'T') {
            cout << "You found treasure!\n";
            dungeon[newX][newY] = ' ';
        } else if (tile == 'E') {
            cout << "You found the exit! You win!\n";
            break;
        }
        playerX = newX;
        playerY = newY;
    }
    return 0;
}