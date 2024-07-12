#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program u kojem treba:
definisati tip CVOR kojim se reprezentuje čvor jednostruko povezane liste (informacioni sadržaj treba da bude string),
definisati funkciju koja dodaje novi string u listu tako da je poredak elemenata u listi uvijek u rastućem redoslijedu (ukoliko dati string postoji u listi, ignorisati pokušaj dodavanja istog stringa),
definisati funkciju koja upisuje sadržaj liste u datoteku (parametar funkcije),
definisati funkciju koja omogućava brisanje stringa iz liste,
definisati funkciju koja briše listu,
u glavnom programu:
pročitati sve riječi iz datoteke, čiji je naziv prvi argument komandne linije, i formirati odgovarajuću jednostruko povezanu listu,
iz formirane liste izbaciti sve riječi koje se pojavljuju u datoteci čiji je naziv drugi argument komandne linje,
sadržaj liste upisati u datoteku čiji je naziv treći argument komandne linije.
*/

typedef struct cvor
{
    char info[21];
    struct cvor *next;
} CVOR;

int rijec_postoji(CVOR *plista, char *s)
{
    while(plista)
    {
        if(strcmp(plista->info, s)==0)
            return 1;
        plista=plista->next;
    }
    return 0;
}

void dodaj_sortirano(CVOR **plista, char *s)
{
    if(rijec_postoji(*plista, s)==0)
    {
        CVOR *novi = (CVOR*)calloc(sizeof(CVOR), 1);
        strcpy(novi->info, s);
        if(*plista == 0)
        {
            *plista = novi;
        }
        else
        {
            CVOR *p;
            for(p=*plista; p->next && strcmp(p->next->info, s)<0; p=p->next);
            novi->next = p->next;
            p->next = novi;
        }
    }
}

void upisi_datoteku(CVOR *plista, char *argv)
{
    FILE *file = fopen(argv, "w");
    if(!file)printf("Neuspjesno otvaranje datoteke.\n");
    else
    {
        while(plista)
        {
            fprintf(file, "%s\n", plista->info);
            plista = plista->next;
        }
        fclose(file);
    }
}

int brisi(CVOR **plista, char *s)
{
    if(*plista == 0)return 0;
    CVOR *p=0;
    if(strcmp((*plista)->info, s)==0)
    {
        p = *plista;
        *plista = (*plista)->next;
    }
    else
    {
        CVOR *pr = *plista;
        for(p=(*plista)->next; p && strcmp(p->next->info, s)<0; p=p->next)pr=p;
        if(p==0 || strcmp(p->next->info, s)>0)return 0;
        pr->next = p->next;
    }
    free(p);
    return 1;
}

void brisi_listu(CVOR **plista)
{
    while(*plista)
    {
        CVOR *p = *plista;
        *plista = (*plista)->next;
        free(p);
    }
    *plista =0;
}


int main(int argc, char *argv[])
{
    if(argc<4){
        printf("Netacan unos!\n");
        return -1;
    }
    CVOR *lista=0;
    FILE *file = fopen(argv[1], "r");
    if(!file){
        printf("Nije bilo moguce otvoriti datoteku! - (1)\n");
        return -2;
    }
    char rijec[21];
    while(fscanf(file, "%s ", &rijec)!=EOF){
        dodaj_sortirano(&lista, rijec);
    }
    fclose(file);

    strcpy(rijec, argv[2]);
    int x=1;
    while(rijec_postoji(lista, rijec))brisi(&lista, rijec);

    file = fopen(argv[3], "w");
        if(!file){
        printf("Nije bilo moguce otvoriti datoteku! - (2)\n");
        return -3;
    }

    CVOR *p=lista;
    while(p){
        fprintf(file, "%s\n", p->info);
        p=p->next;
    }
    fclose(file);
    brisi_listu(&lista);
    return 0;
}
