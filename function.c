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

boolean win(int tab[3][3], int joueur)
{
  //test pour les lignes
  for(int i=0;i<3;i++)
  {
    if(tab[i][0]==tab[i][1]==tab[i][2]==joueur)
    {
      return true;
    }
  }
  
  //test pour les colonnes
  for(int i=0;i<3;i++)
  {
    if(tab[0][i]==tab[1][i]==tab[2][i]==joueur)
    {
      return true;
    }
  }
  
  //test pour les diagonales
  if(tab[0][0]==tab[1][1]==tab[2][2]==joueur)
  {
    return true;
  }
  if(tab[0][2]==tab[1][1]==tab[2][0]==joueur)
  {
    return true;
  }
  
  return false;
} 
