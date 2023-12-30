#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int BOARD_SIZE = 3;

enum class GameState {
    NotFinished,
    Draw,
    WinnerX,
    WinnerO
};

GameState check_game_state(const vector<string>& board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? GameState::WinnerX : GameState::WinnerO;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j] == 'X' ? GameState::WinnerX : GameState::WinnerO;
        }
    }

    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 'X' ? GameState::WinnerX : GameState::WinnerO;
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 'X' ? GameState::WinnerX : GameState::WinnerO;
    }

    // Check if the game is not finished
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '-') {
                return GameState::NotFinished;
            }
        }
    }

    // If we get here, the game is a draw
    return GameState::Draw;
}

int main() {
    ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        cerr << "sth went wrong" << endl;
        return 1;
    }

    string line;
    vector<string> board(BOARD_SIZE, string(BOARD_SIZE, '-'));
    while (getline(input_file, line)) {
        if (line == "-----") {
            GameState game_state = check_game_state(board);
            switch (game_state) {
                case GameState::NotFinished:
                    cout << "Not finished." << endl;
                    break;
                case GameState::Draw:
                    cout << "Draw." << endl;
                    break;
                case GameState::WinnerX:
                    cout << "Winner: X." << endl;
                    break;
                case GameState::WinnerO:
                    cout << "Winner: O." << endl;
                    break;
            }
            board.assign(BOARD_SIZE, string(BOARD_SIZE, '-'));
        } else {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                board[line[2 * j] - '0'][j] = line[2 * j + 1];
            }
        }
    }

    input_file.close();

    return 0;
}
