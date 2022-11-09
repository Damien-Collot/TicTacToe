#include "joueurVComputer.h"
#include "function.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void JvCMode1();
void JvCMode2();
void JvCMode3();
int currentPlayer1 = 0;
int vJ = 0;
int vC = 0;
int draw1 = 0;

void initJvC(){
    srand(time(NULL));
    int should_run = 1;
    
    while (should_run == 1)
    {
        printf("\nVoulez vous une matrice 3x3(1) ou 5x5(2) ou 7x7(3) ?\n");
        int mode;
        scanf("%d",&mode);
        while (mode != 1 && mode != 2 && mode != 3)
        {
            printf("Paramètre faux !!!");
            scanf("%d",&mode);
        }
        if (mode == 1){
            JvCMode1();
        } else if (mode == 2) {
            JvCMode2();
        } else {
            JvCMode3();
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
    int listCoupJoueur1[5];
    int listCoupJoueur2[5];
    int coupJ1 = 0;
    int coupJ2 = 0;
    int firstToPlay = currentPlayer1;
    printf("\nVoici les coups possibles : \n");
    int table[3][3] = 
    {
    { 1 , 2 , 3},
    { 4 , 5 , 6},
    { 7 , 8 , 9}
    };
    firstAffiche(3,table);

    while (isOver == false){
        int rep;
        if (currentPlayer1 == 0){
            printf("Joueur 1 entrez un coup compris entre 1 et 9 et possible\n");
            scanf("%d",&rep);
            while (CheckCoup(3, table,rep) != true)
            {
                scanf("%d",&rep);
            }
        } else {
            rep = rand() % 9 + 1;
            while (CheckCoupComputer(3, table,rep) != true)
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

        afficheMatrice(3, table);
        
        isOver = win(table,currentPlayer1);

        if (countNumber == 8){
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
            if(isOver == true){
                if (currentPlayer1 == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    vJ++;
                } else {
                    printf("L'ordinateur a gagné !!!!\n");
                    vC++;
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
    printf("Voulez vous sauvegarder ? oui(1) non(2)\n");
    int save;
    scanf("%d",&save);
    if (save == 1){
        saveGame(3,coupJ1, coupJ2, listCoupJoueur1,listCoupJoueur2, firstToPlay);
    }
}

void JvCMode2(){
    bool isOver = false;
    int countNumber = 0;
    int listCoupJoueur1[13];
    int listCoupJoueur2[13];
    int coupJ1 = 0;
    int coupJ2 = 0;
    int firstToPlay = currentPlayer1;
    printf("\nVoici les coups possibles : \n");
    int table[5][5]= 
    {   
    { 1, 2, 3, 4, 5},
    { 6, 7, 8, 9, 10},
    { 11, 12, 13, 14, 15},
    { 16, 17, 18, 19, 20},
    { 21, 22, 23, 24, 25}
    };
    firstAffiche(5, table);

    while (isOver == false){
        int rep;
        if (currentPlayer1 == 0){
            printf("Joueur 1 entrez un coup compris entre 1 et 9 et possible\n");
            scanf("%d",&rep);
            while (CheckCoup(5,table,rep) != true)
            {
                scanf("%d",&rep);
            }
        } else {
            rep = rand() % 25 + 1;
            while (CheckCoupComputer(5,table,rep) != true)
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

        afficheMatrice(5, table);
        
        isOver = win1(table,currentPlayer1);
        
        if (countNumber == 24){
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
                } else {
                    printf("L'ordinateur a gagné !!!!\n");
                    vC++;
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
    printf("Voulez vous sauvegarder ? oui(1) non(2)\n");
    int save;
    scanf("%d",&save);
    if (save == 1){
        saveGame(3,coupJ1, coupJ2, listCoupJoueur1,listCoupJoueur2, firstToPlay);
    }
}

void JvCMode3(){
    bool isOver = false;
    int countNumber = 0;
    int listCoupJoueur1[25];
    int listCoupJoueur2[25];
    int coupJ1 = 0;
    int coupJ2 = 0;
    int firstToPlay = currentPlayer1;
    printf("\nVoici les coups possibles : \n");
    int table[7][7]= 
    {   
    { 1, 2, 3, 4, 5, 6, 7},
    { 8, 9, 10, 11, 12, 13, 14},
    { 15, 16, 17, 18, 19, 20, 21},
    { 22, 23, 24, 25, 26, 27, 28},
    { 29, 30, 31, 32, 33, 34, 35},
    { 36, 37, 38, 39, 40, 41, 42},
    { 43, 44, 45, 46, 47, 48, 49}
    };
    firstAffiche(7, table);

    while (isOver == false){
        int rep;
        if (currentPlayer1 == 0){
            printf("Joueur 1 entrez un coup compris entre 1 et 9 et possible\n");
            scanf("%d",&rep);
            while (CheckCoup(7, table,rep) != true)
            {
                scanf("%d",&rep);
            }
        } else {
            rep = rand() % 49 + 1;
            while (CheckCoupComputer(7, table,rep) != true)
            {
                rep = rand() % 49 + 1;
            }
        }
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                if(table[i][j]==rep){
                table[i][j] = currentPlayer1;
                }
            }
        }

        afficheMatrice(7, table);
        
        isOver = win2(table,currentPlayer1);
        
        if (countNumber == 48){
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
        else if (countNumber > 6){
            if(win2(table,currentPlayer1) == true){
                if (currentPlayer1 == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    vJ++;
                } else {
                    printf("L'ordinateur a gagné !!!!\n");
                    vC++;
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
    printf("Voulez vous sauvegarder ? oui(1) non(2)\n");
    int save;
    scanf("%d",&save);
    if (save == 1){
        saveGame(3,coupJ1, coupJ2, listCoupJoueur1,listCoupJoueur2, firstToPlay);
    }
}
