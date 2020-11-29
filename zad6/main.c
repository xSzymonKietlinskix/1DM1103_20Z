#include "liczenie.h"

int main(int argc, char *argv[])
{
     Macierz mac; 
     Macierz mac2;
    if(( strcmp (argv[1], "norm") != 0) and (strcmp(argv[1], "multiply") != 0)) // jezeli uzywamy funkcji wymagajacej tylko jednej macierzy to nie wczytujemy drugiego pliku
    {
    FILE *fin2 = fopen(argv[3], "r");
    mac2 = wczytajj(fin2);
    }
    FILE *fin = fopen(argv[2], "r");
    mac = wczytajj(fin);
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
         Macierz mac3 = multiply(mac,n);
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
         Macierz mac3 = sum(mac, mac2);
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
         Macierz mac3 = subtract(mac, mac2);
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
        Macierz mac3 = prod(mac, mac2);
        mac3.r = mac2.r;
        mac3.c = mac.c;
     if (argv[4] == NULL)
        {
        wypisz(mac3);
        }
     else
      {
         FILE *fun = fopen(argv[4], "w+");
        wypiszdopliku(fun,mac3);
        fclose(fin);
      }}};
      zwolnij(mac);
      fclose(fin);
      if(( strcmp (argv[1], "norm") != 0) and (strcmp(argv[1], "multiply") != 0))
      {
      zwolnij(mac2);
      } 
      return 0;
}
