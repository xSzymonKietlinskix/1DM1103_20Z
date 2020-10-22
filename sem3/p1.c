#include <stdio.h>
#include <stdlib.h> // to jest biblioteka do atof
// argv [0] = nazwa programu
// %f float
int main(int argc, char *argv[])
{
    // int całkowite
    // unsigned int
    // float zmienno przecinkowe
    // double dokładniejsze float
    // char znak
    // unsigned char

    // atof zamienia napis na float
    

    float v;
    float a1;
    float a2;
    // a1 = atof(argv[1]);
    // a2 = atof(argv[2]);
    a1 = atof("12.3");
    a2 = atof("0.1");
    v = a1 + a2;
    printf("[%s] Suma: %f\n", argv[0], v);
}