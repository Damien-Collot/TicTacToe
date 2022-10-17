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
