/*
Name:Antonio Butts Jr.
Assignment:Final Project
Section:006
AI-Usage:Minimal
*/

#include <iostream>
using namespace std;

// Game object
struct Player {
    int x;
    int y;
    bool hasWon;
    int moves;
};

// Draw the grid
void drawGrid(Player p, int tx, int ty) {
    cout << "\n=== TREASURE GRID ===\n";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (i == p.y && j == p.x) {
                cout << "P ";
            }
            else if (i == ty && j == tx) {
                cout << "T ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    cout << "Moves: " << p.moves << endl;
}

// Move player
void movePlayer(Player &p, char input) {
    if (input == 'w' && p.y > 0) {
        p.y--;
        p.moves++;
    }
    else if (input == 's' && p.y < 4) {
        p.y++;
        p.moves++;
    }
    else if (input == 'a' && p.x > 0) {
        p.x--;
        p.moves++;
    }
    else if (input == 'd' && p.x < 4) {
        p.x++;
        p.moves++;
    }
}

int main() {
    Player player;
    player.x = 0;
    player.y = 0;
    player.hasWon = false;
    player.moves = 0;

    int treasureX = 4;
    int treasureY = 4;

    cout << "=== FIND THE TREASURE! ===\n";
    cout << "HOW TO PLAY:\n";
    cout << "- You are P on the grid\n";
    cout << "- T is the treasure\n";
    cout << "- Move using W (up), A (left), S (down), D (right)\n";
    cout << "- Reach the treasure in the FEWEST moves possible\n";
    cout << "- Press Q to quit\n\n";

    char input;

    while (!player.hasWon) {

        drawGrid(player, treasureX, treasureY);

        cout << "\nMove (W/A/S/D) or Q to quit: ";
        cin >> input;

        if (input == 'q' || input == 'Q') {
            cout << "You quit the game.\n";
            break;
        }

        movePlayer(player, input);

        // WIN CONDITION
        if (player.x == treasureX && player.y == treasureY) {
            player.hasWon = true;

            cout << "\n YOU WIN! You found the treasure!\n";
            cout << "Total moves: " << player.moves << endl;

            // Performance grading message (simple but effective)
            if (player.moves <= 8) {
                cout << "Excellent! You found it in a low number of moves!\n";
            }
            else {
                cout << "Try again to reach it in fewer moves!\n";
            }
        }
    }

    if (!player.hasWon) {
        cout << "Game Over.\n";
    }

    return 0;
}