#include <iostream>
#include <vector>

using namespace std;

vector<int> board(9, 0);
int analyzeBoard();
void printBoard();
void playerTurn(int, int);
int minimax(int, int);
void computerTurn();
void showInstructions();

void printBoard() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 9; i++) {
        cout << (board[i] == 0 ? "_" : (board[i] == -1 ? "X" : "O")) << " ";
        if (i % 3 == 2) cout << "\n";
    }
    cout << endl;
}

void playerTurn(int player, int symbol) {
    int pos;
    cout << "Enter " << (symbol == -1 ? "X" : "O") << "'s position (1-9): ";
    cin >> pos;
    if (pos < 1 || pos > 9 || board[pos - 1] != 0) {
        cout << "Invalid move. Try again.\n";
        playerTurn(player, symbol);
    } else board[pos - 1] = symbol;
}

int minimax(int player, int symbol) {
    int score = analyzeBoard();
    if (score != 0) return score * symbol;

    int bestScore = -2;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = symbol;
            int tempScore = -minimax(player, -symbol);
            board[i] = 0;
            if (tempScore > bestScore) bestScore = tempScore;
        }
    }
    return (bestScore == -2) ? 0 : bestScore;
}

void computerTurn() {
    int bestScore = -2, bestMove = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = 1;
            int score = -minimax(0, -1);
            board[i] = 0;
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    board[bestMove] = 1;
}

int analyzeBoard() {
    int winLines[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for (auto &line : winLines) {
        if (board[line[0]] != 0 && board[line[0]] == board[line[1]] && board[line[0]] == board[line[2]])
            return board[line[0]];
    }
    return 0;
}

void showInstructions() {
    cout << "Tic-Tac-Toe Instructions:\n";
    cout << "Positions:\n 1 | 2 | 3 \n 4 | 5 | 6 \n 7 | 8 | 9 \n\n";
}

int main() {
    int choice;
    cout << "1. Show Instructions\n2. Play vs Computer\n3. Play vs Friend\n4. Exit\nChoice: ";
    cin >> choice;
    
    if (choice == 1) {
        showInstructions();
        main();
    } else if (choice == 4) return 0;

    int playerSymbol = (choice == 2) ? -1 : 0;
    for (int turn = 0; turn < 9 && analyzeBoard() == 0; turn++) {
        printBoard();
        if (choice == 2 && (turn + playerSymbol) % 2 == 0) computerTurn();
        else playerTurn((turn % 2 == 0 ? 1 : 2), (turn % 2 == 0 ? -1 : 1));
    }

    printBoard();
    int result = analyzeBoard();
    if (result == 0) cout << "It's a draw!\n";
    else cout << "Player " << (result == -1 ? "X" : "O") << " wins!\n";
    return main();
}