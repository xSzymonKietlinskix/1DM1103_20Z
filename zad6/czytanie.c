#include "czytanie.h"

Macierz wczytajj (FILE *fin)
{
 int i,j;
    Macierz * ms;
    ms = (Macierz*) malloc(sizeof(Macierz));
    fscanf(fin, "%d", &ms->r);
    fscanf(fin, "%d", &ms->c);
    ms->tab = (float**) malloc(sizeof(float*) * ms->r);
    for (i=0;i<ms->r;i++) {
        ms->tab[i] = (float*) malloc(sizeof(float) * ms->c);
        for (j=0;j< ms->c; j++)
        fscanf(fin, "%f", &(*ms).tab[i][j]);
    }
    return *ms;
}
Macierz utworz (int x, int y)
{
    Macierz * ms;
    ms = (Macierz*) malloc(sizeof(Macierz));
    ms->r = x;
    ms->c = y;
    ms->tab = (float**) malloc(sizeof(float*) * ms->r);
    for (int i=0;i<ms->r;i++)
        ms->tab[i] = (float*) malloc(sizeof(float) * ms->c);
    return *ms;
}

void wypiszdopliku(FILE *fun, Macierz A) //wypisuje do pliku
{
    fprintf(fun, "%d  \n", A.r); // wypisuje koljeno l. wierszy a nastepnie l. kolumn
    fprintf(fun, "%d \n", A.c);
    for (int wiersz = 0; wiersz < A.r; wiersz ++)
    {
        for (int kolumna = 0; kolumna < A.c; kolumna++)
           fprintf(fun, "%2.1f  ", A.tab[wiersz][kolumna]);
    fprintf(fun,"\n");
    }
    fprintf(fun,"\n");
}

void wypisz(Macierz m) //wypisuje macierze 
{
    int i,j;
    printf("[ ");
    for(i = 0; i < m.r; i++)
    {
        for(j = 0; j < m.c; j++)
        printf("%5.1f", m.tab[i][j]);
        if (i < m.r-1)
        printf("\n");
    }
    printf(" ]\n");
}

void zwolnij (Macierz m)
{
    int i;
    for (i=0;i<m.r;i++) 
    free(m.tab[i] );
    free(m.tab);
}