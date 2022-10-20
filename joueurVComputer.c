#include "joueurVComputer.h"
#include "function.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initJvC(){
    srand(time(NULL));
    int currentPlayer = 0;
    int should_run = 1;
    int vJ = 0;
    int vC = 0;
    int draw = 0;

    while (should_run == 1)
    {
        bool isOver = false;
        int countNumber = 0;
        printf("\nVoici les coups possibles : \n");
        int table[3][3] = 
        {
        { 1 , 2 , 3},
        { 4 , 5 , 6},
        { 7 , 8 , 9}
        };
        firstAffiche(table);

        while (isOver == false){
            int rep;
            if (currentPlayer == 0){
                printf("Joueur 1 entrez un coup compris entre 1 et 9 et possible\n");
                scanf("%d",&rep);
                while (CheckCoup(table,rep) != true)
                {
                    scanf("%d",&rep);
                }
            } else {
                rep = rand() % 9 + 1;
                while (CheckCoupComputer(table,rep) != true)
                {
                    rep = rand() % 9 + 1;
                }
            }
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(table[i][j]==rep){
                    table[i][j] = currentPlayer;
                    }
                }
            }

            afficheMatrice(table);

            if (countNumber == 8){
                isOver = win(table,currentPlayer);
                if (isOver != true){
                    isOver = true;
                    printf("La partie se termine sur un nul\n");
                    draw++;
                } else {
                    if (currentPlayer == 0){
                        printf("Le joueur 1 a gagné !!!!\n");
                        vJ++;
                    } else {
                        printf("L'ordinateur a gagné !!!!\n");
                        vC++;
                    }
                }
                if (currentPlayer == 0){
                        currentPlayer = -1;
                    } else {
                        currentPlayer = 0;
                    }
            }
            else if (countNumber > 3){
                if(win(table,currentPlayer) == true){
                    if (currentPlayer == 0){
                        printf("Le joueur 1 a gagné !!!!\n");
                        vJ++;
                        isOver = true;
                    } else {
                        printf("L'ordinateur a gagné !!!!\n");
                        vC++;
                        isOver = true;
                    }
                    if (currentPlayer == 0){
                        currentPlayer = -1;
                    } else {
                        currentPlayer = 0;
                    }
                } else {
                    countNumber++;
                    if (currentPlayer == 0){
                        currentPlayer = -1;
                    } else {
                        currentPlayer = 0;
                    }
                }
            } else {
                if (currentPlayer == 0){
                    currentPlayer = -1;
                } else {
                    currentPlayer = 0;
                }
                countNumber++;
            }
        }
        printf("J : %d,  C : %d,  Draw : %d\n",vJ,vC,draw);
        printf("Voulez vous rejouer ? oui(1) non(2)\n");
        int answer;
        scanf("%d",&answer);
        if (answer != 1){
            should_run = 0;
            if (vJ > vC ){
                printf("Le joueur 1 a été le meilleur gg à lui\n");
            } else if (vJ == vC){
                printf("Vous êtes à égalité avec l'ordinateur\n");
            } else {
                printf("L'ordinateur a été le meilleur gg à lui\n");
            }
        }
    }
}