#include "function.h"
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void firstAffiche(int n, int tableau[n][n]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("|%d|", tableau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void afficheMatrice(int n, int tableau[n][n]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
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

bool win(int tab[3][3], int joueur)
{
  //test pour les lignes
  for(int i=0;i<3;i++)
  {
    if(tab[i][0]==joueur && tab[i][0]==tab[i][1] && tab[i][1]==tab[i][2])
    {
      return true;
    }
  }
  
  //test pour les colonnes
  for(int i=0;i<3;i++)
  {
    if(tab[0][i]==joueur && tab[0][i]==tab[1][i] && tab[1][i]==tab[2][i])
    {
      return true;
    }
  }
  
  //test pour les diagonales
  if(tab[0][0]==joueur && tab[0][0]==tab[1][1] && tab[1][1]==tab[2][2])
  {
    return true;
  }
  if(tab[0][2]== joueur && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0])
  {
    return true;
  }
  
  return false;
} 

bool CheckCoup(int n, int tab[n][n],int valCoup)
{
  //on exclue les valeurs n'étant pas incluses entre 1 et 9 
  //on parcourt les valeurds 
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(tab[i][j]==valCoup){
        return true;
      }
    }
  }
  //si le true n'est pas retourné c'est que le nombre n'est pas inclue entre 1 et 9 et/ou qu'il n'est plus disponible dans la matrice
  //on retourne donc false
  printf("La valeur rentrée n'est pas disponible, veuillez réessayer.\n");
  return false;
}

bool CheckCoupComputer(int n, int tab[n][n],int valCoup){
  //on parcourt les valeurds 
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(tab[i][j]==valCoup){
        return true;
      }
    }
  }
  //si le true n'est pas retourné c'est que le nombre n'est pas inclue entre 1 et 9 et/ou qu'il n'est plus disponible dans la matrice
  //on retourne donc false
  return false;
}

bool checkDiagonal(int n, int tab[n][n], int joueur){
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (j==i){
        if (tab[i][j] != joueur){
          return false;
        }
      }
    }
  }
  return true;
}

bool CheckDiagonal2(int n, int tab[n][n], int joueur){
    for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (j==n-1-i){
        if (tab[i][j] != joueur){
          return false;
        }
        break;
      }
    }
  }
  return true;
}

bool win1(int tab[5][5], int joueur)
{
  //test pour les lignes
  for(int i=0;i<5;i++)
  {
    if(tab[i][0]==joueur && tab[i][0]==tab[i][1] && tab[i][1]==tab[i][2] && tab[i][2] == tab[i][3] && tab[i][3] == tab[i][4])
    {
      return true;
    }
  }
  
  //test pour les colonnes
  for(int i=0;i<5;i++)
  {
    if(tab[0][i]==joueur && tab[0][i]==tab[1][i] && tab[1][i]==tab[2][i] && tab[2][i] == tab[3][i] && tab[3][i] == tab[4][i])
    {
      return true;
    }
  }
  
  if(checkDiagonal(5, tab,joueur) == true){
    return true;
  };

  return CheckDiagonal2(5, tab,joueur);

} 

bool win2(int tab[7][7], int joueur)
{
  //test pour les lignes
  for(int i=0;i<7;i++)
  {
    if(tab[i][0]==joueur && tab[i][0]==tab[i][1] && tab[i][1]==tab[i][2] && tab[i][2] == tab[i][3] && tab[i][3] == tab[i][4] && tab[i][4]==tab[i][5] && tab[i][5]==tab[i][6])
    {
      return true;
    }
  }
  
  //test pour les colonnes
  for(int i=0;i<7;i++)
  {
    if(tab[0][i]==joueur && tab[0][i]==tab[1][i] && tab[1][i]==tab[2][i] && tab[2][i] == tab[3][i] && tab[3][i] == tab[4][i] && tab[4][i]==tab[5][i] && tab[5][i]==tab[6][i])
    {
      return true;
    }
  }
  
  if(checkDiagonal(7, tab,joueur) == true){
    return true;
  };

  return CheckDiagonal2(7, tab,joueur);
  
  return false;

} 


void saveGame(int tailleMap, int cJ1, int cJ2, int listCoupJ1[cJ1] , int listCoupJ2[cJ2], int firstPlayer){
  FILE *fptr = fopen("saveTicTacToe","w");
  fprintf(fptr, "%d\n", firstPlayer);
  fprintf(fptr, "%d\n", tailleMap);
  fprintf(fptr, "%d\n", cJ1);
  fprintf(fptr, "%d\n", cJ2);
  for (int i=0; i < cJ1; i++){
    fprintf(fptr, "%d", listCoupJ1[i]);
  }

  fprintf(fptr, "\n");

  for (int j=0; j < cJ2; j++){
    fprintf(fptr, "%d", listCoupJ2[j]);
  }
  
  fclose(fptr);
}

void readGame(){
  FILE* file = fopen ("saveTicTacToe", "r");
  if (file == NULL){
    printf("FICHIER NON PRESENT");
    return;
  }
  int firstPlayer;
  int tailleMap;
  int cJ1;
  int cJ2;
  int listCoupJ1[50];
  int listCoupJ2[50];

  char content[6][50];
  int cpt = 0;
  while (fgets(content[cpt], 50, file))
  {
    cpt ++;
  }
  
  for (int i=0; i< 6;i++){
    printf("%s",content[i]);
  }

  firstPlayer = atoi(content[0]);
  printf("\n%d\n", firstPlayer);
  tailleMap = atoi(content[1]);
  printf("%d\n", tailleMap);
  cJ1 = atoi(content[2]);
  printf("%d\n", cJ1);
  cJ2 = atoi(content[3]);
  printf("%d\n", cJ2);

  for (int i=0; i<cJ1; i++){
    listCoupJ1[i] =  content[4][i] - '0';
  }

  for (int j=0; j<cJ2; j++){
    listCoupJ2[j] = content[5][j] - '0';
  }

  int map[tailleMap][tailleMap];
  int mapCount = 1;
  for (int i=0; i< tailleMap;i++){
    for (int j=0; j< tailleMap;j++){
      map[i][j] = mapCount;
      mapCount++;
    }
  }

  firstAffiche(tailleMap, map);
    bool isOver = false;
    int nbJ1 = 0;
    int nbJ2 = 0;
    int coup;
    int countNumber = 0;
    while (isOver == false){
    if (firstPlayer == 0){
      coup = listCoupJ1[nbJ1];
      nbJ1 ++;
    } else {
      coup = listCoupJ2[nbJ2];
      nbJ2 ++;
    }

    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(map[i][j]==coup){
          map[i][j] = firstPlayer;
        }
      }
    }

    afficheMatrice(tailleMap, map);

    if (countNumber == 8){
      if (tailleMap == 3){
        isOver = win(map, firstPlayer);
      } else if (tailleMap == 5){
        isOver = win1(map,firstPlayer);
      } else {
        isOver = win2(map,firstPlayer);
      }
      if (isOver != true){
          isOver = true;
          printf("La partie se termine sur un nul\n");
      } else {
          if (firstPlayer == 0){
              printf("Le joueur 1 a gagné !!!!\n");
          } else {
              printf("Le joueur 2 a gagné !!!!\n");
          }
      }
      if (firstPlayer == 0){
        firstPlayer = -1;
      } else {
        firstPlayer = 0;
      }
    }
        else if (countNumber > 3){
            bool jWin = false;
            if (tailleMap == 3){
              jWin = win(map, firstPlayer);
            } else if (tailleMap == 5){
              jWin = win1(map,firstPlayer);
            } else {
              jWin = win2(map,firstPlayer);
            }
            if(jWin){
                if (firstPlayer == 0){
                    printf("Le joueur 1 a gagné !!!!\n");
                    isOver = true;
                } else {
                    printf("Le joueur 2 a gagné !!!!\n");
                    isOver = true;
                }
                if (firstPlayer == 0){
                    firstPlayer = -1;
                } else {
                    firstPlayer = 0;
                }
            } else {
                countNumber++;
                if (firstPlayer == 0){
                    firstPlayer = -1;
                } else {
                    firstPlayer = 0;
                }
            }
        } else {
            if (firstPlayer == 0){
                firstPlayer = -1;
            } else {
                firstPlayer = 0;
            }
            countNumber++;
        }
  }
}