#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**Napisati funkciju sa promjenljivim brojem
argumenata, koja redom prihvata promjenljive fp
(pokazivač na ulaznu binarnu datoteku) i n, te n
pokazivača na izlazne binarne datoteke (neobavezni
argumenti). Funkcija treba da podijeli sadržaj ulazne
datoteke na n jednakih segmenata i u izlazne datoteke,
redom, upiše segment po segment sadržaja ulazne
datoteke. Smatrati da su sve datoteke otvorene prije
poziva funkcije.*/

void podijeli(FILE *ulaz, int n, ...)
{
    va_list args;
    fseek(ulaz, 0, SEEK_END);
    int bajt = ftell(ulaz)/n;
    rewind(ulaz);
    va_start(args, n);
    for(int i=0; i<n; i++)
    {
        FILE *f = va_arg(args, FILE*);
        char s[bajt+1];
        fread(s, 1, bajt, ulaz);
        fwrite(s, 1, bajt, f);
    }
    va_end(args);
}

int main()
{
    int n;
    printf("Unesi n: ");
    scanf("%d", &n);
    FILE *ulazna = fopen("ULAZNA.bin", "rb");
    FILE *datoteke[n];
    for(int i=0; i<n; i++)
    {
        char s[20];
        sprintf(s, "dat_%d.bin", i);
        datoteke[i] = fopen(s, "wb");
    }
    podijeli(ulazna, n, datoteke[0], datoteke[1], datoteke[2]);
    for(int i=0; i<n; i++)
    {
        fclose(datoteke[i]);
    }
    fclose(ulazna);
    return 0;
}
