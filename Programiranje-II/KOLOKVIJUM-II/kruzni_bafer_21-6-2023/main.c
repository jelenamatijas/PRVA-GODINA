#include <stdio.h>
#include <stdlib.h>

/**Neka je dat tip kojim se reprezentuje
kružni bafer sa prepisivanjem:
typedef struct red {
int niz[100]; int f, r;
} RED;
Neka je dat tip kojim se reprezentuje čvor jedostruko
ulančane liste:
typedef struct cvor {
RED *red;
struct cvor *next;
} CVOR;
Napisati funkciju za dodavanje elementa u kružni bafer.
Napisati funkciju za dodavanje novog bafera na početak
jednostruko ulančane liste. Napisati funkciju koja prolazi
kroz sve čvorove liste te za svaki čvor ispisuje sadržaj
kružnog bafera:
void ispisi(CVOR* glava);
U glavnom programu kreirati jednu listu i tri bafera sa po
dva elementa u svakom. Date kružne bafere potrebno je
dodati u listu i zatim ilustrovati upotrebu prethodno
definisane funkcije.*/

#define MAX 3

typedef struct red
{
    int niz[MAX];
    int f, r;
} RED;

typedef struct cvor
{
    RED *red;
    struct cvor *next;
} CVOR;

int isFull(RED *red)
{
    return (red->r + 1)%MAX == red->f;
}

int isEmpty(RED *red)
{
    return red->f == -1;
}

void dodaj_u_bafer(RED *red, int info)
{
    if (isFull(red))
        red->f = (red->f + 1) % MAX;
    if (isEmpty(red))
        red->f = 0;
    red->r = (red->r + 1) % MAX;
    red->niz[red->r] = info;
}

void dodaj_na_listu(RED *red, CVOR **plista)
{
    CVOR *novi = (CVOR*)calloc(1, sizeof(CVOR));
    novi->red = red;
    novi->next = *plista;
    *plista = novi;
}

void ispisi(CVOR* glava)
{
    while(glava)
    {
        RED *red = glava->red;
        glava = glava->next;
        int i = red->f;
        if(i<=red->r)
        {
            while(i<=red->r)
                printf("%d ", red->niz[i++]);
        }
        else
        {
            while(i<=MAX-1)
                printf("%d ", red->niz[i++]);
            i=0;
            while(i<=red->r)
                printf("%d ", red->niz[i++]);
        }
        printf("\n");
    }
}

void brisi_listu(CVOR **plista)
{
    while(*plista)
    {
        CVOR *del = *plista;
        *plista = del->next;
        free(del->red);
        free(del);
    }
}

int main()
{
    RED *r1 = (RED*)calloc(3, sizeof(RED));
    r1->f = r1->r = -1;
    dodaj_u_bafer(r1, 1);
    dodaj_u_bafer(r1, 2);
    dodaj_u_bafer(r1, 3);

    RED *r2 = (RED*)calloc(3, sizeof(RED));
    r2->f = r2->r = -1;
    dodaj_u_bafer(r2, 4);
    dodaj_u_bafer(r2, 5);
    dodaj_u_bafer(r2, 6);

    RED *r3 = (RED*)calloc(3, sizeof(RED));
    r3->f = r3->r = -1;
    dodaj_u_bafer(r3, 7);
    dodaj_u_bafer(r3, 8);
    dodaj_u_bafer(r3, 9);

    CVOR *lista = 0;
    dodaj_na_listu(r1, &lista);
    dodaj_na_listu(r2, &lista);
    dodaj_na_listu(r3, &lista);

    ispisi(lista);

    brisi_listu(&lista);
    return 0;
}
