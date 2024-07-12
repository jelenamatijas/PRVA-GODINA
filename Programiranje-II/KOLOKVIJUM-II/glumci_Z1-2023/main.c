#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Neka su dati tipovi:
typedef struct glumac {
char *ime, *prezime;
} GLUMAC;
typedef struct film {
GLUMAC *niz;
int n; //broj glumaca u filmu
} FILM;
kojim se reprezentuju glumac i film u kojem glume
glumci, respektivno.
Neka su dati tipovi:
typedef struct glumac_pojavljivanja {
char *ime, *prezime;
int broj_pojavljivanja;
} GLUMAC_POJAVLJIVANJA;
typedef struct cvor {
GLUMAC_POJAVLJIVANJA gp;
struct cvor *sljedeci;
} CVOR;
kojim se reprezentuju glumac sa ukupnim brojem
pojavljivanja u svim filmovima i čvor jednostruko
povezane liste čiji je informacioni sadržaj glumac
sa brojem pojavljivanja u filmovima, respektivno.
Napisati funkciju koja iz niza filmova kreira
jednostruko povezanu listu u čijim su čvorovima
informacioni sadržaj glumci (tip
GLUMAC_POJAVLJIVANJA) sa ukupnim brojem
pojavljivanja u svim filmovima. Funkcija kao
rezultat vraća glavu liste.
Glumac se jedinstveno identifikuje imenom i
prezimenom (u obzir uzeti velika i mala slova).
Prototip funkcije je:
CVOR* dodaj(FILM *f, int n);
Pri tome je parametar f adresa niza filmova, a
parametar n broj filmova u nizu*/


typedef struct glumac {
char *ime, *prezime;
} GLUMAC;

typedef struct film {
GLUMAC *niz;
int n; //broj glumaca u filmu
} FILM;

typedef struct glumac_pojavljivanja {
char *ime, *prezime;
int broj_pojavljivanja;
} GLUMAC_POJAVLJIVANJA;

typedef struct cvor {
GLUMAC_POJAVLJIVANJA gp;
struct cvor *sljedeci;
} CVOR;

CVOR* trazi(CVOR *lista, GLUMAC *g){
    while(lista){
        if(!strcmp(lista->gp.ime, g->ime) && !strcmp(lista->gp.prezime, g->prezime))
            return lista;
        lista = lista->sljedeci;
    }
    return NULL;
}

CVOR* dodaj(FILM *f, int n){
    CVOR *lista = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j < f[i].n; j++){
            CVOR *pom = trazi(lista, &f[i].niz[j]);
            if(pom!=NULL)pom->gp.broj_pojavljivanja++;
            else{
                CVOR *novi = (CVOR*)calloc(1, sizeof(CVOR));

                novi->gp.ime = (char*)calloc(strlen(f[i].niz[j].ime)+1, sizeof(char));
                strcpy(novi->gp.ime, f[i].niz[j].ime);
                novi->gp.prezime = (char*)calloc(strlen(f[i].niz[j].prezime)+1, sizeof(char));
                strcpy(novi->gp.prezime, f[i].niz[j].prezime);

                novi->gp.broj_pojavljivanja++;
                novi->sljedeci = lista;
                lista = novi;
            }
        }
    }
    return lista;
}

void obrisi_listu(CVOR *glava) {
    while (glava != NULL) {
        CVOR *temp = glava;
        glava = glava->sljedeci;
        free(temp);
    }
}

int main()
{
    FILM filmovi[2];
    GLUMAC glumac1 = {"Brad", "Pitt"};
    GLUMAC glumac2 = {"Angelina", "Jolie"};
    GLUMAC glumac3 = {"Tom", "Cruise"};
    GLUMAC glumac4 = {"Jennifer", "Aniston"};
    filmovi[0].niz = (GLUMAC*)malloc(2 * sizeof(GLUMAC));
    filmovi[0].niz[0] = glumac1;
    filmovi[0].niz[1] = glumac2;
    filmovi[0].n = 2;
    filmovi[1].niz = (GLUMAC*)malloc(2 * sizeof(GLUMAC));
    filmovi[1].niz[0] = glumac3;
    filmovi[1].niz[1] = glumac2;
    filmovi[1].n = 2;

    CVOR *glava_liste = dodaj(filmovi, 2);

    CVOR *trenutni = glava_liste;
    while (trenutni != NULL) {
        printf("%s %s - Broj pojavljivanja: %d\n", trenutni->gp.ime, trenutni->gp.prezime, trenutni->gp.broj_pojavljivanja);
        trenutni = trenutni->sljedeci;
    }


    obrisi_listu(glava_liste);


    for (int i = 0; i < 2; i++) {
        free(filmovi[i].niz);
    }
    return 0;
}
