#include <stdio.h>

void sac_a_dos(int capacite, int poids[], int valeurs[], int size)
{
  int i, w;
  int K[size + 1][capacite + 1];

  for (i = 0; i <= size; i++)
  {
    for (w = 0; w <= capacite; w++)
    {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (poids[i - 1] <= w)
        K[i][w] = (valeurs[i - 1] + K[i - 1][w - poids[i - 1]] > K[i - 1][w]) ? valeurs[i - 1] + K[i - 1][w - poids[i - 1]] : K[i - 1][w];
      else
        K[i][w] = K[i - 1][w];
    }
  }

  printf("Valeur maximale que l'on peut emporter: %d\n", K[size][capacite]);
}

int main()
{
  printf("2 - Application du paradigme « Méthodes gloutonnes » :\n");

  int capacite = 50;
  int poids[] = {10, 20, 30};
  int valeurs[] = {60, 100, 120};
  int size = sizeof(valeurs) / sizeof(valeurs[0]);

  sac_a_dos(capacite, poids, valeurs, size);
  printf("\n\n");

  return 0;
}