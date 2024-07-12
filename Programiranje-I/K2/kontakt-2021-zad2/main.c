#include <stdio.h>
#include <stdlib.h>
/*Neka su definisani tipovi:
typedef struct datum {
int d, m, g; // dan, mesec, godina
} DATUM;
typedef struct kontakt {
char ime[21], prezime[21], broj_telefona[21];
DATUM datum_rodjenja;
} KONTAKT;
kojima se reprezentuju datum i podaci o jednom
kontaktu u imeniku, respektivno.
Napisati funkciju koja sa standardnog ulaza učitava
i vraća podatke o kontaktu, a čiji je prototip:
KONTAKT ucitaj();
Napisati funkciju koja ispisuje podatke o jednom
kontaktu, a čiji je prototip:
void ispisi(KONTAKT *k);
Napisati funkciju koja ispisuje podatke o
kontaktima koji su rođeni na zadati datum d, a čiji
je prototip:
void ispisi_r(KONTAKT *niz, int n, DATUM d);
U glavnoj funkciji učitati podatke za n kontakata i
formirati odgovarajući dinamički niz, pa ispisati
podatke o kontaktima rođenim na današnji dan
2001. godine.*/

typedef struct datum
{
    int d, m, g; // dan, mesec, godina
} DATUM;
typedef struct kontakt
{
    char ime[21], prezime[21], broj_telefona[21];
    DATUM datum_rodjenja;
} KONTAKT;

KONTAKT ucitaj();
void ispisi(KONTAKT *k);
void ispisi_r(KONTAKT *niz, int n, DATUM d);

int main()
{
    int n;
    do{
        printf("Unesi broj kontakata: ");
        scanf("%d", &n);

    }while(n<1);
    KONTAKT *kontakti =(KONTAKT *)malloc(sizeof(KONTAKT)*n);
    if(kontakti==NULL){
        printf("Alokacija memorije nije bila moguca.");
        return 0;
    }
    for(int i=0;i<n;i++){
        kontakti[i]=ucitaj();
    }
    DATUM danas = {9,1,2001};
    ispisi_r(kontakti, n, danas);
    free(kontakti);
    return 0;
}

KONTAKT ucitaj(){
    KONTAKT k;
    printf("Unesi ime kontakta: ");
    scanf("%s", &k.ime);
    printf("Unesi prezime kontakta: ");
    scanf("%s", &k.prezime);
    printf("Unesi broj telefona: ");
    scanf("%s%c",&k.broj_telefona);
    DATUM dat;
    printf("Unesi datum rodjenja kontakta: ");
    scanf("%d%d%d",&dat.d, &dat.m, &dat.g);
    k.datum_rodjenja=dat;
    return k;
}
void ispisi(KONTAKT *k){
    printf("%s %s %d.%d.%d. %s\n", k->ime, k->prezime, k->datum_rodjenja.d, k->datum_rodjenja.m, k->datum_rodjenja.g, k->broj_telefona);
}

void ispisi_r(KONTAKT *niz, int n, DATUM d){
    for(int i=0;i<n;i++){
        if(niz[i].datum_rodjenja.d==d.d && niz[i].datum_rodjenja.m==d.m && niz[i].datum_rodjenja.g==d.g){
            ispisi(&niz[i]);
        }
    }
}
