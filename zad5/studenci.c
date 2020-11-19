#include "de.h"

int wczytaj(student dane[100], char *fnazwa) { //wczytuje dane
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

void wypisz(student dane[100], int n) { //wypisuje dane
    int i;
    for (i=0; i<n;i++) {
        printf("{ Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymał %.1f\n",
            dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
            dane[i].kod_przed, dane[i].nazwa_przed,
            dane[i].ects, dane[i].ocena
        );
    }
    printf("\n");
}

int znajdz_albumy(char *szukany_nr, char nr_albumow[100][10], int n) { //szuka powtzrających sie albumów
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) { //szuka unikalnych studentów
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz_albumy(dane[i].nr_albumu, nr_albumow, ile_znalazlem ) == -1) {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

int znajdz_kody(char *szukany_nr, char kod_przed[100][10], int n) { //szuka powtarzających się kodów przedmiotów
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, kod_przed[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_nazwe(char *szukany_nr, char nazwa_przed[100][100], int n) { //szuka powtarzających się nazw przedmiotów
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nazwa_przed[i]) == 0)
            return i;   
    }
    return -1;
}

int znajdz_przedmiot(char ile_przed[100][10], student dane[100], int n) { //szuka unikalnych kodów przedmiotów
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz_kody(dane[i].kod_przed, ile_przed, ile_znalazlem ) == -1) {
            strncpy(ile_przed[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

int znajdz_nazweprzedmiotu(char ile_nazw[100][100], student dane[100], int n) { //szuka unikalnych nazw przedmiotów
    int ile_nazwznalazlem = 0;
    int j;

    for (j=0; j <n; j++) {
        if (znajdz_nazwe(dane[j].nazwa_przed, ile_nazw, ile_nazwznalazlem ) == -1) {
            strncpy(ile_nazw[ile_nazwznalazlem], dane[j].nazwa_przed, 254);
            ile_nazwznalazlem++;
        }
    }
    return ile_nazwznalazlem;
}