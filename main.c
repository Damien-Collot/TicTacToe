#include<stdio.h>
#include "function.h"

int main(){

    int table[3][3] = 
    {
    { 1 , 2 , 3},
    { 4 , 5 , 6},
    { 7 , 8 , 9}
    };

    firstAffiche(table);

    table[0][2] = 0;
    table[0][1] = -1;
    table[1][2] = 0;

    afficheMatrice(table);

    return 1;

}