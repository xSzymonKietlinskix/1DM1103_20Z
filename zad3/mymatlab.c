#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iso646.h> // do używania and or

struct Macierz
{
    int r;
    int c;
    float tab[20][20];
};

void wczytaj(FILE * fin, struct Macierz *m) //wczytuje macierz z txt
{
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    for (int i = 0; i < m->r; i++)
    {
        for (int j = 0; j < m->c; j++)
        fscanf(fin, "%f", &(*m).tab[i][j]);
    }
}
struct Macierz sum(struct Macierz A, struct Macierz B) //sumuje macierze
{
    struct Macierz suma;
    for (int wiersz = 0; wiersz < B.r; wiersz++)
    {
        for (int kolumna = 0; kolumna < B.c; kolumna++)
            {
                suma.tab[wiersz][kolumna] = A.tab[wiersz][kolumna] + B.tab[wiersz][kolumna];
            }
    }

    return suma; //zwraca te sume
}

struct Macierz subtract(struct Macierz A, struct Macierz B)
{
    struct Macierz roznica;
    for (int wiersz = 0; wiersz < B.r; wiersz++)
    {
        for (int kolumna = 0; kolumna < B.c; kolumna++)
            {
                roznica.tab[wiersz][kolumna] = A.tab[wiersz][kolumna] - B.tab[wiersz][kolumna];
            }
    }

    return roznica;
}
struct Macierz prod(struct Macierz A, struct Macierz B)
{
    struct Macierz mnoz;
    for (int wiersz = 0; wiersz < B.r; wiersz ++)
    {
        for (int kolumna = 0; kolumna < A.c; kolumna++)
            for(int c = 0; c < A.c; c++)
        mnoz.tab[wiersz][kolumna] += A.tab[wiersz][c] * B.tab[c][kolumna] ;
    }
    return mnoz;

}
struct Macierz multiply(struct Macierz A, float s) // zmienna s to skalar
{
    struct Macierz AS;
    for (int wiersz = 0; wiersz < A.r; wiersz ++)
    {
        for (int kolumna = 0; kolumna < A.c; kolumna++)
        AS.tab[wiersz][kolumna] = A.tab[wiersz][kolumna] * s ;
    }
    return AS;

}

void wypisz(struct Macierz m) //wypisuje macierze 
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
float norm(struct Macierz m)
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
void wypiszdopliku(FILE *fun, struct Macierz A) //wypisuje do pliku
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

int main(int argc, char *argv[])
{
    struct Macierz mac; 
    struct Macierz mac2;
    if(( strcmp (argv[1], "norm") != 0) and (strcmp(argv[1], "multiply") != 0)) // jezeli uzywamy funkcji wymagajacej tylko jednej macierzy to nie wczytujemy drugiego pliku
    {
    FILE *fin2 = fopen(argv[3], "r");
    wczytaj(fin2, &mac2);
    }
    FILE *fin = fopen(argv[2], "r");
    wczytaj(fin, &mac);
    
     if( strcmp (argv[1], "norm") == 0) // dla norm
      {
     if (argv[3] == NULL)
        printf("%f\n", norm(mac));
     else
     {
      FILE *fun = fopen(argv[3], "w+");
      fprintf(fun, "%f\n", norm(mac));
    }
    }
    else if( strcmp (argv[1], "multiply") == 0) //dla multiply
      {
        float n;
        n = atof(argv[3]); //przypisuje wartosc z konsoli do zmiennej n (to nasz skalar)
        struct Macierz mac3 = multiply(mac,n);
        mac3.r = mac.r; // przypisuje mac3 liczbe wierszy i kolumn aby funkcja wypisz dzialala prawidlowo
        mac3.c = mac.c;
        if (argv[4] == NULL)
        wypisz(mac3);
     else
      {
         FILE *fun = fopen(argv[4], "w+");
        wypiszdopliku(fun,mac3);
      }}
else if ( strcmp (argv[1], "sum") == 0) //dla sum
{
    if (mac.r != mac2.r or mac.c != mac2.c) //sprawdza wymiary macierzy
    {
        printf("Blad! Macierze maja rozne wymiary!\n");
        exit(-1);
    }
    else
    {
        struct Macierz mac3 = sum(mac, mac2);
        mac3.r = mac.r;
        mac3.c = mac.c;
        if (argv[4] == NULL)
            wypisz(mac3);
        else
    {
            FILE *fun = fopen(argv[4], "w+");
            wypiszdopliku(fun,mac3);
    }
}}


else if( strcmp (argv[1], "subtract") == 0) //dla subtract
{
    if (mac.r != mac2.r or mac.c != mac2.c)
    {
        printf("Blad! Macierze maja rozne wymiary!\n");
        exit(-1);
    }
    else{
        struct Macierz mac3 = subtract(mac, mac2);
        mac3.r = mac.r;
        mac3.c = mac.c;
    if (argv[4] == NULL)
        wypisz(mac3);
    else
    {
        FILE *fun = fopen(argv[4], "w+");
        wypiszdopliku(fun,mac3);
    }}
    }
    

    else if( strcmp (argv[1], "prod") == 0) //dla prod
    {
        if (mac.c != mac2.r)
    {
        printf("Blad! Liczba kolumn pierwszej macierzy nie jest rowna liczbie rzedow drugiej!\n");
        exit(-1);
    }
    else{
        struct Macierz mac3 = prod(mac, mac2);
        mac3.r = mac2.r;
        mac3.c = mac.c;
     if (argv[4] == NULL)
        wypisz(mac3);
     else
      {
         FILE *fun = fopen(argv[4], "w+");
        wypiszdopliku(fun,mac3);
      }}};
      fclose(fin);
      return 0;
}
    
