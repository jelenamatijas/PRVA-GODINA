#include <stdio.h>
#include <stdlib.h>
/**Neka su definisani tipovi:
typedef struct duz {
double duzina;
} DUZ;
typedef struct kvadar {
DUZ a, b, c;
} KVADAR;
kojima se reprezentuju duž i kvadar,
respektivno.
Napisati funkciju koja sa standardnog ulaza
učitava i vraća (validan) kvadar (dužine ivica
a, b i c su > 0), a čiji je prototip:
KVADAR ucitaj();
Napisati funkciju koja vraća informaciju o
zapremini kvadra, a čiji je prototip:
double zapremina(KVADAR k);
Napisati funkciju koja proverava i vraća
informaciju o tome koji je od dva kvadra po
zapremini veći. Funkcija vraća vrednost 1 ako
je k1 veće od k2, 0 ako su jednaki i -1 ako je
k2 veće od k1 po zapremini. Prototip funkcije
je:
int uporedi(KVADAR *k1, KVADAR *k2);
Napisati funkciju koja sortira niz od n kvadara
u rastućem redosledu (prema zapremini), a
čiji je prototip:
void sortiraj(KVADAR *niz, int n);*/

typedef struct duz
{
    double duzina;
} DUZ;

typedef struct kvadar
{
    DUZ a, b, c;
} KVADAR;

KVADAR ucitaj()
{
    double a,b,c;
    do
    {
        printf("Unesi stranice kvadra: ");
        scanf("%lf%lf%lf", &a, &b, &c);
    }
    while(a<=0 || b<=0 || c<=0);
    DUZ d1,d2,d3;
    d1.duzina = a;
    d2.duzina = b;
    d3.duzina = c;
    KVADAR k = {d1,d2,d3};
    return k;
}

double zapremina(KVADAR k){
    return k.a.duzina * k.b.duzina *k.c.duzina;
}

int uporedi(KVADAR *k1, KVADAR *k2){
    double v1, v2;
    v1 = zapremina(*k1);
    v2 = zapremina(*k2);
    if(v1==v2)
        return 0;
    if(v1>v2)
        return 1;
    return -1;
}

void sortiraj(KVADAR *niz, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(uporedi(&niz[i],&niz[j])==1){
                KVADAR k = niz[i];
                niz[i]=niz[j];
                niz[j]=k;
            }
        }
    }
}

int main()
{
    int n;
    do{
        printf("Unesi n: ");
        scanf("%d", &n);
    }while(n<1);
    KVADAR k[n];
    for(int i=0;i<n;i++){
        k[i] = ucitaj();
    }
    sortiraj(&k, n);
    for(int i=0;i<n;i++){
        printf("%.2lf %.2lf %.2lf\n", k[i].a.duzina,k[i].b.duzina,k[i].c.duzina);
    }
    return 0;
}
