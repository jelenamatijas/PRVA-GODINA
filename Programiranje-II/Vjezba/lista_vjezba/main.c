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
    char ime[20], prezime[20], br_indeksa[10];
}STUDENT;

typedef struct cvor{
    STUDENT info;
    struct cvor *next;
}CVOR;

CVOR* dodaj_pocetak(CVOR **glava, STUDENT *info){
    CVOR *novi = (CVOR*)calloc(sizeof(STUDENT), 1);
    if(novi==NULL)return 0;
    novi->info = *info;
    novi->next = *glava;
    *glava = novi;
    return novi;
}

CVOR* dodaj_kraj(CVOR **glava, STUDENT *info){
    CVOR *pom, *novi = (CVOR*)calloc(sizeof(STUDENT), 1);
    if(!novi)return 0;
    novi->info = *info;
    novi->next = 0;
    if(!*glava)*glava = novi;
    else{
        for(pom = *glava;pom->next;pom=pom->next);
        pom->next = novi;
    }
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

CVOR* dodaj_iza(CVOR *cvor, STUDENT *info){
    CVOR *novi = (CVOR*)calloc(sizeof(STUDENT), 1);
    if(!novi)return 0;
    novi->info = *info;
    novi->next=cvor->next;
    cvor->next = novi;
    return novi;
}

CVOR* dodaj_ispred(CVOR *cvor, STUDENT *info){
    CVOR *novi = (CVOR*)calloc(sizeof(STUDENT), 1);
    if(!novi)return 0;
    novi->info = cvor->info;
    novi->next = cvor->next;
    cvor->info = *info;
    cvor->next = novi;
    return cvor;
}

int brisi_iza(CVOR *cvor){
    CVOR *p = cvor->next;
    if(!p)return 0;
    cvor->next = p->next;
    free(p);
    return 1;
}

int brisi(CVOR *cvor){
    CVOR *p = cvor->next;
    if(!p)return 0;
    cvor->info = p->info;
    cvor->next = p->next;
    free(p);
    return 1;
}

void brisi_listu(CVOR **glava){
    while(*glava){
        CVOR *p = (*glava)->next;
        (*glava) = p;
        free(p);
    }
    *glava=0;
}

void invertuj(CVOR **glava){
    CVOR *p1=*glava, *p2=0, *p3;
    while(p1){
        p3 = p1->next;
        p1->next = p2;
        p2=p1;
        p1=p3;
    }
    *glava = p2;
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
    STUDENT ss= {"Petar","Petrovic", "1123/23"}, s2 = {"Milica", "Ilic", "1180/23"};
    CVOR *c = dodaj_kraj(&lista, &ss);
    CVOR *c1 = dodaj_iza(c, &ss);
    CVOR *c2 = dodaj_ispred(c1, &s2);
    brisi_iza(c1);
    brisi_iza(c);
    ///brisi_listu(&lista);
    invertuj(&lista);
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
