#include <stdio.h>
#include <stdlib.h>
/**Napisati (rekurzivnu) funkciju za binarnu
pretragu niza proizvoljnog tipa koja ima sljedeći
prototip:
int bin_search (void *a, int size, int
begin, int end, void *key, int (*cmp)(void
*, void *));
Funkcija kao argumente prima niz a, veličinu jednog
elementa niza, indekse prvog i posljednjeg elementa
niza, ključ za pretragu i funkciju za poređenje dva
elementa niza, respektivno.
U glavnom programu demonstrirati pretragu
proizvoljnog niza cijelih brojeva koristeći funkciju
bin_search, pri čemu je potrebno implementirati i
odgovarajuću funkciju za poređenje dva elementa niza.
Prije pretrage, niz je potrebno sortirati korištenjem
qsort funkcije (funkcija iz stdlib.h).*/

int compare(void* a, void* b)
{
    if(*(int*)a>*(int*)b)return 1;
    if(*(int*)a<*(int*)b)return -1;
    return 0;
}

int bin_search (void *a, int size, int begin, int end, void *key, int (*cmp)(void*, void *))
{
    if(begin>end)return 0;

    qsort(a, end, size, cmp);

    int sredina = (begin+end)/2;
    if(((int*)a)[sredina] == *(int*)key)return 1;
    if(((int*)a)[sredina] > *(int*)key)
        bin_search(a, size, begin, sredina-1, key, cmp);
    else
        bin_search(a, size, sredina+1, end, key, cmp);
}

int main()
{
    int niz[10]= {1,13,2,25,54,22,54,13,42,3};
    int n=22;
    printf("Broj %s pronadjen u nizu.\n",bin_search(niz, sizeof(int), 0, 10, &n, compare)?"jeste":"nije");
    return 0;
}
