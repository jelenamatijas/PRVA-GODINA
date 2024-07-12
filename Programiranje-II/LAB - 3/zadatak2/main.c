#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju koja u nizu cijelih brojeva određuje najdužu seriju elemenata koji zadovoljavaju dato
svojstvo. Prototip funkcije je:
void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina);
Napisati program u kojem se učitava dinamički niz od n cijelih brojeva, nakon toga poziva funkcija za
taj niz, a zatim se ispisuje najduža serija parnih, kao i najduža serija pozitivnih elemenata niza (ispis
vršiti u glavnom programu poslije poziva funkcije).*/

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina);
int paran(int x);
int pozitivan(int x);
int main()
{
    int n;
    printf("Unesi broj elemenata niza: ");
    scanf("%d",&n);
    int *niz = (int*)calloc(sizeof(int),n);
    if(niz)
    {
        printf("Unesi elemente niza:\n");
        for(int i=0; i<n; i++)
            scanf("%d",&niz[i]);
        int *pocetak, duzina;
        serija(niz, n, &paran, &pocetak, &duzina);
        printf("Najduza serija parnih brojeva:\n");
        for(int i=0; i<duzina; i++)
        {
            printf("%d ", pocetak[i]);
        }
        serija(niz, n, &pozitivan, &pocetak, &duzina);
        printf("\nNajduza serija pozitivnih brojeva:\n");
        for(int i=0; i<duzina; i++)
        {
            printf("%d ", pocetak[i]);
        }
        free(niz);
    }
    else
    {
        printf("GRESKA!");
    }
    return 0;
}

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina)
{
    int br=0, max=0, tren=0;
    *pocetak = niz;
    *duzina = max;
    for(int i=0; i<n; i++)
    {
        if(s(niz[i]))
        {
            if(br==0)tren=i;
            br++;
        }
        else
        {
            if(br>max)
            {
                max=br;
                br=0;
                *pocetak = niz+tren;
                *duzina = max;
            }
        }
    }
    if(br>max)
    {
        max=br;
        br=0;
        *pocetak = niz+tren;
        *duzina = max;
    }
}

int paran(int x)
{
    return (x%2==0)?1:0;
}

int pozitivan(int x)
{
    return (x>=0)?1:0;
}
