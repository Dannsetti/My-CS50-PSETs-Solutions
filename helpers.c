//
//  helpers.c
//  
//
//  Created by Daniel Sette on 03/11/2014.
//
//

/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <string.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
    // implement a searching algorithm
    
    // save bounds of list
    int beginning = 0;
    int end = n-1;
    
    // while length of list > 0
    while (beginning <= end)
    {
        // look at middle of list
        int middle = (beginning + end) / 2;
        if (values[middle] == value)
        {
            // if number found, return true
            return true;
        }
        
        // else if middle higher, search left
        else if (values[middle] > value)
        {
            end = middle - 1;
        }
        
        // else if middle lower, search right
        else
        {
            beginning = middle + 1;
        }
    }
    
    // return false
    return false;
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    //implement an O(n^2) sorting algorithm
    for (int i = 0; i < n; i++)
    {
        int location = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (values[i] > values[j])
            {
                values[i] = values[j];
                location = j;
            }
        }
        values[location] = values[i];
        
        values [i] = values [i];
        
    }
    return;
}