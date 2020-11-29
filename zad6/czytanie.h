#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iso646.h>

typedef struct _Macierz
{
    int r;
    int c;
    float **tab;
}Macierz;
Macierz wczytajj (FILE * FIN);

void wypiszdopliku(FILE *fun, Macierz A);

void wypisz( Macierz m);
Macierz utworz(int x, int y);
void zwolnij (Macierz m);

