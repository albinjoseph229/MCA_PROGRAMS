#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h> // add this line

#define WIDTH 20
#define HEIGHT 10

typedef struct {
    bool visited;
    bool north_wall;
    bool south_wall;
    bool east_wall;
    bool west_wall;
} Cell;

typedef struct {
    Cell cells[HEIGHT][WIDTH];
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} Maze;

void init_maze(Maze* maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze->cells[i][j].visited = false;
            maze->cells[i][j].north_wall = true;
            maze->cells[i][j].south_wall = true;
            maze->cells[i][j].east_wall = true;
            maze->cells[i][j].west_wall = true;
        }
    }
}

void generate_maze(Maze* maze, int x, int y) {
    maze->cells[y][x].visited = true;

    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int direction = directions[i];
        int new_x = x;
        int new_y = y;
        switch (direction) {
            case 0: // North
                if (y > 0 && !maze->cells[y-1][x].visited) {
                    maze->cells[y][x].north_wall = false;
                    maze->cells[y-1][x].south_wall = false;
                    new_y--;
                    generate_maze(maze, new_x, new_y);
                }
                break;
            case 1: // South
                if (y < HEIGHT-1 && !maze->cells[y+1][x].visited) {
                    maze->cells[y][x].south_wall = false;
                    maze->cells[y+1][x].north_wall = false;
                    new_y++;
                    generate_maze(maze, new_x, new_y);
                }
                break;
            case 2: // East
                if (x < WIDTH-1 && !maze->cells[y][x+1].visited) {
                    maze->cells[y][x].east_wall = false;
                    maze->cells[y][x+1].west_wall = false;
                    new_x++;
                    generate_maze(maze, new_x, new_y);
                }
                break;
            case 3: // West
                if (x > 0 && !maze->cells[y][x-1].visited) {
                    maze->cells[y][x].west_wall = false;
                    maze->cells[y][x-1].east_wall = false;
                    new_x--;
                    generate_maze(maze, new_x, new_y);
                }
                break;
        }
    }
}

void print_maze(Maze* maze) {
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("--+");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (maze->cells[i][j].south_wall) {
                printf("  |");
            } else {
                printf("   ");
            }
        }
        printf("\n");

        printf("+");
        for (int j = 0; j < WIDTH; j++) {
            if (maze->cells[i][j].east_wall) {
                printf("--+");
            } else {
                printf("  +");
            }
        }
        printf("\n");
    }
}

void navigate_maze(Maze* maze) {
    int x = maze->start_x;
    int y = maze->start_y;

    while (x != maze->end_x || y != maze->end_y) {
        system("cls");
        print_maze(maze);

        printf("Use arrow keys to move. Press enter to continue.\n");

        int input = getchar();
        while (input != '\n') {
            input = getchar();
        }

        switch (getch()) {
            case 72: // Up arrow
                if (!maze->cells[y][x].north_wall) {
                    y--;
                }
                break;
            case 80: // Down arrow
                if (!maze->cells[y][x].south_wall) {
                    y++;
                }
                break;
            case 77: // Right arrow
                if (!maze->cells[y][x].east_wall) {
                    x++;
                }
                break;
            case 75: // Left arrow
                if (!maze->cells[y][x].west_wall) {
                    x--;
                }
                break;
        }
    }

    system("cls");
    print_maze(maze);
    printf("Congratulations, you made it to the end!\n");
}

int main() {
    srand(time(NULL));

    Maze maze;
    init_maze(&maze);
    generate_maze(&maze, rand() % WIDTH, rand() % HEIGHT);

    maze.start_x = rand() % WIDTH;
    maze.start_y = rand() % HEIGHT;
    maze.end_x = rand() % WIDTH;
    maze.end_y = rand() % HEIGHT;

    navigate_maze(&maze);

    return 0;
}
