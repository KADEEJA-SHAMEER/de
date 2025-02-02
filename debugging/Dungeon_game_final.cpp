#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayMap(char dungeon[5][5], int playerX, int playerY) {
    cout << "\nDungeon Map:\n";
    cout << "  +---+---+---+---+---+" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  |";
        for (int j = 0; j < 5; j++) {
            if (i == playerX && j == playerY) {
                cout << " P |"; // Player's position
            } else {
                cout << " " << dungeon[i][j] << " |";
            }
        }
        cout << "\n  +---+---+---+---+---+" << endl;
    }
}

void generateWalls(char dungeon[5][5]) {
    // Initialize with empty spaces
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dungeon[i][j] = ' ';
        }
    }
    dungeon[4][0] = ' '; // Start position
    dungeon[0][4] = 'E'; // Fixed Exit Position

    // **Fixed walls that do not change**
    for (int i = 0; i < 3; i++) {
        int x, y;
        do {
            x = rand() % 5;
            y = rand() % 5;
        } while ((x == 4 && y == 0) || (x == 3 && y == 0) || (x == 4 && y == 1) || dungeon[x][y] != ' ');
        dungeon[x][y] = 'W'; // Walls
    }
}

void generateMonsters(char dungeon[5][5], int playerX, int playerY) {
    // Remove old monster positions
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (dungeon[i][j] == 'M') {
                dungeon[i][j] = ' ';
            }
        }
    }

    // **Place monsters randomly each time**
    for (int i = 0; i < 3; i++) {
        int x, y;
        do {
            x = rand() % 5;
            y = rand() % 5;
        } while (dungeon[x][y] != ' ' || (x == playerX && y == playerY) || (x == 0 && y == 4));
        dungeon[x][y] = 'M'; // Monsters
    }

    // **Ensure treasure is placed properly**
    int x, y;
    do {
        x = rand() % 5;
        y = rand() % 5;
    } while (dungeon[x][y] != ' ' || (x == playerX && y == playerY) || (x == 0 && y == 4));
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
    int playerX = 4, playerY = 0; // **Start position fixed at [4][0]**
    char move;

    cout << "Welcome to the Dungeon Game!\n";
    cout << "Your goal is to reach the exit (E).\n";
    cout << "Beware of monsters (M) and walls (W)!\n\n";

    // **Generate walls once (do not change them)**
    generateWalls(dungeon);

    while (true) {
        // **Generate monsters & treasure every iteration**
        generateMonsters(dungeon, playerX, playerY);
        
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
            // Player defeats the monster and moves into the position
        } else if (tile == 'T') {
            cout << "You found treasure!\n";
        } else if (tile == 'E') {
            cout << "You found the exit! You win!\n";
            break;
        }

        // Update player position
        playerX = newX;
        playerY = newY;
    }

    return 0;
}
