#include "function.h"
#include<stdio.h>
#include <stdbool.h>

void firstAffiche(int tableau[n][n]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("|%d|", tableau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void afficheMatrice(int tableau[n][n]){
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

bool CheckCoup(int tab[3][3],int valCoup)
{
  //on exclue les valeurs n'étant pas incluses entre 1 et 9 
  //on parcourt les valeurds 
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
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

bool CheckCoupComputer(int tab[3][3],int valCoup){
  //on parcourt les valeurds 
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
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

bool checkDiagonal(int tab[5][5], int joueur){
  for (int i=0;i<5;i++){
    for (int j=0;j<5;j++){
      if (j==i){
        if (tab[i][j] != joueur){
          return false;
        }
      }
    }
  }
  return true;
}

bool CheckDiagonal2(int tab[5][5], int joueur){
    for (int i=0;i<5;i++){
    for (int j=0;j<5;j++){
      if (j==4-i){
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
  
  if(checkDiagonal(tab,joueur) == true){
    return true;
  };

  return CheckDiagonal2(tab,joueur);

} 

bool CheckCoup1(int tab[5][5],int valCoup)
{
  //on exclue les valeurs n'étant pas incluses entre 1 et 9 
  //on parcourt les valeurds 
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
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

bool CheckCoupComputer1(int tab[5][5],int valCoup){
  //on parcourt les valeurds 
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
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
