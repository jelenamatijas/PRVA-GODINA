#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program u kojem treba:
definisati tip CVOR kojim se reprezentuje čvor jednostruko povezane kružne liste (informacioni sadržaj treba da bude string),
definisati funkciju koja dodaje novi string u listu tako da je poredak elemenata u listi uvijek u rastućem redoslijedu
(ukoliko dati string postoji u listi, ignorisati pokušaj dodavanja istog stringa),
definisati funkciju koja upisuje sadržaj liste u datoteku (parametar funkcije),
definisati funkciju koja omogućava brisanje stringa iz liste,
definisati funkciju koja briše listu,
u glavnom programu:
pročitati sve riječi iz datoteke, čiji je naziv prvi argument komandne linije, i formirati odgovarajuću jednostruko povezanu kružnu listu,
iz formirane liste izbaciti sve riječi koje se pojavljuju u datoteci čiji je naziv drugi argument komandne linje,
sadržaj liste upisati u datoteku čiji je naziv treći argument komandne linije.
*/

typedef struct cvor
{
    char *info;
    struct cvor *next;
} CVOR;

CVOR* sadrzi_rijec(CVOR *plista, char *string)
{
    if(plista==NULL)return NULL;
    CVOR *p = plista;
    while (p->next != plista && strcmp(p->next->info, string) != 0) p = p->next;
    if (p->next == plista) return NULL;
    return p;
}

void dodaj(CVOR** plista, char *string)
{
    if(sadrzi_rijec(*plista, string)!=0)return;
    CVOR *novi = (CVOR*)malloc(sizeof(CVOR));
    novi->info = (char*)malloc(strlen(string) + 1);
    strcpy(novi->info, string);
    if(*plista == 0)
    {
        novi->next = novi;
        *plista = novi;
    }
    else if(strcmp((*plista)->info, string)>0)
    {
        CVOR *p = *plista;
        while(p->next != *plista)
            p=p->next;
        novi->next = *plista;
        p->next = novi;
        *plista = novi;
    }
    else
    {
        CVOR *p = *plista;
        while(p->next != *plista && strcmp(p->next->info, string)<0)
            p=p->next;
        novi->next = p->next;
        p->next = novi;
    }
}

void brisi_listu(CVOR **plista)
{
    if(*plista==0)return;
    CVOR *p=*plista;
    do
    {
        CVOR *q = p;
        p=p->next;
        free(q->info);
        free(q);
    }
    while(p != *plista);
    *plista=0;
}

void pisi(CVOR *lista)
{
    if (lista == 0) return;
    CVOR *p = lista;
    do
    {
        printf("%s ", p->info);
        p = p->next;
    }
    while (p != lista);
}

void pisi_datoteku(CVOR *lista, char argv[])
{
    FILE *file = fopen(argv, "w");
    if(!file)
    {
        printf("Neuspresno otvaranje datoteke!\n");
        return;
    }
    CVOR *p=lista;
    while(p->next != lista)
    {
        fprintf(file, "%s\n", p->next->info);
        p=p->next;
    }
    fclose(file);
}

int brisi_string(CVOR **plista, CVOR *cvor)
{
    CVOR *p=cvor->next;
    if(cvor==p)return 0;
    cvor->next = p->next;
    if(*plista==p)*plista = cvor;
    free(p);
    return 1;
}

int main(int argc, char *argv[])
{
    if(argc<4)
    {
        printf("Netacan unos!\n");
        return -1;
    }
    CVOR *lista=0, *p;
    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        printf("Nije bilo moguce otvoriti datoteku! - (1)\n");
        return -2;
    }
    char rijec[21];
    while(fscanf(file, "%s ", &rijec)!=EOF)
    {
        dodaj(&lista, rijec);
    }
    fclose(file);

    strcpy(rijec, argv[2]);
    while(p=sadrzi_rijec(lista, rijec))brisi_string(&lista, p);

    file = fopen(argv[3], "w");
    if(!file)
    {
        printf("Nije bilo moguce otvoriti datoteku! - (2)\n");
        return -3;
    }

    p=lista;
    while(p->next != lista)
    {
        fprintf(file, "%s\n", p->next->info);
        p=p->next;
    }
    fclose(file);
    brisi_listu(&lista);
    return 0;
}
