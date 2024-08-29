#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Napisati program u kojem treba:
• definisati tip STUDENT kojim se reprezentuje student čiji su atributi: ime, prezime i broj indeksa,
• definisati tip CVOR kojim se reprezentuje čvor jednostruko povezane liste (informacioni sadržaj
treba da bude tipa STUDENT),
• definisati funkciju koja dodaje novi čvor na početak liste,
• definisati funkciju koja ispisuje sadržaj liste na standardni izlaz,
• definisati funkciju koja formatirano upisuje u tekstualnu datoteku čvorove liste tipa STUDENT,
• u glavnom programu ilustrovati rad sa (neuređenom) jednostruko povezanom listom tj. definisanim
funkcijama.
*/

typedef struct student{
    char ime[21], prezime[21], br_indeksa[10];
}STUDENT;

typedef struct cvor{
    STUDENT info;
    struct cvor *next;
}CVOR;

CVOR* dodaj_pocetak(CVOR **glava, STUDENT *info){
    CVOR *novi = (CVOR*)calloc(sizeof(CVOR), 1);
    novi->info = *info;
    novi->next = *glava;
    *glava = novi;
    return novi;
}

void ispisi(CVOR *glava){
    while(glava!=NULL){
        printf("%s %s %s\n", glava->info.ime, glava->info.prezime, glava->info.br_indeksa);
        glava = glava->next;
    }
}

int upisi(CVOR *glava, char *f){
    FILE *out = fopen(f, "w");
    if(out==NULL)return 0;
    while(glava!=NULL){
        fprintf(out,"%s %s %s\n", glava->info.ime, glava->info.prezime, glava->info.br_indeksa);
        glava = glava->next;
    }
    return 1;
    fclose(out);
}

int main()
{
    CVOR *lista=NULL;
    STUDENT s;
    int n;
    printf("Unesi broj studenata: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Student %d:\n", i+1);
        scanf("%s%s%s", &s.ime,&s.prezime, &s.br_indeksa);
        CVOR *c=dodaj_pocetak(&lista, &s);
    }
    ispisi(lista);
    printf("Unesi ime datoteke: ");
    char dat[10];
    scanf("%s", &dat);
    if(!upisi(lista, dat)){
        printf("GRESKA PRI UPISU U DATOTEKU!!!\n");
    }
    CVOR *pom;
    while(lista!=NULL){
        pom=lista;
        lista=lista->next;
        free(pom);
    }
    return 0;
}
