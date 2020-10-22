#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    float liczba;
    double kwadrat;
    liczba = atof(argv[1]);
    kwadrat = liczba * liczba;
    printf("Wartość %.0f do kwadratu to %.0f\n", liczba, kwadrat);
    return 0;
}