//
//  change_coins.c
//  Program to give the right amount of coins
//  with the less number possible
//
//  Created by Daniel Sette on 27/08/2014.
//
//

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    //declare float money to get decimal numbers
    float money;
    
    //ask the user for a positive value otherwise ask again
    do
    {
        printf("How much change is owed?\n");
        money = GetFloat();
    }
    
    while (money <= 0);
    
    //declare integer change to transform the float in int.
    int change;
    //use roundf for a better accuracy
    change = roundf(money * 100);
    //declare counter to get the number of coins starting from 0
    int counter = 0;
    
    //while loop for each type of coin
    while (change >= 25)
    {
        //add 1 to the counter
        counter ++;
        //deduce the value of the coin from the change
        change = change - 25;
    }
    
    while (change >= 10)
    {
        counter ++;
        change = change - 10;
        
    }
    
    while (change >= 5)
        
    {
        counter ++;
        change = change - 5;
        
    }
    while (change >= 1)
        
    {
        counter ++;
        change = change - 1;
        
    }
    
    //print the number of coins collect in counter
    printf("%d\n", counter);
    
}