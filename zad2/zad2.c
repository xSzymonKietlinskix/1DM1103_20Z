#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    FILE *A;
    FILE *x;
    int wierwek; //wiersze wektora
    int kolwek; //kolumny wektora
    int wiersze;
    int kolumny;
    int i,j,p; //zmienne int pomocnicze
    float b,a,z; //zmienne float pomocnicze
    float wynik;

    A = fopen(argv[1], "r"); // otwieranie pliku z macierza
    x = fopen(argv[2], "r"); // otwieranie pliku z wektorem

    fscanf(x, "%d", &wierwek); // czyta liczbę wierszy wektora
    fscanf(x, "%d", &kolwek); // czyta liczbę kolumn wektora
    fclose(x); // zamyka plik żeby późńiej znowu szedł od początku

    fscanf(A, "%d", &wiersze); // czyta liczbę wierszy
    fscanf(A, "%d", &kolumny); // czyta liczbę kolumn
    if(kolumny != wierwek) // sprawdza czy wymiary macierzy i wektora pozwalają na wykonanie mnożenia
    {
        printf("Błąd liczba wierszy wektora (%d) nie jest równa liczbie kolumn macierzy (%d)! Nie można wykonać mnożenia! \n", wierwek, kolumny);
        exit (-1); //awaryjnie kończy program
    }
    printf("(%d)  [", wierwek); // zaczyna wypisywanie wyniku
    wynik = 0; // na wszelki wypadek zeruje wynik przed ponownym włączeniem funckji
    for(i = 0; i < kolumny; i++)
    {
        for(j = 0; j < wiersze; j++)
        {
            a = 0; //zeruje zmienne przed ponownym wynikiem
            z = 0;
            x = fopen(argv[2], "r");
            for(int g = 0; g < j + 2; g++) // służy do przeskakiwania na odpowiednią daną w pliku z wektorem
            {
            fscanf(x, "%f", &b); // przeskaukje na nastepną daną
            }
            fscanf(A,"%f",&a); // czyta konkretny wyraz z macierzy
            fscanf(x,"%f",&z); // czyta konkretny wyraz z wektroa
            fclose(x); // zamykam plik żeby później czytać go od początku
            p = a*z; // wymnaża wyraz z macierzy razy wyraz wektora
            wynik = wynik + p; //dodaje do siebie koljene iloczyny tworząć tym samym gotowe wyrazy do odpowiedzi


        }
        printf("%0.1f ", wynik); //drukuje odpowiedź
        wynik = 0; //zeruje wynik by uniknąć błędów 
    }
    printf("] \n");
}