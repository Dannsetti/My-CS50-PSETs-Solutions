//
//  generate.c
//  
//
//  Created by Daniel Sette on 03/11/2014.
//
//

/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // ask for argc as input, if provides none or more than 3 error message retun 1
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }
    
    // declare int n as a second command line argument argv[1] and convert into a int
    int n = atoi(argv[1]);
    
    // if argc equals 3, seed with a random positive int and convert it into a int
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }
    
    // while input is less than n increment i. Print out random int modulo LIMIT
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }
    
    // that's all folks
    return 0;
}