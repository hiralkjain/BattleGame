#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 30

int x,y,targetx,targety,gameover=0,score=0,bulletx,bullety,active;

void printPosition(int x,int y, int bulletx,int bullety) {
    system("clear");  // Clear the console (works on Unix-based systems)
    
    // Print the grid
    for (int i = HEIGHT; i >= 0; i--) {
        if (i == y) {
            // Print the rocket's position
            for (int j = 0; j < x; j++) {
                printf(" ");
            }
            printf("^ Rocket\n");
        } else if (i == bullety) {
            // Print the bullet's position
            for (int j = 0; j < bulletx; j++) {
                printf(" ");
            }
            printf("o Bullet\n");
        } else {
            printf("\n");  // Empty line
        }
    }
}
void setup()
{
    gameover = 0;
    score=0;
    srand(time(NULL));
    targetx = rand() % WIDTH;
    targety = rand() % (HEIGHT-2);
    x=WIDTH/2;
    y=HEIGHT-3;
}
void Draw() {
    system("cls");  // Clear console

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
            {
                printf("A\n");
            }
            else if (i == targety && j == targetx)
                printf("*");
                else if(i==bulletY && j == bulletX)
                 printf("|");
                else
                printf(" ");
            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
     printf("Score: %d\n", score);
}

void Game()
{
   if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        case 'w':
        if(!active)
        {
         active=1;
         bulletx= x;
         bullety = y-1;
        }
        
        break;
        case 'x':
            gameOver = 1;
            break;
        }
    }   
}
void Logic()
{
    if(active)
    {
        bullety--;
         if (bulletY < 0) 
            active = 0;
            else if(bulletY == y && bulletX == x)
            {
            score += 10;
            active = 0;
            x = rand() % WIDTH;
            y = rand() % (HEIGHT - 2);
            }
    }
}
void main()
{
    setup();
    while(!gameover){
    Draw();
    Game();
    Logic();
    }
}