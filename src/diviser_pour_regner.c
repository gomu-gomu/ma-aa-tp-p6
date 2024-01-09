#include <stdio.h>

int trouverPic(int nombres[], int min, int max, int capacite)
{
    int mid = min + (max - min) / 2;

    if (
        (mid == 0 || nombres[mid - 1] <= nombres[mid]) &&
        (mid == capacite - 1 || nombres[mid + 1] <= nombres[mid]))
    {
        return mid;
    }

    if (mid > 0 && nombres[mid - 1] > nombres[mid])
    {
        return trouverPic(nombres, min, mid - 1, capacite);
    }

    return trouverPic(nombres, mid + 1, max, capacite);
}

int main()
{
    printf("1 - Application du paradigme « Diviser-pour-régner » :\n");

    int nombres[] = {1, 3, 7, 4, 1, 0};
    int capacite = sizeof(nombres) / sizeof(nombres[0]);
    int picIndice = trouverPic(nombres, 0, capacite - 1, capacite);

    printf("Un pic se trouve à l'index: '%d', le pic est '%d'.\n\n", picIndice, nombres[picIndice]);

    return 0;
}