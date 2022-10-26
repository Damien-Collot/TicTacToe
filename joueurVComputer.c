#include "joueurVComputer.h"
#include "function.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void JvCMode1();
void JvCMode2();
int currentPlayer1 = 0;
int vJ = 0;
int vC = 0;
int draw1 = 0;

void initJvC(){
    srand(time(NULL));
    int should_run = 1;
    
    while (should_run == 1)
    {
        printf("\nVoulez vous une matrice 3x3(1) ou 5x5(2) ?\n");
        int mode;
        scanf("%d",&mode);
        while (mode != 1 && mode != 2)
        {
            printf("Paramêtre faux !!!");
            scanf("%d",&mode);
        }
        if (mode == 1){
            JvCMode1();
        } else {
            JvCMode2();
        }
        printf("J : %d,  C : %d,  Draw : %d\n",vJ,vC,draw1);
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

void JvCMode1(){
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
        if (currentPlayer1 == 0){
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
                table[i][j] = currentPlayer1;
                }
            }
        }

        afficheMatrice(table);

        if (countNumber == 8){
            isOver = win(table,currentPlayer1);
            if (isOver != true){
                isOver = true;
                printf("La partie se termine sur un nul\n");
                draw1++;
            } else {
                if (currentPlayer1 == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    vJ++;
                } else {
                    printf("L'ordinateur a gagné !!!!\n");
                    vC++;
                }
            }
            if (currentPlayer1 == 0){
                    currentPlayer1 = -1;
                } else {
                    currentPlayer1 = 0;
                }
        }
        else if (countNumber > 3){
            if(win(table,currentPlayer1) == true){
                if (currentPlayer1 == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    vJ++;
                    isOver = true;
                } else {
                    printf("L'ordinateur a gagné !!!!\n");
                    vC++;
                    isOver = true;
                }
                if (currentPlayer1 == 0){
                    currentPlayer1 = -1;
                } else {
                    currentPlayer1 = 0;
                }
            } else {
                countNumber++;
                if (currentPlayer1 == 0){
                    currentPlayer1 = -1;
                } else {
                    currentPlayer1 = 0;
                }
            }
        } else {
            if (currentPlayer1 == 0){
                currentPlayer1 = -1;
            } else {
                currentPlayer1 = 0;
            }
            countNumber++;
        }
    }
}

void JvCMode2(){
    bool isOver = false;
    int countNumber = 0;
    printf("\nVoici les coups possibles : \n");
    int table[5][5]= 
    {   
    { 1, 2, 3, 4, 5},
    { 6, 7, 8, 9, 10},
    { 11, 12, 13, 14, 15},
    { 16, 17, 18, 19, 20},
    { 21, 22, 23, 24, 25}
    };
    firstAffiche1(table);

    while (isOver == false){
        int rep;
        if (currentPlayer1 == 0){
            printf("Joueur 1 entrez un coup compris entre 1 et 9 et possible\n");
            scanf("%d",&rep);
            while (CheckCoup1(table,rep) != true)
            {
                scanf("%d",&rep);
            }
        } else {
            rep = rand() % 25 + 1;
            while (CheckCoupComputer1(table,rep) != true)
            {
                rep = rand() % 25 + 1;
            }
        }
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(table[i][j]==rep){
                table[i][j] = currentPlayer1;
                }
            }
        }

        afficheMatrice1(table);

        if (countNumber == 24){
            isOver = win1(table,currentPlayer1);
            if (isOver != true){
                isOver = true;
                printf("La partie se termine sur un nul\n");
                draw1++;
            } else {
                if (currentPlayer1 == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    vJ++;
                } else {
                    printf("L'ordinateur a gagné !!!!\n");
                    vC++;
                }
            }
            if (currentPlayer1 == 0){
                    currentPlayer1 = -1;
                } else {
                    currentPlayer1 = 0;
                }
        }
        else if (countNumber > 3){
            if(win1(table,currentPlayer1) == true){
                if (currentPlayer1 == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    vJ++;
                    isOver = true;
                } else {
                    printf("L'ordinateur a gagné !!!!\n");
                    vC++;
                    isOver = true;
                }
                if (currentPlayer1 == 0){
                    currentPlayer1 = -1;
                } else {
                    currentPlayer1 = 0;
                }
            } else {
                countNumber++;
                if (currentPlayer1 == 0){
                    currentPlayer1 = -1;
                } else {
                    currentPlayer1 = 0;
                }
            }
        } else {
            if (currentPlayer1 == 0){
                currentPlayer1 = -1;
            } else {
                currentPlayer1 = 0;
            }
            countNumber++;
        }
    }
}