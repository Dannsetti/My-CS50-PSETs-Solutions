//
//  caeser.c
//  
//
//  Created by Daniel Sette on 05/10/2014.
//
//

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//declere main accepting command line argument
int main (int argc, string argv[])
{
    // with uses more than 2 give an error message and quit
    if (argc != 2)
    {
        printf("Not acceptable Key, please provide a non negative interger for the key\n");
        return 1;
    }
    // k is the second line arg
    int k = atoi(argv[1]);
    
    //declare string p to get the user text
    string p = GetString();
    
    //declare char c for ciphertext
    char c;
    
    //condition for the lenght of user input
    for (int i = 0 , n = strlen(p); i < n; i++)
    {
        //condition for lower cases
        if (islower(p[i]))
        {
            //switch ASCII value to alphabetical and vice versa
            c = (((p[i] - 97) + k) % 26) + 97;
            //print encrypted text
   	        printf("%c", c);
        }
        //condition for capital letters
        else if (isupper(p[i]))
        {
            //switch ASCII value to alphabetical and vice versa
            c = (((p[i] - 65) + k) % 26) + 65;
            //print encrypted text
   	        printf("%c", c);
        }
        else
        {
            //Print out non ciphered input
            printf("%c", p[i]);
        }
        
    }
    //new line
    printf("\n");
}