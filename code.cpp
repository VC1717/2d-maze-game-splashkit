#include "splashkit.h"

// Constants defining maze dimensions
const int MAZE_WIDTH = 15;
const int MAZE_HEIGHT = 15;
const int CELL_SIZE = 40;

// Define the structure for the player
struct Player {
    int x;
    int y;
};

// Function to check if a move is valid
bool is_valid_move(const char maze[MAZE_HEIGHT][MAZE_WIDTH], int x, int y) {
    return x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[y][x] != '#';
}

// Function to check if the player has won
bool has_won(const Player& player, const char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    return maze[player.y][player.x] == 'E';
}

// Function to check if the player has lost
bool has_lost(const Player& player, const char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    return maze[player.y][player.x] == 'T';
}

// Function to handle player input
void handle_input(Player& player, const char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    if (key_typed(RIGHT_KEY) && is_valid_move(maze, player.x + 1, player.y)) {
        player.x++;
    }
    else if (key_typed(LEFT_KEY) && is_valid_move(maze, player.x - 1, player.y)) {
        player.x--;
    }
    else if (key_typed(DOWN_KEY) && is_valid_move(maze, player.x, player.y + 1)) {
        player.y++;
    }
    else if (key_typed(UP_KEY) && is_valid_move(maze, player.x, player.y - 1)) {
        player.y--;
    }
}

// Function to draw the maze
void draw_maze(const char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int y = 0; y < MAZE_HEIGHT; ++y) {
        for (int x = 0; x < MAZE_WIDTH; ++x) {
            switch (maze[y][x]) {
                case '#':
                    fill_rectangle(COLOR_BLACK, x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                    break;
                case ' ':
                    fill_rectangle(COLOR_WHITE, x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                    break;
                case 'S':
                    fill_rectangle(COLOR_GREEN, x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                    break;
                case 'E':
                    fill_rectangle(COLOR_RED, x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                    break;
                case 'T':
                    fill_rectangle(COLOR_YELLOW, x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                    break;
            }
        }
    }
}

// Function to reset the player position
void reset_game(Player &player, int level) {
    player.x = 1;
    player.y = 1;
}

// Main function
int main() {
    // Open the game window
    open_window("2D Maze Game", MAZE_WIDTH * CELL_SIZE, MAZE_HEIGHT * CELL_SIZE);

    //Different Maze levels layout
    const char maze1[MAZE_HEIGHT][MAZE_WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', '#', 'T', ' ', '#', '#', '#', 'T', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', 'T', ' ', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', 'T', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', 'E', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', 'T', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    const char maze2[MAZE_HEIGHT][MAZE_WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', 'T', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', 'T', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', 'T', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    const char maze3[MAZE_HEIGHT][MAZE_WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', 'T', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', 'T', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', 'T', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', 'T', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', 'T', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Initialize player and current level
    Player player = {1, 1};
    int current_level = 1;
    const char (*current_maze)[MAZE_WIDTH];

    // Main game loop
    while (!window_close_requested("2D Maze Game")) {
        process_events();
        
        // Select the current maze based on the current level
        if (current_level == 1) {
            current_maze = maze1;
        } else if (current_level == 2) {
            current_maze = maze2;
        } else {
            current_maze = maze3;
        }

        // Handle player input
        handle_input(player, current_maze);
        
        // Clear the screen and draw the maze and player
        clear_screen(COLOR_WHITE);
        draw_maze(current_maze);
        fill_circle(COLOR_BLUE, (player.x * CELL_SIZE) + CELL_SIZE / 2, (player.y * CELL_SIZE) + CELL_SIZE / 2, CELL_SIZE / 3);

        // Check if the player has won or lost
        if (has_won(player, current_maze)) {
            if (current_level < 3) {
                // If the player has won and there are more levels, display a message and move to the next level
                draw_text("Level Complete!", COLOR_WHITE, 20, 20);
                refresh_screen(60);
                delay(2000); // wait for 2 seconds
                current_level++;
                reset_game(player, current_level);
            } else {
                // If the player has won all levels, display a winning message and exit the loop
                draw_text("You Win the Game!", COLOR_WHITE, 20, 20);
                refresh_screen(60);
                delay(2000); // wait for 2 seconds
                break; // Exit the while loop if all mazes are completed
            }
        } else if (has_lost(player, current_maze)) {
            // If the player has lost, display a message and reset the game
            draw_text("You Lose!", COLOR_WHITE, 20, 20);
            refresh_screen(60);
            delay(2000); // wait for 2 seconds
            reset_game(player, current_level);
        }

        // Refresh the screen
        refresh_screen(60);
    }

    // Close the game window
    close_window("2D Maze Game");
    return 0;
}
