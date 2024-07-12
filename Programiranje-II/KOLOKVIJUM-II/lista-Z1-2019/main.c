#include <stdio.h>
#include <stdlib.h>

/**Neka je dat sljedeći tip podataka:
typedef struct cvor {
int info; // inf. sadrzaj
struct cvor *lijevi, *desni;
} CVOR;
kojim se reprezentuje čvor dvostruko povezane kružne
liste i koja se može predstaviti vizuelno na sljedeći
način:
Napisati funkciju čiji je prototip:
CVOR* dodaj_pocetak(CVOR **plista, int podatak);
Funkcija vrši dodavanje novog čvora na početak liste
te isti vraća kao rezultat. Pri tome je parametar plista
spoljašnji pokazivač na listu koji pokazuje na prvi čvor
liste, a parametar podatak informacioni sadržaj novog
čvora liste koji koji se dodaje na početak iste*/

typedef struct cvor {
int info; // inf. sadrzaj
struct cvor *lijevi, *desni;
} CVOR;

CVOR* dodaj_pocetak(CVOR **plista, int podatak){
    CVOR *novi = (CVOR*)calloc(1, sizeof(CVOR));
    novi->info = podatak;

    if(*plista==0){
        *plista = novi;
        novi->desni = novi->lijevi = novi;
    }else{
        novi->desni = *plista;
        novi->lijevi = (*plista)->lijevi;
        (*plista)->lijevi->desni = novi;
        (*plista)->lijevi = novi;
        *plista = novi;
    }
    return novi;
}

void brisi(CVOR **plista){
    while(*plista != (*plista)->desni){
        CVOR *pom = *plista;
        pom->desni->lijevi = (*plista)->lijevi;
        (*plista)->lijevi->desni = pom->desni;
        *plista = pom->desni;
        free(pom);
    }
    free(*plista);
}

void pisi(CVOR *lista){
    CVOR *pom = lista;
    do{
        printf("%d ", pom->info);
        pom=pom->desni;
    }while(pom!=lista);
    printf("\n");
}

int main()
{
    CVOR *lista=0;
    for(int i=1;i<6;i++){
        lista = dodaj_pocetak(&lista, i);
        pisi(lista);
    }
    brisi(&lista);
    return 0;
}
