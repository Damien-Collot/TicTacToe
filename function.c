#include "function.h"
#include<stdio.h>

void firstAffiche(int tableau[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("|%d|", tableau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void afficheMatrice(int tableau[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (tableau[i][j] == 0){
                printf("|X|");
            } else if (tableau[i][j] == -1){
                printf("|O|");
            } else {
                printf("| |");
            }
        }
        printf("\n");
    }
    printf("\n");
}