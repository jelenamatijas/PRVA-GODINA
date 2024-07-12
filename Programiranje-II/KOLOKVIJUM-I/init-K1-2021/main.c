#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**Napisati funkciju init koja kao obavezne
parametre prihvata pokazivač na funkciju (parametar
u), adresu nekog cijelog broja (parametar pn) i cijeli
broj n, a zatim n realnih brojeva tipa double
(neobavezni parametri).
Parametar u predstavlja pokazivač na funkciju koja
provjerava da li je ispunjen neki uslov za dati realan
broj (funkcija vraća vrijednost 0 ako uslov nije
ispunjen, a vrijednost 1 ako uslov jeste ispunjen).
Funkcija init treba da od realnih brojeva (neobavezni
parametri) koji ispunjavaju dati uslov, formira i vrati
dinamički niz. Preko parametra pn funkcija treba da
vrati broj elemenata formiranog niza. Ako dati uslov
nije ispunjen niti za jedan realan broj, funkcija init
treba da vrati NULL.
Prototip funkcije init je:
double* init(int (*u)(double), int *pn, int n, ...);*/

int provjeri(double x)
{
    if(x>0)return 1;
    return 0;
}

double* init(int (*u)(double), int *pn, int n, ...)
{
    va_list args;
    double *niz = (double*)calloc(sizeof(double), n);
    if(niz==NULL)return 0;
    va_start(args, n);
    int br=0;
    for(int i=0; i<n; i++)
    {
        double broj = va_arg(args, double);
        if((*u)(broj))
        {
            niz[br++] = broj;
        }
    }
    va_end(args);
    if(br<n)
    {
        niz = (double*)realloc(niz, br*sizeof(double));
        if(niz==NULL)return 0;
    }
    *pn=br;
    return niz;
}

int main()
{
    int n;
    double *niz = init(provjeri, &n,6, 2.0, 3.0, -1.0, 5.0, 7.0, -8.0);
    if(niz!=NULL)
    {
        for(int i=0; i<n; i++)
        {
            printf("%.2lf ", niz[i]);
        }
    }
    free(niz);
    return 0;
}
