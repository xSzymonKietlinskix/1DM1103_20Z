#include <stdio.h>
#include <stdlib.h>
#include<string.h> // biblioteka do strcpy

int main(int argc, char *argv[]) //char *argv  to tablica dwu wymaiarowa 
{
    char n[100]; // zarezerwuj pamiec dla tablicy 100 znakow
    strcpy(n, "Ala"); // to kopiuje napis do n
    
    printf("%s\n", n); //%s zmienna typu tablicowego, bedzie pisac dopoki nienapotka 0

    return 0;
}