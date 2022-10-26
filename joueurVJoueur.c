#include "joueurVJoueur.h"
#include "function.h"
#include <stdbool.h>
#include <stdio.h>

void JvJMode1();
void JvJMode2();
void JvJMode3();
int currentPlayer = 0;
int vJ1 = 0;
int vJ2 = 0;
int draw = 0;

void initJvJ(){
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
            JvJMode1();
        } else {
            JvJMode2();
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

void JvJMode1(){
    bool isOver = false;
    int countNumber = 0;
    printf("Voici les coups possibles : \n");
    int table[3][3] = 
        {
        { 1 , 2 , 3},
        { 4 , 5 , 6},
        { 7 , 8 , 9}
        };
    firstAffiche(3, table);
    while (isOver == false)
    {
        if (currentPlayer == 0){
            printf("Joueur 1 entrez un coup\n");
        } else {
            printf("Joueur 2 entrez un coup\n");
        }
        int rep;
        scanf("%d",&rep);
        while (CheckCoup(3, table,rep) != true)
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

        afficheMatrice(3, table);

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
                    vJ1++;
                    isOver = true;
                } else {
                    printf("Le joueur 2 a gagné !!!!\n");
                    vJ2++;
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
}

void JvJMode2(){
    bool isOver = false;
    int countNumber = 0;
    printf("Voici les coups possibles : \n");
    int table[5][5]= 
    {
        { 1, 2, 3, 4, 5},
        { 6, 7, 8, 9, 10},
        { 11, 12, 13, 14, 15},
        { 16, 17, 18, 19, 20},
        { 21, 22, 23, 24, 25}
    };
    firstAffiche(5, table);
    while (isOver == false)
    {
        if (currentPlayer == 0){
            printf("Joueur 1 entrez un coup\n");
        } else {
            printf("Joueur 2 entrez un coup\n");
        }
        int rep;
        scanf("%d",&rep);
        while (CheckCoup(5, table,rep) != true)
        {
            fflush(stdout);
            scanf("%d",&rep);
        }
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(table[i][j]==rep){
                table[i][j] = currentPlayer;
                }
            }
        }

        afficheMatrice(5, table);

        if (countNumber == 24){
            isOver = win1(table,currentPlayer);
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
            if (currentPlayer == 0){
                    currentPlayer = -1;
                } else {
                    currentPlayer = 0;
                }
        }
        else if (countNumber > 3){
            if(win1(table,currentPlayer) == true){
                if (currentPlayer == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    vJ1++;
                    isOver = true;
                } else {
                    printf("Le joueur 2 a gagné !!!!\n");
                    vJ2++;
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
}

void JvJMode3(){
        bool isOver = false;
    int countNumber = 0;
    printf("Voici les coups possibles : \n");
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
    while (isOver == false)
    {
        if (currentPlayer == 0){
            printf("Joueur 1 entrez un coup\n");
        } else {
            printf("Joueur 2 entrez un coup\n");
        }
        int rep;
        scanf("%d",&rep);
        while (CheckCoup(7, table,rep) != true)
        {
            scanf("%d",&rep);
        }
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                if(table[i][j]==rep){
                table[i][j] = currentPlayer;
                }
            }
        }

        afficheMatrice(7, table);

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
            if (currentPlayer == 0){
                    currentPlayer = -1;
                } else {
                    currentPlayer = 0;
                }
        }
        else if (countNumber > 7){
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
}