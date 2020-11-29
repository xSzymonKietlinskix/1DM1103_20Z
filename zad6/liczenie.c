#include "liczenie.h"
 Macierz sum( Macierz A,  Macierz B) //sumuje macierze
{
     Macierz suma = utworz(A.r,A.c);
    for (int wiersz = 0; wiersz < B.r; wiersz++)
    {
        for (int kolumna = 0; kolumna < B.c; kolumna++)
            {
                suma.tab[wiersz][kolumna] = A.tab[wiersz][kolumna] + B.tab[wiersz][kolumna];
            }
    }

    return suma; //zwraca te sume
}

 Macierz subtract( Macierz A,  Macierz B)
{
     Macierz roznica = utworz(A.r,A.c);
    for (int wiersz = 0; wiersz < B.r; wiersz++)
    {
        for (int kolumna = 0; kolumna < B.c; kolumna++)
            {
                roznica.tab[wiersz][kolumna] = A.tab[wiersz][kolumna] - B.tab[wiersz][kolumna];
            }
    }

    return roznica;
}
 Macierz prod( Macierz A,  Macierz B)
{
     Macierz mnoz = utworz(A.r,B.c);
    for (int wiersz = 0; wiersz < B.r; wiersz ++)
    {
        for (int kolumna = 0; kolumna < A.c; kolumna++)
            for(int c = 0; c < A.c; c++)
        mnoz.tab[wiersz][kolumna] += A.tab[wiersz][c] * B.tab[c][kolumna] ;
    }
    return mnoz;
}
 Macierz multiply( Macierz A, float s) // zmienna s to skalar
{
     Macierz AS = utworz(A.r,A.c);

    for (int wiersz = 0; wiersz < A.r; wiersz ++)
    {
        for (int kolumna = 0; kolumna < A.c; kolumna++)
        AS.tab[wiersz][kolumna] = A.tab[wiersz][kolumna] * s ;
    }
    return AS;

}


float norm( Macierz m)
{
    float s = 0;
    int i,j;

    for (i = 0; i < m.r; i++) {
        for (j=0; j < m.c; j++) {
            s += m.tab[i][j] * m.tab[i][j];
        }
    }
    return sqrt(s);
}