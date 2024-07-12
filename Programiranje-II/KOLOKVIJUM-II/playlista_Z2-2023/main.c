#include <stdio.h>
#include <stdlib.h>

/**Izabrati i definisati najpogodnije
tipove za rješavanje sljedećeg problema:
Korisnik sluša pjesme iz određene plejliste. Tokom
slušanja plejliste korisnik koristi akcije za
prebacivanje pjesama naprijed i nazad. Napisati
funkciju koja prima adekvatnu strukturu pjesama
i listu akcija te na osnovu datih podataka pronaći
koja je posljednja pjesma koju je korisnik slušao.
Akcije treba da budu definisane tipom int gdje broj
0 definiše prebacivanje unazad, a broj 1
prebacivanje unaprijed. Ukoliko se dođe do kraja
plejliste, potrebno je ponovo krenuti od prve
pjesme.
Koristiti ulančane reprezentacije odabranih tipova.*/

typedef struct pjesma
{
    double trajanje;
} PJESMA;

typedef struct cvor
{
    PJESMA pjesma;
    struct cvor *lijevi, *desni;
} CVOR;

PJESMA pronadji(CVOR *glava, CVOR *rep, CVOR *trenutni, int akcija[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(akcija[i]==1)
        {
            trenutni = trenutni->desni;
        }
        else
        {
            if(trenutni != glava)trenutni = trenutni->lijevi;
        }
    }
    return trenutni->pjesma;
}

void dodaj_kraj(CVOR **glava, CVOR **rep, PJESMA p)
{
    CVOR *novi = (CVOR*)calloc(1, sizeof(CVOR));
    novi->pjesma = p;
    if(*glava==0)
    {
        *glava =*rep= novi;
    }
    else
    {
        novi->lijevi = *rep;
        (*rep)->desni = novi;
        *rep = novi;
        (*rep)->desni = *glava;
    }
}

void brisi_listu(CVOR **glava, CVOR **rep)
{
    while(*glava != *rep)
    {
        CVOR *pom = *glava;
        *glava = pom->desni;
        free(pom);
    }
    free(*rep);
}

int main()
{
    CVOR *glava, *rep;
    glava=rep=0;
    PJESMA p1 = {3.20}, p2 = {2.86}, p3 = {4.58}, p4={3.21};
    dodaj_kraj(&glava, &rep, p1);
    dodaj_kraj(&glava, &rep, p2);
    dodaj_kraj(&glava, &rep, p3);
    dodaj_kraj(&glava, &rep, p4);
    int akcije[] = {1,0,1,1,0};

    PJESMA t = pronadji(glava, rep, glava->desni, akcije, 5);
    printf("Trajanje pjesme na kojoj ste se zaustavili je %.2lf.\n", t.trajanje);

    brisi_listu(&glava, &rep);

    return 0;
}
