#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student;

int wczytaj(student dane[100], char *fnazwa) { // tutaj się nic nie zmieniło
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
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

int znajdz(char *szukany_nr, char kod_przed[100][10], int n) { //szuka powtarzających się kodów przedmiotów
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, kod_przed[i]) == 0)
            return i;
    }
    return -1;
}
int znajdznazwe(char *szukany_nr, char nazwa_przed[100][100], int n) { //szuka powtarzających się nazw przedmiotów
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
        if (znajdz(dane[i].kod_przed, ile_przed, ile_znalazlem ) == -1) {
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
        if (znajdznazwe(dane[j].nazwa_przed, ile_nazw, ile_nazwznalazlem ) == -1) {
            strncpy(ile_nazw[ile_nazwznalazlem], dane[j].nazwa_przed, 254);
            ile_nazwznalazlem++;
        }
    }
    return ile_nazwznalazlem;
}
void naj_przedmiot(student dane[100], int ile_rekordow) { //znajduje oraz wypisuje najlepsza oraz najgorsza srednia
    char ile_przed[100][10];
    char ile_nazw[100][100]; //wieksza tablica zeby sie napisy miescily
    int ile_przedmiotow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i = 0;
    int pozycja = 0;
    int najgorsza_pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0;
    float najgorsza = 0.0; //zeruje na wszelki wypadek
    
    znajdz_nazweprzedmiotu(ile_nazw, dane, ile_rekordow); // uruchamiam te funckje aby ile_nazw miało odpowiednią wartość
    ile_przedmiotow = znajdz_przedmiot(ile_przed, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) { //pętla zeruje wszystkie używane później miejsca tablic ects i wazonych ocen poniewaz wystepowaly losowe bledy co kilka uruchomien programu
        pozycja = znajdz( dane[i].kod_przed, ile_przed, ile_przedmiotow );
        sumy_wazonych_ocen[pozycja] = 0;
        sumy_ects[pozycja] = 0;   
    }    

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, ile_przed, ile_przedmiotow );
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;   
    }    
    for (i=0; i < ile_przedmiotow; i++) { //szuka najlepszej sredniej z przedmiotu
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
           najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
           najlepsza_pozycja = i;
       }
    }
    najgorsza = najlepsza; //to jest po to zeby kolejna petla zaczynala z dobrej strony (tzn od najwiekszej sredniej)
    for (int j=0; j < ile_przedmiotow; j++) { // szuka najgorszej sredniej
        if (najgorsza > sumy_wazonych_ocen[j] / sumy_ects[j]) {
           najgorsza = sumy_wazonych_ocen[j] / sumy_ects[j];
           najgorsza_pozycja = j;
       }
    }

    printf("Najlepsza średnia: ");
    printf("%s - %s: %.1f \n", //.1f zeby wynik mial 1 miejsce po przecinku i lepiej wygldal
        ile_przed[najlepsza_pozycja], ile_nazw[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
    printf("Najgorsza średnia: ");
    printf("%s - %s: %.1f \n", 
        ile_przed[najgorsza_pozycja], ile_nazw[najgorsza_pozycja],
        sumy_wazonych_ocen[najgorsza_pozycja] / sumy_ects[najgorsza_pozycja]
    );

}
int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
    naj_przedmiot(dane, ile);
    return 0;
}