//
//  mario 2 pyramids.c
//  print 2 half pyramid with 2 spaces between them
//
//  Created by Daniel Sette on 29/08/2014.
//
//

#include <stdio.h>
#include <cs50.h>

int main (void)

{
    //Declare height = h
    int h = 0-23;
    
    //Prompt user for an positive interger no greater than 23
    //Do again and again untill get a number in the range 0 to 23
    do
    {
        
        printf("Give me a integer for Mario's pyramid height:\n");
        h = GetInt();
    }
    while (h < 0 || h > 23);
    
    //Draw the pyramid
    //Declare int i as condition for the loop
    for (int i = 0; i < h; i++)
    {
        //declare space inside of the loop
        for(int spaces = 0; spaces < h-(i+1); spaces++)
        {
            printf(" ");
            
        }
        //declare haches for firsthalf inside of the loop
        for(int first_half = 0; first_half < i+1; first_half++)
        {
            printf("#");
            
        }
        //print 2 spaces between pyramids
        {
            printf("  ");
        }
        //declare second half inside of the loop
        for (int sec_half = 0; sec_half < i+1; sec_half++)
        {
            printf("#");
        }
        //new line
        {
            printf("\n");
        }
    }
    
}