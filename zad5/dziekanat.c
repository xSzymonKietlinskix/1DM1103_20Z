#include "de.h"

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i = 0;
    int pozycja = 0;
    int najlepsza_pozycja;
    float najlepsza = 0.0;
    sumy_wazonych_ocen[0] = 0;
    sumy_ects[0] = 0;
    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++)
    { 
        pozycja = znajdz_albumy( dane[i].nr_albumu, nr_albumow, ile_studentow );
        sumy_wazonych_ocen[pozycja] = 0;
        sumy_ects[pozycja] = 0;   
    }    

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_albumy( dane[i].nr_albumu, nr_albumow, ile_studentow );
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}

void najlepszy_przedmiot(student dane[100], int ile_rekordow) { //znajduje oraz wypisuje najlepszy przedmiot
    char ile_przed[100][10];
    char ile_nazw[100][100]; //wieksza tablica zeby sie napisy miescily
    int ile_przedmiotow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i = 0;
    int pozycja = 0;
    int najlepsza_pozycja;
    float najlepsza = 0.0;
    
    znajdz_nazweprzedmiotu(ile_nazw, dane, ile_rekordow); // uruchamiam te funckje aby ile_nazw miało odpowiednią wartość
    ile_przedmiotow = znajdz_przedmiot(ile_przed, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) { //pętla zeruje wszystkie używane później miejsca tablic ects i wazonych ocen poniewaz wystepowaly losowe bledy co kilka uruchomien programu
        pozycja = znajdz_kody( dane[i].kod_przed, ile_przed, ile_przedmiotow );
        sumy_wazonych_ocen[pozycja] = 0;
        sumy_ects[pozycja] = 0;   
    }    

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_kody( dane[i].kod_przed, ile_przed, ile_przedmiotow );
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;   
    }    
    for (i=0; i < ile_przedmiotow; i++) { //szuka najlepszej sredniej z przedmiotu
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
           najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
           najlepsza_pozycja = i;
       }
    }
    printf("Najlepsza średnia: ");
    printf("%s - %s: %.1f \n \n", //.1f zeby wynik mial 1 miejsce po przecinku i lepiej wygldal
        ile_przed[najlepsza_pozycja], ile_nazw[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
}
void najgorszy_przedmiot(student dane[100], int ile_rekordow) { //znajduje oraz wypisuje najgorszy przedmiot
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
        pozycja = znajdz_kody( dane[i].kod_przed, ile_przed, ile_przedmiotow );
        sumy_wazonych_ocen[pozycja] = 0;
        sumy_ects[pozycja] = 0;   
    }    

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_kody( dane[i].kod_przed, ile_przed, ile_przedmiotow );
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

    printf("Najgorsza średnia: ");
    printf("%s - %s: %.1f \n \n", 
        ile_przed[najgorsza_pozycja], ile_nazw[najgorsza_pozycja],
        sumy_wazonych_ocen[najgorsza_pozycja] / sumy_ects[najgorsza_pozycja]
    );
}