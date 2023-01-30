#include <iostream>
#include <limits>

using namespace std;

bool checkWinner(char element[9], char currentPlayer);

void printBoarder(char element[9]);

void beginning(char element[9]);

int main() {
    char element[9], again;
    char currentPlayer = 'X';
    bool X_turn = true;
    int choice;
    beginning:
    beginning(element);
    while (true) {
        printBoarder(element);
        cout << currentPlayer << " turn\n";
        cin >> choice;
        if (0 < choice && choice < 10) {
            if (element[choice - 1] != 'X' && element[choice - 1] != 'O')
                element[choice - 1] = currentPlayer;
            else {
                cout << "already has been chosen \n";
                continue;
            }
        } else cout << "Wrong choice Mr." << currentPlayer << endl;
        X_turn = !X_turn;
        if (checkWinner(element, currentPlayer)) {
            printBoarder(element);
            cout << currentPlayer << " Winner Winner Chicken Dinner\n";
            cout << "Wanna play again?";
            cin >> again;
            if (tolower(again) == 'y') beginning(element); else break;
        } else if (X_turn)
            currentPlayer = 'X';
        else currentPlayer = 'O';
    }
}

void printBoarder(char element[9]) {
    int counter = 0;
    for (int r = 0; r < 3; r++) {
        cout << "| ";
        for (int c = 0; c < 3; c++)
            cout << element[counter++] << " | ";
        cout << endl;
        for (int u = 0; u < 3 && r != 2; u++)
            cout << "|---";
        if (r != 2) cout << "|" << endl;
    }
}

void beginning(char element[9]) {
    for (int i = 0; i < 9; i++)
        element[i] = i + 49;
}

bool checkWinner(char element[9], char currentPlayer) {
    for (int r = 0; r < 7; r += 3)
        if (element[r] == element[r + 1] && element[r + 1] == element[r + 2] && element[r] == currentPlayer) {
            element[r] = '-';
            element[r + 1] = '-';
            element[r + 2] = '-';
            return true;
        }
    for (int c = 0; c < 3; c++)
        if (element[c] == element[c + 3] && element[c + 3] == element[c + 6] && element[c] == currentPlayer) {
            element[c] = '|';
            element[c + 3] = '|';
            element[c + 6] = '|';
            return true;
        }
    if (element[0] == element[4] && element[4] == element[8] && element[0] == currentPlayer) {
        element[0] = '\\';
        element[4] = '\\';
        element[8] = '\\';
        return true;
    }
    if (element[2] == element[4] && element[4] == element[6] && element[2] == currentPlayer) {
        element[2] = '/';
        element[4] = '/';
        element[6] = '/';
        return true;
    }
    return false;
}