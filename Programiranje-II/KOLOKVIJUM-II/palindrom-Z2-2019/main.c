#include <stdio.h>
#include <stdlib.h>

/**Dat je sljedeći tip podataka koji se koristi
pri radu sa ulančanom reprezentacijom reda (FIFO),
kao i sa ulančanom reprezentacijom steka (LIFO):
typedef struct cvor {
char c;
struct cvor *sljedeci;
} CVOR;
Pretpostaviti da su implementirane sljedeće funkcije:
void dodaj_u_red(CVOR **pf, CVOR **pr, char *c);
int brisi_iz_reda(CVOR **pf, CVOR **pr, char *c);
void brisi_red(CVOR **pf, CVOR **pr);
int ukloni_sa_steka(CVOR **tos, char *c);
void brisi_stek(CVOR **tos);
Potrebno je:
 napisati funkciju za dodavanje elementa na
stek:
void dodaj_na_stek(CVOR **tos, char *c);
 napisati glavnu funkciju (main) u kojoj
korisnik unosi n znakova (mala slova) putem
standardnog ulaza (jedan po jedan znak).
Prilikom unosa, znakovi se dodaju u red i na
stek. Nakon unosa svih znakova potrebno je
ispisati riječ koja nastaje od datih znakova i
da li je ta riječ palindrom (poređenjem
znakova iz reda sa znakovima na steku).*/

typedef struct cvor
{
    char c;
    struct cvor *sljedeci;
} CVOR;

CVOR *noviCvor(char c)
{
    CVOR *novi = (CVOR*)calloc(1, sizeof(CVOR));
    novi->c = c;
    return novi;
}

void dodaj_u_red(CVOR **pf, CVOR **pr, char *c)
{
    CVOR *novi = noviCvor(*c);
    if(*pf==NULL)*pf = *pr = novi;
    else
    {
        (*pr)->sljedeci = novi;
        *pr=novi;
    }
}
int brisi_iz_reda(CVOR **pf, CVOR **pr, char *c)
{
    if(*pf==0)return 0;
    *c = (*pf)->c;
    if(*pf == *pr)
    {
        free(*pf);
        *pf = *pr = 0;
    }
    else
    {
        CVOR *del = *pf;
        *pf = del->sljedeci;
        free(del);
    }
    return 1;
}
void brisi_red(CVOR **pf, CVOR **pr)
{
    while(*pf)
    {
        CVOR *del = *pf;
        *pf = del->sljedeci;
        free(del);
    }
    *pr=0;
}
int ukloni_sa_steka(CVOR **tos, char *c)
{
    if(*tos==NULL)return 0;
    *c = (*tos)->c;
    CVOR *del = *tos;
    *tos = del->sljedeci;
    free(del);
    return 1;
}
void brisi_stek(CVOR **tos)
{
    while(*tos)
    {
        CVOR *del = *tos;
        *tos = del->sljedeci;
        free(del);
    }
    *tos=0;
}
void dodaj_na_stek(CVOR **tos, char *c)
{
    CVOR *novi = noviCvor(*c);
    novi->sljedeci = *tos;
    *tos=novi;
}



int main()
{
    CVOR *tos=0, *f=0, *r=0;
    char c, d;
    int p=1;
    do
    {
        printf("Unesi znak (0 za prekid): ");
        scanf("%c%*c", &c);
        if(c!='0')
        {
            dodaj_na_stek(&tos, &c);
            dodaj_u_red(&f, &r, &c);
        }
    }while(c!='0');
    while(brisi_iz_reda(&f, &r, &c) && ukloni_sa_steka(&tos, &d)){
        if(c!=d){
            p=0;
        }
        printf("%c", c);
    }
    printf("\nRijec %s palindrom.\n", p?"jeste":"nije");
    return 0;
}
