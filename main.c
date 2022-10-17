#include<stdio.h>
#include "function.h"

int main(){
    printf("-----------TicTacToe-----------\n");
    printf("Choissisez votre mode de jeu : \n");
    printf("Joueur contre Joueur(1)\n");
    printf("Joueur contre Ordinateur(2)\n");
    printf("Ordinateur contre Ordinateur(3)\n");
    int rep;
    scanf("%d",&rep);

    if (rep < 1 || rep > 3){
        while (rep < 1 || rep > 3)
        {
            printf("Veuillez entrez une option valide !!!\n");
            scanf("%d",&rep);
        }
    }
    printf("------------------------------------\n");

    if (rep == 1){
        printf("Mode Joueur contre Joueur sélectionné\n");
    } else if (rep == 2){
        printf("Mode Joueur contre ordinateur sélectionné\n");
    } else {
        printf("Mode ordinateur contre ordinateur sélectionné\n");
        printf("Entrez le nombre de simulation que vous souhaitez");
        scanf("%d",&rep);
    }

    int table[3][3] = 
    {
    { 1 , 2 , 3},
    { 4 , 5 , 6},
    { 7 , 8 , 9}
    };

    return 1;

}