#include <stdio.h>
#include <stdlib.h>
/* Neka je definisan tip:
typedef struct dokument {
char naziv[20], autor[20];
int s; // broj strana
} DOKUMENT;
kojim se reprezentuju podaci o dokumentu.
Napisati funkciju koja učitava prirodan broj n, a
zatim učitava i vraća (dinamički) niz podataka o n
dokumenata. Učitanu vrednost n funkcija vraća
preko parametra pn. Prototip funkcije je:
DOKUMENT* ucitaj(int *pn);
Napisati funkciju koja sortira niz od n dokumenata
opadajuće po broju strana, a čiji je prototip:
void sortiraj(DOKUMENT *niz, int n);
Napisati glavnu funkciju u kojoj treba (korištenjem
funkcije ucitaj) učitati i formirati dinamički niz
podataka o dokumentima, a zatim sortirati i
ispisati sortirani niz podataka o dokumentima.*/

typedef struct dokument
{
    char naziv[20], autor[20];
    int s; // broj strana
} DOKUMENT;

DOKUMENT* ucitaj(int *pn);
void sortiraj(DOKUMENT *niz, int n);

int main()
{
    DOKUMENT *dokumenti;
    int n;
    dokumenti = ucitaj(&n);
    if(dokumenti!=NULL){
        sortiraj(dokumenti, n);
        printf("Sortirani dokumenti:\n");
        for(int i=0;i<n;i++){
            printf("%-20s %-20s %d\n", dokumenti[i].naziv, dokumenti[i].autor, dokumenti[i].s);
        }
        free(dokumenti);
        dokumenti=NULL;
    }
    return 0;
}

DOKUMENT* ucitaj(int *pn)
{
    do
    {
        printf("Unesi broj dokumenta: ");
        scanf("%d", pn);
    }
    while(*pn<1);
    DOKUMENT *d = (DOKUMENT*)malloc(sizeof(DOKUMENT)**pn);
    if(d==NULL){
        return NULL;
    }
    printf("UNESI PODATKE O DOKUMENTIMA:\n");
    for(int i=0;i<*pn;i++){
        printf("Unesi naziv dokumenta: ");
        scanf("%s", &d[i].naziv);
        printf("Unesi ime autora: ");
        scanf("%s", &d[i].autor);
        printf("Unesi broj strana dokumenta: ");
        scanf("%d", &d[i].s);
    }
    return d;
}

void sortiraj(DOKUMENT *niz, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(niz[i].s<niz[j].s){
                DOKUMENT s=niz[i];
                niz[i]=niz[j];
                niz[j]=s;
            }
        }
    }
}
