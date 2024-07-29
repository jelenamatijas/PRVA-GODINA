#include <stdio.h>
#include <stdlib.h>

typedef struct red
{
    int niz[100];
    int f, r;
} RED;

typedef struct cvor
{
    RED *red;
    struct cvor *next;
} CVOR;

int isFull(RED *red)
{
    return (red->r+1)%100 == red->f;
}

int isEmpty(RED *red)
{
    return red->f==red->r;
}

int obrisi(RED *red, int *data)
{
    if (isEmpty(red)) return 0;
    *data = red->niz[red->f];
    red->f = (red->f + 1) % 100;
    return 1;
}


void dodaj(RED *red, int data)
{
    if(isFull(red))
        red->f = (red->f+1)%100;
    red->niz[red->r] = data;
    red->r = (red->r+1)%100;
}

void dodaj_novi(CVOR **glava, RED *red)
{
    CVOR *novi = (CVOR *)calloc(1,sizeof(CVOR));
    if(novi)
    {
        novi->red = red;
        if(*glava==NULL)*glava = novi;
        else
        {
            novi->next = *glava;
            *glava = novi;
        }
    }
}

void ispisi(CVOR *glava)
{
    while(glava!=NULL)
    {
        int data;
        while(obrisi(glava->red, &data))
            printf("%d ", data);
        glava = glava->next;
    }
}

void obrisi_listu(CVOR **glava){
    while(*glava){
        CVOR *pom = *glava;
        *glava = (*glava)->next;
        free(pom);
    }
    *glava=0;
}

int main()
{
    RED r1, r2, r3;
    r1.r=r1.f=r2.r=r2.f=r3.r=r3.f=0;
    dodaj(&r1, 1);
    dodaj(&r1, 2);
    dodaj(&r2, 3);
    dodaj(&r2, 4);
    dodaj(&r3, 5);
    dodaj(&r3, 6);

    CVOR *glava=0;
    dodaj_novi(&glava, &r3);
    dodaj_novi(&glava, &r2);
    dodaj_novi(&glava, &r1);

    ispisi(glava);
    obrisi_listu(&glava);
    return 0;
}
