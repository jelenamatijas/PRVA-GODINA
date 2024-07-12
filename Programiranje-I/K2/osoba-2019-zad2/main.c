#include <stdio.h>
#include <stdlib.h>
/* Neka su definisani tipovi:
typedef struct mesto {
int broj_poste;
char naziv[20];
} MESTO;
kojim se reprezentuje mesto te
typedef struct osoba {
char ime[20], prezime[20];
MESTO mesto_rodjenja;
} OSOBA;
kojim se reprezentuje osoba.
Napisati funkciju koja učitava prirodan broj n
(učitanu vrednost funkcija vraća preko parametra
pn), a zatim učitava i vraća (dinamički) niz
podataka o n osoba. Prototip funkcije je:
OSOBA* ucitaj(int *pn);
Napisati funkciju koja pronalazi i ispisuje podatke o
osobama (ime i prezime) koje su rođene u mestu
čiji je broj pošte parametar funkcije (broj_poste).
Parametar n predstavlja broj elemenata niza niz.
Prototip funkcije je:
void ispisi(OSOBA *niz, int n, int broj_poste);
Napisati glavnu funkciju u kojoj treba (korištenjem
funkcije ucitaj) učitati i formirati dinamički niz
podataka o osobama, a zatim (korištenjem funkcije
ispisi) ispisati podatke o osobama koje su rođene u
mestu čiji je broj pošte 78000.*/

typedef struct mesto
{
    int broj_poste;
    char naziv[20];
} MESTO;

typedef struct osoba
{
    char ime[20], prezime[20];
    MESTO mesto_rodjenja;
} OSOBA;

OSOBA* ucitaj(int *pn);
void ispisi(OSOBA *niz, int n, int broj_poste);

int main()
{
    int n;
    OSOBA *osobe = ucitaj(&n);
    if(osobe!=NULL){
        ispisi(osobe, n, 78000);
        free(osobe);
        osobe=NULL;
    }
    return 0;
}

OSOBA* ucitaj(int *pn)
{
    do
    {
        printf("Unesi broj osoba: ");
        scanf("%d", pn);
    }
    while(*pn<1);
    OSOBA *o=(OSOBA*)malloc(sizeof(OSOBA)**pn);
    if(o==NULL){
        return NULL;
    }
    for(int i=0;i<*pn;i++){
        printf("Unesi ime osobe: ");
        scanf("%s", &o[i].ime);
        printf("Unesi prezime osobe: ");
        scanf("%s", &o[i].prezime);
        MESTO m;
        printf("Unesi mjesto rodjenja osobe: ");
        scanf("%s", &m.naziv);
        printf("Unesi postanski broj: ");
        scanf("%d", &m.broj_poste);
        o[i].mesto_rodjenja = m;
    }
    return o;

}
void ispisi(OSOBA *niz, int n, int broj_poste){
    for(int i=0;i<n;i++){
        if(niz[i].mesto_rodjenja.broj_poste == broj_poste){
            printf("%-20s %-20s %-20s %d\n", niz[i].ime, niz[i].prezime, niz[i].mesto_rodjenja.naziv, niz[i].mesto_rodjenja.broj_poste);
        }
    }
}
