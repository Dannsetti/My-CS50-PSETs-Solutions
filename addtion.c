//
//  addtion.c
//  
//
//  Created by Daniel Sette on 23/08/2014.
//
//
#include <stdio.h>

int main (void)

{
    //discover the value of c
    int a, b, c;
    //ask for an integer = a
    printf("Enter the first value:");
    scanf("%i" , &a);
    //ask gor another integer = b
    printf("Enter the second value:");
    scanf("%i" , &b);
    //add both values to get = c
    c = a + b;
    printf("%i + %i = %i\n", a, b, c);
}