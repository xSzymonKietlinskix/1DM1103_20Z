#include "baza.h"

Student * wczytaj_studentow(FILE *fin) { //wczytuje studenotw z pliku
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    if(bufor == NULL)
    exit(-1);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa_pliku) { //tworzy baze
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);

    fclose(fin);
    return baza;
}

int ile_studentow(SBaza *baza) { //liczy studentow
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza) { //liczy przedmioty
    int n = 0;
    Przedmiot * przedmiot = baza->lista_przedmiotow;
    while (przedmiot != NULL) {
        n++;
        przedmiot = przedmiot->nast;
    }
    return n;
}

int ile_studentprzedmiot(SBaza *baza) { //liczy studentow przypisanych do przedmiotow
    int n = 0;
    Student_przedmiot * studentprzedmiot = baza->lista;
    while (studentprzedmiot != NULL) {
        n++;
        studentprzedmiot = studentprzedmiot->nast;
    }
    return n;
}

Przedmiot *wczytaj_przedmioty (FILE *fin){ //wczytuje przedmioty
char bufor[255];
    int n, i;
    char *s;
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przedmiot = (Przedmiot*) malloc(sizeof(Przedmiot));
        przedmiot->nast = NULL;

        if (last_przedmiot == NULL)
            glowa = przedmiot;
        else
            last_przedmiot->nast = przedmiot;
        last_przedmiot = przedmiot;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przedmiot->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        przedmiot->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->nazwa, s);

        s = strtok(NULL, "\n");
        przedmiot->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->semestr, s);
    }

    return glowa;
}

Przedmiot *wczytaj_przedmiot (char *n1, char *n2, char *n3, FILE *fin){ //dodaje przedmiot
char bufor[255];
    int n, i;
    char *s;
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<=n; i++) {
        Przedmiot *przedmiot = (Przedmiot*) malloc(sizeof(Przedmiot));
        przedmiot->nast = NULL;

        if (last_przedmiot == NULL)
            glowa = przedmiot;
        else
            last_przedmiot->nast = przedmiot;
        last_przedmiot = przedmiot;
        if((n-i) != 0){
        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przedmiot->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        przedmiot->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->nazwa, s);

        s = strtok(NULL, "\n");
        przedmiot->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiot->semestr, s);
        } else {
            strcpy(bufor, n1);
            przedmiot->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
            strcpy(przedmiot->kod_przedmiotu, n1);

            strcpy(bufor, n2);
            przedmiot->nazwa = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
            strcpy(przedmiot->nazwa, n2);

            strcpy(bufor, n3);
            przedmiot->semestr = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
            strcpy(przedmiot->semestr, n3);
        }
    }

    return glowa;
    }

void listuj_studentow(SBaza *baza) { //wyposuje w konsoli studentow
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_przedmioty(SBaza *baza) { //wypisuje w konsoli przedmioty
    Przedmiot * przedmiot = baza->lista_przedmiotow;
    while (przedmiot != NULL) {
        printf("%s %s %s\n", przedmiot->kod_przedmiotu, przedmiot->nazwa, przedmiot->semestr);
        przedmiot = przedmiot->nast;
    }
}

Student * wczytaj_studenta(char *n1, char *n2, char *n3, char *n4, FILE *fin) { //wczytuje studentow z pliku i dodaje studenta z wiersza polecen
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<=n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;
        if((n-i) != 0){
        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
        }
        else
        {
        strcpy(bufor, n1);
        stud->imie = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
        strcpy(stud->imie, n1);

        strcpy(bufor, n2);
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
        strcpy(stud->nazwisko, n2);

        strcpy(bufor, n3);
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
        strcpy(stud->nr_albumu, n3);

        strcpy(bufor, n4);
        stud->email = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
        strcpy(stud->email, n4);
        }
    }
    return glowa;
}

Student_przedmiot *dodaj_studenta_do_przedmiotu(char *n1, char *n2, FILE *fin) //dodaje studenta do przedmiotu
{
    char bufor[255];
    int n, i;
    char *s;
    Student_przedmiot *last_student = NULL;
    Student_przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<=n; i++) {
        Student_przedmiot *studentprzedmiot = (Student_przedmiot*) malloc(sizeof(Student_przedmiot));
        studentprzedmiot->nast = NULL;

        if (last_student == NULL)
            glowa = studentprzedmiot;
        else
            last_student->nast = studentprzedmiot;
        last_student = studentprzedmiot;
        if((i-n) != 0) {
        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        studentprzedmiot->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));

        strcpy(studentprzedmiot->kod_przedmiotu, s);
        s = strtok(NULL, "\n");
        studentprzedmiot->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(studentprzedmiot->nr_albumu, s);
        } else
        {
        strcpy(bufor, n1);
        studentprzedmiot->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
        strcpy(studentprzedmiot->kod_przedmiotu, n1);

        strcpy(bufor, n2);
        studentprzedmiot->nr_albumu = (char*) malloc( sizeof(char) * (strlen(bufor) + 1));
        strcpy(studentprzedmiot->nr_albumu, n2);
        }
    }
    return glowa;
}

Student_przedmiot *studenta_do_przedmiotu(FILE *fin) //wczytuje stgudentow dodanych do przedmiotu (juz istniejacych)
{
    char bufor[255];
    int n, i;
    char *s;
    Student_przedmiot *last_student = NULL;
    Student_przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student_przedmiot *studentprzedmiot = (Student_przedmiot*) malloc(sizeof(Student_przedmiot));
        studentprzedmiot->nast = NULL;

        if (last_student == NULL)
            glowa = studentprzedmiot;
        else
            last_student->nast = studentprzedmiot;
        last_student = studentprzedmiot;
        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        studentprzedmiot->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(studentprzedmiot->kod_przedmiotu, s);
        s = strtok(NULL, "\n");
        studentprzedmiot->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(studentprzedmiot->nr_albumu, s);
    }
    return glowa;
}

SBaza * nowa_baza_student(char *nazwa_pliku,char *n1, char *n2, char *n3, char *n4) { //tworzy baze z wczytanym studentem
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *nowabaza = (SBaza*) malloc( sizeof(SBaza) );
    nowabaza->lista_studentow = wczytaj_studenta(n1,n2,n3,n4,fin);
    nowabaza->lista_przedmiotow = wczytaj_przedmioty(fin);
    nowabaza->lista = studenta_do_przedmiotu(fin);

    fclose(fin);
    return nowabaza;
}

SBaza * nowa_baza_przedmiot(char *nazwa_pliku,char *n1, char *n2, char *n3) { //tworzy baze z wczytanym przedmiotem
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *nowabaza = (SBaza*) malloc( sizeof(SBaza) );
    nowabaza->lista_studentow = wczytaj_studentow(fin);
    nowabaza->lista_przedmiotow = wczytaj_przedmiot(n1,n2,n3,fin);
    nowabaza->lista = studenta_do_przedmiotu(fin);

    fclose(fin);
    return nowabaza;
}

SBaza * nowa_baza_przedmiotstudent(char *nazwa_pliku,char *kod, char *numer) { //tworzy baze z wczytanym przedmiotem i przypisanym studentem
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *nowabaza = (SBaza*) malloc( sizeof(SBaza) );
    nowabaza->lista_studentow = wczytaj_studentow(fin);
    nowabaza->lista_przedmiotow = wczytaj_przedmioty(fin);
    nowabaza->lista = dodaj_studenta_do_przedmiotu(kod, numer, fin);

    fclose(fin);
    return nowabaza;
}

void zapisz_baze(char *nazwa_pliku, SBaza * baza) { //zapisuje zmiany w bazie do pliku
    FILE *fin = fopen(nazwa_pliku, "w+");

    fprintf(fin, "%d\n",ile_studentow(baza));
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        fprintf(fin, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
    Przedmiot * przedmiot = baza->lista_przedmiotow;
    fprintf(fin, "%d\n",ile_przedmiotow(baza));
    while (przedmiot != NULL) {
        fprintf(fin, "%s;%s;%s\n", przedmiot->kod_przedmiotu, przedmiot->nazwa, przedmiot->semestr);
        przedmiot = przedmiot->nast;
    }
    Student_przedmiot *studentprzedmiot = baza->lista;
    fprintf(fin, "%d\n",ile_studentprzedmiot(baza));
    while (studentprzedmiot != NULL) {
        fprintf(fin, "%s;%s\n", studentprzedmiot->kod_przedmiotu, studentprzedmiot->nr_albumu);
        studentprzedmiot = studentprzedmiot->nast;
    }
    fclose(fin);
    }

void zwolnij_student(Student *s) { //zwalnia dane od studenta
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmiot(Przedmiot *s) { //zwalnia dane od przedmiotu
    free(s->kod_przedmiotu);
    free(s->nazwa);
    free(s->semestr);
    free(s);
}

void zwolnij_studentprzedmiot(Student_przedmiot *s) { //zwalnia dane od studneta przypisanego do przedmiotu
    free(s->kod_przedmiotu);
    free(s->nr_albumu);
    free(s);
}

void zwolnij_liste_przedmiotow(Przedmiot *s) { //zwalnia cala liste przedmiotow
    Przedmiot *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_przedmiot(s);
        s = n;
    }
}

void zwolnij_liste_studentow(Student *s) { //zwalnia cala liste studentow
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste(Student_przedmiot *s) { //zwalnia cala liste przedmiotow z przypsianymo studentami
    Student_przedmiot *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_studentprzedmiot(s);
        s = n;
    }
}

void zwolnij(SBaza *baza) { //zwalnia cala baze
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste(baza->lista);
    free(baza);
}
