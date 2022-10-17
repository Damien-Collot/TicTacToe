boolean CheckCoup(int tab[3][3],int valCoup)
{
  //on exclue les valeurs n'étant pas incluses entre 1 et 9 
  if(valCoup>0 && valCoup<10)
  {
    //on parcourt les valeurds 
    for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)
      {
        if(tab[i][j]==valCoup){
          return true;
        }
      }
    }
  }
  //si le true n'est pas retourné c'est que le nombre n'est pas inclue entre 1 et 9 et/ou qu'il n'est plus disponible dans la matrice
  //on retourne donc false
  printf("La valeur rentrée n'est pas disponible, veuillez réessayer.")
  return false;
}
