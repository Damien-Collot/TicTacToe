#include<stdio.h>
#include "function.h"
#include "joueurVJoueur.h"
#include "joueurVComputer.h"
#include "essai.h"

int main(){
    printf("-----------TicTacToe-----------\n");
    printf("Choississez votre mode de jeu : \n");
    printf("Joueur contre Joueur(1)\n");
    printf("Joueur contre Ordinateur(2)\n");
    printf("Ordinateur contre Ordinateur(3)\n");
    printf("Simuler une partie sauvegardée(4)\n");
    int rep;
    scanf("%d",&rep);

    if (rep < 1 || rep > 4){
        while (rep < 1 || rep > 4)
        {
            printf("Veuillez entrer une option valide !!!\n");
            scanf("%d",&rep);
        }
    }
    printf("------------------------------------\n");
    if (rep == 1){
        printf("Mode Joueur contre Joueur sélectionné\n");
        initJvJ();
    } else if (rep == 2){
        printf("Mode Joueur contre ordinateur sélectionné\n");
        initJvC();
    } else if (rep == 3){
        printf("Mode ordinateur contre ordinateur sélectionné\n");
        initi();
    } else {
        readGame();
    }

    return 1;
}
