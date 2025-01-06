#include "raylib.h"  // Include Raylib library for graphics and input handling
#include <vector>      // Include vector for storing game board
#include <string>      // Include string for displaying messages

// Constants for the game
const int SCREEN_WIDTH = 600;       // Screen width
const int SCREEN_HEIGHT = 600;      // Screen height
const int GRID_SIZE = 3;            // Number of rows and columns in the grid
const int CELL_SIZE = SCREEN_WIDTH / GRID_SIZE; // Size of each cell in the grid

// Enum for game states
enum GameState {
    PLAYING,    // The game is ongoing
    PLAYER_X_WINS, // Player X has won
    PLAYER_O_WINS, // Player O has won
    DRAW        // The game is a draw
};

// Function to check for a winner or a draw
GameState CheckGameState(const std::vector<std::vector<char>>& board) {
    // Check rows and columns for a win
    for (int i = 0; i < GRID_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0] == 'X' ? PLAYER_X_WINS : PLAYER_O_WINS;

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i] == 'X' ? PLAYER_X_WINS : PLAYER_O_WINS;
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0] == 'X' ? PLAYER_X_WINS : PLAYER_O_WINS;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2] == 'X' ? PLAYER_X_WINS : PLAYER_O_WINS;

    // Check for a draw (no empty cells)
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (board[i][j] == ' ')
                return PLAYING; // Game is still ongoing
        }
    }

    return DRAW; // No winner and no empty cells, so it's a draw
}

// Function to draw the game board
void DrawBoard(const std::vector<std::vector<char>>& board) {
    // Draw the grid lines
    for (int i = 1; i < GRID_SIZE; i++) {
        DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, SCREEN_HEIGHT, WHITE); // Vertical lines
        DrawLine(0, i * CELL_SIZE, SCREEN_WIDTH, i * CELL_SIZE, WHITE); // Horizontal lines
    }

    // Draw the X and O marks
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            Vector2 position = { j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2 };

            if (board[i][j] == 'X') {
                DrawText("X", position.x - 20, position.y - 20, 40, RED);
            }
            else if (board[i][j] == 'O') {
                DrawText("O", position.x - 20, position.y - 20, 40, BLUE);
            }
        }
    }
}

// Main function
int main() {
    // Initialize Raylib
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic Tac Toe");
    SetTargetFPS(60);

    // Initialize the game board with empty cells
    std::vector<std::vector<char>> board(GRID_SIZE, std::vector<char>(GRID_SIZE, ' '));

    char currentPlayer = 'X';      // The current player ('X' or 'O')
    GameState gameState = PLAYING; // The current state of the game

    // Main game loop
    while (!WindowShouldClose()) {
        // Handle player input
        if (gameState == PLAYING && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int col = mousePosition.x / CELL_SIZE;

            // Place the current player's mark if the cell is empty
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;

                // Check for a winner or a draw
                gameState = CheckGameState(board);

                // Switch to the other player if the game is still ongoing
                if (gameState == PLAYING) {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the game board
        DrawBoard(board);

        // Display the game state
        if (gameState == PLAYER_X_WINS) {
            DrawText("Player X Wins!", 200, SCREEN_HEIGHT / 2 - 20, 40, GREEN);
        }
        else if (gameState == PLAYER_O_WINS) {
            DrawText("Player O Wins!", 200, SCREEN_HEIGHT / 2 - 20, 40, GREEN);
        }
        else if (gameState == DRAW) {
            DrawText("It's a Draw!", 230, SCREEN_HEIGHT / 2 - 20, 40, YELLOW);
        }
        else {
            DrawText(TextFormat("Current Player: %c", currentPlayer), 10, 10, 20, WHITE);
        }

        EndDrawing(); // End drawing
    }

    // Close Raylib
    CloseWindow();

    return 0;
}
