#include <stdio.h>
#include <stdlib.h>
#include <conio.h>    // For _kbhit() and _getch() (Windows)
#include <windows.h>  // For Sleep()

#define WIDTH 40
#define HEIGHT 20

// Game state
int gameOver;
int score;
int x, y;              // Snake head position
int fruitX, fruitY;    // Food position
int tailX[100], tailY[100]; // Snake body segments
int nTail;             // Length of tail
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

// Setup initial game state
void Setup() {
    gameOver = 0;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
}

// Draw the game board
void Draw() {
    system("cls");  // Clear console (Windows). Use "clear" for Linux/Mac
    
    printf("=== SNAKE GAME ===  Score: %d\n", score);
    
    // Top border
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
    
    // Game area
    for (int i = 0; i < HEIGHT; i++) {
        printf("#"); // Left wall
        
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x)
                printf("O");  // Snake head
            else if (i == fruitY && j == fruitX)
                printf("*");  // Food
            else {
                int print = 0;
                // Check if this position is part of the tail
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");  // Snake body
                        print = 1;
                    }
                }
                if (!print) printf(" ");
            }
        }
        
        printf("#\n"); // Right wall
    }
    
    // Bottom border
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
    printf("Controls: W/A/S/D  |  X to quit\n");
}

// Handle keyboard input
void Input() {
    if (_kbhit()) {  // Check if key is pressed
        switch (_getch()) {
            case 'a': case 'A': if(dir != RIGHT) dir = LEFT; break;
            case 'd': case 'D': if(dir != LEFT) dir = RIGHT; break;
            case 'w': case 'W': if(dir != DOWN) dir = UP; break;
            case 's': case 'S': if(dir != UP) dir = DOWN; break;
            case 'x': case 'X': gameOver = 1; break;
        }
    }
}

// Game logic
void Logic() {
    // Move tail: each segment follows the one in front
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
    // Move head based on direction
    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default: break;
    }
    
    // Wall collision (game over version)
    // Uncomment below to die when hitting walls:
    /*
    if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
        gameOver = 1;
    */
    
    // Wall collision (wrap-around version - more fun!)
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;
    
    // Self collision
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    
    // Eat food
    if (x == fruitX && y == fruitY) {
        score += 10;
        nTail++;
        // Spawn new food (not on snake body)
        int valid;
        do {
            valid = 1;
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;
            for (int i = 0; i < nTail; i++) {
                if (tailX[i] == fruitX && tailY[i] == fruitY)
                    valid = 0;
            }
        } while (!valid);
    }
}

int main() {
    Setup();
    
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);  
    }
    
    printf("Game Over! Final Score: %d\n", score);
    return 0;
}