//
//  fifteen.c
//  
//
//  Created by Daniel Sette on 03/11/2014.
//
//

/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();
    
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }
    
    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               MIN, MIN, MAX, MAX);
        return 2;
    }
    
    // initialize the board
    init();
    
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();
        
        // draw the current state of the board
        draw();
        
        // saves the current state of the board (for testing)
        save();
        
        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }
        
        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
        
        // sleep for animation's sake
        usleep(500000);
    }
    
    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // declare descend for descendent number
    int descend = (d * d) - 1;
    // declare odd for odd board
    int odd = (descend % 2) ;
    
    // loop board row and column
    for (int i = 0; i < d; i++)
    {
        
        for (int j = 0; j < d; j++)
        {
            board[i][j] = descend;
            descend--;
            
        }
        // if there is an odd number of column
        if (odd != 0)
        {
            int tmp = board[d - 1][d - 2];
            board[d - 1][d - 2] = board[d - 1][d - 3];
            board[d - 1][d - 3] = tmp;
            
        }
        
    }
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // loop for board row and column
    for (int i = 0; i < d; i++)
    {
        
        for (int j = 0; j < d; j++)
        {
            // declare char for blank int
            char space = '_';
            
            // if location is equal 0
            if (board[i][j] == 0)
            {
                printf("  ");
                printf("%2c", space);
            }
            else
            {
                printf("  ");
                printf("%2d", board[i][j]);
                
            }
            
        }
        printf("\n\n");
        
    }
    printf("\n");
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */

bool move(int tile)
{
    // declare ints for inicial location
    int tile_i = -1;
    int tile_j = -1;
    int blank_i = -1;
    int blank_j = -1;
    
    // loop to find the position
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // board position of the tile
            if (board[i][j] == tile)
            {
                tile_i = i;
                tile_j = j;
            }
            // board position blank tile
            else if (board[i][j] == 0)
            {
                blank_i = i;
                blank_j = j;
            }
        }
    }
    // check if tile was found, retun false if not
    if(tile_i == -1 && tile_j == -1)
    {
        return false;
    }
    //declare dif as the differnce of coordinates blank and tile
    int dif_i = blank_i - tile_i;
    int dif_j = blank_j - tile_j;
    
    //if check if the distance is grater than 1 or if the moviment diriction is legal
    if((dif_i > 1 || dif_i < -1) || (dif_j > 1 || dif_j < -1) || (dif_i == -1 && dif_j == -1) || (dif_i == 1 && dif_j == 1) || (dif_i == -1 && dif_j == 1) || (dif_i == 1 && dif_j == -1))
        
    {
        return false;
    }
    
    // if move is legal do swap
    else
    {
        board[blank_i][blank_j] = tile;
        board[tile_i][tile_j] = 0;
        
        return true;
    }
    
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // declare varible win
    int win = 1;
    
    // loop to find position row and column
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // if board is equal win increment 1
            if(board[i][j] == win)
            {
                win++;
                
                // if win is equal board position and blank is equal 0 return true
                if(win == (d * d -1) && board[d - 1][d - 1] == 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";
    
    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }
    
    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }
    
    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");
    
    // close log
    fclose(p);
}