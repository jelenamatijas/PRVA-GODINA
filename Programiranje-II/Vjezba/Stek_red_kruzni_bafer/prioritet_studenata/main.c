#include <stdio.h>
#include <stdlib.h>

/**Napisati program koji ilustruje rad prioritetnog reda. U red je potrebno smiještati studente,
pri čemu studenti sa većim prosjekom imaju viši prioritet, tj. potrebno je da se nalaze u redu ispred studenata sa nižim prioritetom.
Definisati tip STUDENT kojim se reprezentuje student (podaci koji se vode o studentu su: indeks, prezime, ime i prosjek).*/

typedef struct student{
    char indeks[10], ime[21], prezime[21];
    float prosjek;
}STUDENT;

typedef struct red{
    STUDENT s;
    struct red *next;
}RED;

void dodaj(RED **f, RED **r, STUDENT s){
    RED *novi = (RED*)calloc(sizeof(RED),1);
    novi->s = s;
    if(*f==0)*f=*r=novi;
    else if((*f)->s.prosjek < novi->s.prosjek){
        novi->next = *f;
        *f = novi;
    }else if((*r)->s.prosjek > novi->s.prosjek){
        (*r)->next = novi;
        novi->next=0;
        *r=novi;
    }else{
        RED *p=(*f);
        while(p->next->s.prosjek > novi->s.prosjek)p=p->next;
        novi->next=p->next;
        p->next=novi;
    }

}

int brisi(RED **f, RED **r, STUDENT *s){
    if(*f==NULL)return 0;
    RED *p=*f;
    *s = p->s;
    if(*f == *r)*f = *r = 0;
    else *f = p->next;
    free(p);
    return 1;
}



int brisi_red(RED **f, RED **r){
    STUDENT pom;
    while(brisi(f, r, &pom));
}

void pisi(RED *f){
    printf("IME -------- PREZIME ---- INDEKS ----- PROSJEK -----\n");
    while(f){
        printf("%12s %12s %12s %12.2f\n", f->s.ime, f->s.prezime, f->s.indeks, f->s.prosjek);
        f=f->next;
    }
}

STUDENT ucitaj(){
    STUDENT s;
    printf("Unesi ime, prezime, indeks i prosjek studenta:\n");
    scanf("%s%s%s%f", &s.ime, &s.prezime, &s.indeks, &s.prosjek);
    return s;
}

int main()
{
    RED *f=0, *r=0;
    for(int i=0;i<2;i++)dodaj(&f, &r, ucitaj());
    pisi(f);
    brisi_red(&f, &r);
    return 0;
}
