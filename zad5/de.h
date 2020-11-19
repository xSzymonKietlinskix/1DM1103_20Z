#include <stdio.h> //biblioteki używane w programie
#include <stdlib.h>
#include <string.h>

typedef struct _student { //głowna struktura używana w programie
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;


int wczytaj(student dane[100], char *fnazwa);
void wypisz(student dane[100], int n);
int znajdz_albumy(char *szukany_nr, char nr_albumow[100][10], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);
int znajdz_kody(char *szukany_nr, char kod_przed[100][10], int n);
int znajdz_nazwe(char *szukany_nr, char nazwa_przed[100][100], int n);
int znajdz_przedmiot(char ile_przed[100][10], student dane[100], int n);
int znajdz_nazweprzedmiotu(char ile_nazw[100][100], student dane[100], int n);
void najlepszy_student(student dane[100], int ile_rekordow);
void najlepszy_przedmiot(student dane[100], int ile_rekordow);
void najgorszy_przedmiot(student dane[100], int ile_rekordow);