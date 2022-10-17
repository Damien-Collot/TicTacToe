boolean CheckCoup(int tab[3][3],int valCoup)
{
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(tab[i][j]==valCoup){
        return true;
      }
    }
  }
  printf("La valeur rentrée n'est pas disponible, veuillez réessayer.")
  return false;
}
