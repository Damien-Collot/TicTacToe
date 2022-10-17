#include<stdio.h>
#include "function.h"
#include "joueurVJoueur.h"

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
        initJvJ();
    } else if (rep == 2){
        printf("Mode Joueur contre ordinateur sélectionné\n");
    } else {
        printf("Mode ordinateur contre ordinateur sélectionné\n");
        printf("Entrez le nombre de simulation que vous souhaitez");
        scanf("%d",&rep);
    }

    return 1;

}