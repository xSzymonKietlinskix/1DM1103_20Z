#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * kod_przedmiotu;
    char * nazwa;
    char * semestr;

    struct _Przedmiot *nast;
} Przedmiot;

typedef struct _studenci_przedmiot {
    char * kod_przedmiotu;
    char * nr_albumu;

    struct _studenci_przedmiot *nast;
} Student_przedmiot;

typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow; //głowa listy przedmiotów
    Student_przedmiot *lista; //lista studentow na przedmicoie 
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
Student * wczytaj_studentow(FILE *fin);
void zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
Student * wczytaj_studenta(char *n1, char *n2, char *n3, char *n4, FILE *fin);
SBaza * nowa_baza_student(char *nazwa_pliku,char *n1, char *n2, char *n3, char *n4);
Przedmiot *wczytaj_przedmioty (FILE *fin);
void listuj_przedmioty(SBaza *baza);
Przedmiot *wczytaj_przedmiot (char *n1, char *n2, char *n3, FILE *fin);
SBaza * nowa_baza_przedmiot(char *nazwa_pliku,char *n1, char *n2, char *n3);
int ile_przedmiotow(SBaza *baza);
void zwolnij_przedmiot(Przedmiot *s);
void zwolnij_liste_przedmiotow(Przedmiot *s);
SBaza * nowa_baza_przedmiotstudent(char *nazwa_pliku,char *kod, char *numer);
Student_przedmiot *dodaj_studenta_do_przedmiotu(char *n1, char *n2, FILE *fin);
Student_przedmiot *studenta_do_przedmiotu(FILE *fin);
int ile_studentprzedmiot(SBaza *baza);
void zwolnij_liste(Student_przedmiot *s);
void zwolnij_studentprzedmiot(Student_przedmiot *s);
#endif