#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) {
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);
    if (strcmp("list_students", argv[2]) == 0) {
        listuj_studentow(baza);

    } else if (strcmp("add_student", argv[2]) == 0) {
        SBaza *nowabaza;
        nowabaza = nowa_baza_student(argv[1], argv[3], argv[4], argv[5], argv[6]);
        zapisz_baze(argv[1], nowabaza);//zapisuje baze z wczytanym studentem, mozna ew zmienic na argv[7] i wtedy mozna wybrac nowa nazwe pliku
        zwolnij(nowabaza);

    } else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
        
    } else if (strcmp("list_courses", argv[2]) == 0) {
        listuj_przedmioty(baza);

    } else if (strcmp("add_course", argv[2]) == 0) {
        SBaza *nowabaza;
        nowabaza = nowa_baza_przedmiot(argv[1], argv[3], argv[4], argv[5]);
        zapisz_baze(argv[1], nowabaza);
        zwolnij(nowabaza); //chyba zwalnia wszytsko bo valgrind nie widzi wyciekow
        
    } else if (strcmp("add_student_to_course", argv[2]) == 0) {
        SBaza *nowabaza;
        nowabaza = nowa_baza_przedmiotstudent(argv[1], argv[3], argv[4]);
        zapisz_baze(argv[1], nowabaza);
        zwolnij(nowabaza); //chyba zwalnia wszytsko bo valgrind nie widzi wyciekow
    }
    zwolnij(baza); //chyba zwalnia wszytsko bo valgrind nie widzi wyciekow
    return 0;
}