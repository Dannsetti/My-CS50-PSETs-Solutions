//
//  vigenere.c
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
        printf("Not acceptable Key, please provide only one key word\n");
        return 1;
    }
    
    // k is the second line arg
    int kl = strlen(argv[1]);
    string k = argv[1];
    char key;
    for (int j = 0; j < kl; j++)
        
        if (isalpha(k[j]))
        {
            if (isupper(k[j]))
            {
                key = (k[j] - 'A');
            }
            
            else if (islower(k[j]))
            {
                key = (k[j] - 'a');
            }
            else
            {
                key = (k[j]);
            }
            continue;
        }
        else
        {
            printf("Please provide alphabetical input only\n");
            return 1;
        }
    //declare string p to get the user text
    
    //declare char c for ciphertext
    char c;
    string p = GetString();
    
    //condition for the lenght of user input
    for (int i = 0, k = 0, n = strlen(p); i < n; i++)
    {
        //condition for lower cases
        if (islower(p[i]))
        {
            //switch ASCII value to alphabetical and vice versa
            c = (((p[i] - 'a') + (key[k % kl])) % 26) + 'a';
            //print encrypted text
   	        printf("%c", c);
        }
        //condition for capital letters
        else if (isupper(p[i]))
        {
            //switch ASCII value to alphabetical and vice versa
            c = (((p[i] - 'A') + (key[k % kl])) % 26) + 'A';
            //print encrypted text
   	        printf("%c", c);
        }
        else
        {
            
            //Print out non ciphered input
            printf("%c", p[i]);
        }
        
    }
    
}