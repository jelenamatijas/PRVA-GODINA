#include <stdio.h>
#include <stdlib.h>

/**Napisati program u kojem treba:
-> definisati tip ARTIKAL kojim se reprezentuje artikal čiji su atributi: šifra (cijeli broj u opsegu 00000-99999,
    koji se uvijek ispisuje kao 5-cifreni podatak), naziv, količina i cijena,
-> definisati tip CVOR kojim se reprezentuje čvor jednostruko povezane liste,
-> definisati funkciju koja dodaje podatke o novom artiklu u listu tako da je poredak elemenata u listi uvijek u rastućem redoslijedu po šifri,
-> definisati funkciju koja omogućava pretraživanje liste po šifri,
-> definisati funkciju koja formatirano ispisuje podatke o svim artiklima,
-> definisati funkciju koja omogućava brisanje podataka o artiklu po šifri,
-> definisati funkciju koja briše listu,
-> definisati funkciju koja omogućava učitavanje podataka o artiklu,

u glavnom programu prikazivati meni prema kojem korisnik može da vrši:
-> dodavanje podataka o novom artiklu,
-> ažuriranje podataka,
-> brisanje podataka,
-> prikaz podataka o svim artiklima,
-> pretraživanje podataka po šifri.
*/

typedef struct artikal
{
    int sifra;
    char naziv[13];
    float kolicina, cijena;
} ARTIKAL;

typedef struct cvor
{
    ARTIKAL info;
    struct cvor *next;
} CVOR;

void dodaj_sortirano(CVOR **plista, ARTIKAL *info)
{
    CVOR *novi = (CVOR*)calloc(sizeof(CVOR), 1);
    novi -> info =  *info;
    if(*plista == 0 || (*plista)->info.sifra==info->sifra)
    {
        novi->next = *plista;
        *plista = novi;
    }
    else
    {
        CVOR *p;
        for(p=*plista; p->next && p->next->info.sifra < novi->info.sifra; p=p->next);
        novi->next = p->next;
        p->next = novi;
    }
}

CVOR *pretraga(CVOR *plista, int sifra)
{
    while(plista && plista->info.sifra!=sifra)
        plista = plista->next;
    return (plista==0 || plista->info.sifra>sifra)?0:plista;
}

void ispis(CVOR *plista)
{
    printf("SIFRA ------ NAZIV ----------- KOLICINA ------ CIJENA ------\n");
    while(plista)
    {
        printf("%5d ------ %s --- %9.2f ------ %9.2f ------\n", plista->info.sifra, plista->info.naziv, plista->info.kolicina, plista->info.cijena);
        plista = plista->next;
    }
}

int brisi(CVOR **plista, int sifra)
{
    if(*plista == 0)
    {
        return 0;
    }
    CVOR *p=0;
    if((*plista)->info.sifra == sifra)
    {
        p=*plista;
        *plista = (*plista)->next;
    }
    else
    {
        CVOR *pr = *plista;
        for(p = (*plista)->next; p->next && p->info.sifra!=sifra; p=p->next)pr=p;
        if(p==0 || p->info.sifra!=sifra)return 0;
        pr->next = p->next;
    }
    free(p);
    return 1;
}

void brisi_listu(CVOR **plista)
{
    while(*plista)
    {
        CVOR *p = (*plista)->next;
        free(*plista);
        *plista=p;
    }
    *plista=0;
}

ARTIKAL ucitaj()
{
    ARTIKAL art;
    printf("Unesi novi artikal (sifra, naziv, kolicina, cijena):\n");
    scanf("%d%s%f%f", &art.sifra, &art.naziv, &art.kolicina, &art.cijena);
    return art;
}

int main()
{
    int x=1;
    ARTIKAL a;
    CVOR *lista=NULL, *novi;
    int sifra;
    do
    {
        printf("-> 0. Kraj\n-> 1. Dodavanje podataka o novom artiklu\n-> 2. Azuriranje podataka\n-> 3. Brisanje podataka\n-> 4. Prikaz podataka o svim artiklima\n-> 5. Pretrazivanje podataka po sifri\n");
        scanf("%d", &x);
        switch(x)
        {
        case 1:
            a=ucitaj();
            dodaj_sortirano(&lista, &a);
            break;
        case 2:
            a=ucitaj();
            CVOR *novi = pretraga(lista, a.sifra);
            if(novi!=0){
                novi->info = a;
            }
            ispis(lista);
            break;
        case 3:
            printf("Unesi sifru: ");
            scanf("%d", &sifra);
            brisi(&lista, sifra);
            break;
        case 4:
            ispis(lista);
            break;
        case 5:
            printf("Unesi sifru: ");
            scanf("%d", &sifra);
            novi = pretraga(lista, sifra);
            if(novi!=0){
                printf("%5d ------ %s --- %9.2f ------ %9.2f ------\n", novi->info.sifra, novi->info.naziv, novi->info.kolicina, novi->info.cijena);
            }else{printf("Lista ne sadrzi taj artikal.\n");};
            break;
        };
    }
    while(x!=0);
    if(lista!=0)
        brisi_listu(&lista);
    return 0;
}
