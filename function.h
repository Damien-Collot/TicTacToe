#include <stdbool.h>
void firstAffiche(int n, int tableau[n][n]);
void afficheMatrice(int n, int tableau[n][n]);
bool win(int tab[3][3], int joueur);
bool CheckCoup(int n, int tab[n][n],int valCoup);
bool CheckCoupComputer(int n, int tab[n][n],int valCoup);
bool win1(int tab[5][5], int joueur);
bool win2(int tab[7][7], int joueur);
void saveGame(int tailleMap, int cJ1, int cJ2, int listCoupJ1[cJ1] , int listCoupJ2[cJ2], int firstPlayer);
void readGame();