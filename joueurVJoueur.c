#include "joueurVJoueur.h"
#include "function.h"
#include <stdbool.h>
#include <stdio.h>

void initJvJ(){
    int currentPlayer = 0;
    int should_run = 1;
    int vJ1 = 0;
    int vJ2 = 0;
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

        while (isOver == false)
        {
            if (currentPlayer == 0){
                printf("Joueur 1 entrez un coup compris entre 1 et 9 et possible\n");
            } else {
                printf("Joueur 2 entrez un coup compris entre 1 et 9 et possible\n");
            }
            int rep;
            scanf("%d",&rep);
            while (CheckCoup(table,rep) != true)
            {
                scanf("%d",&rep);
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
                        vJ1++;
                    } else {
                        printf("Le joueur 2 a gagné !!!!\n");
                        vJ2++;
                    }
                }
            }
            else if (countNumber > 3){
                if(win(table,currentPlayer) == true){
                    if (currentPlayer == 0){
                        printf("Le joueur 1 a gagné !!!!\n");
                        vJ1++;
                        isOver = true;
                    } else {
                        printf("Le joueur 2 a gagné !!!!\n");
                        vJ2++;
                        isOver = true;
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
        printf("J1 : %d,  J2 : %d,  Draw : %d\n",vJ1,vJ2,draw);
        printf("Voulez vous rejouer ? oui(1) non(2)\n");
        int answer;
        scanf("%d",&answer);
        if (answer != 1){
            should_run = 0;
            if (vJ1 > vJ2 ){
                printf("Le joueur 1 a été le meilleur gg à lui\n");
            } else if (vJ1 == vJ2){
                printf("Les deux joueurs ont autant gagné l'un que l'autre on s'emmerde\n");
            } else {
                printf("Le joueur 2 a été le meilleur gg à lui\n");
            }
        }
    }
}