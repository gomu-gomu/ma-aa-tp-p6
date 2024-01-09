#include <stdio.h>
#include <limits.h>

int MatriceOrdre(int tableau[], int capacite)
{
  int matrice[capacite][capacite];
  int i, j, k, L, q;

  for (i = 1; i < capacite; i++)
  {
    matrice[i][i] = 0;
  }

  for (L = 2; L < capacite; L++)
  {
    for (i = 1; i < capacite - L + 1; i++)
    {
      j = i + L - 1;
      matrice[i][j] = INT_MAX;

      for (k = i; k <= j - 1; k++)
      {
        q = matrice[i][k] + matrice[k + 1][j] + tableau[i - 1] * tableau[k] * tableau[j];

        if (q < matrice[i][j])
        {
          matrice[i][j] = q;
        }
      }
    }
  }

  return matrice[1][capacite - 1];
}

int main()
{
  printf("3 - Application du paradigme « Programmation dynamique » :\n");

  int tableau[] = {1, 2, 3, 4};
  int capacite = sizeof(tableau) / sizeof(tableau[0]);

  printf("Le nombre minimal de multiplications est %d\n\n", MatriceOrdre(tableau, capacite));

  return 0;
}