#include <stdio.h>
#include <stdlib.h>

/**Neka je definisan tip:
typedef struct cvor{
double k; // koeficijent clana
unsigned s; // stepen clana
struct cvor *sljedeci;
} CVOR;
kojim se reprezentuje čvor jednostruko povezane liste. Svaki čvor liste reprezentuje jedan član realnog polinoma P(x)=anxn+an-1xn-1+...+a1x+a0.
Pri tome, broj čvorova liste jednak je broju članova polinoma za koje je koeficijent ≠ 0. Takođe, u listi ne postoje dva člana istog stepena. Lista
je uređena u opadajudem redoslijedu po vrijednosti stepena člana.
Neka je definisana funkcija koja dodaje novi čvor na kraj liste:
void dodaj_kraj(CVOR **pglava, double k, unsigned s);
Definisati funkciju (dozvoljeno je korištenje samo funkcije dodaj_kraj) koja sabira dva polinoma (predstavljena odgovarajudim listama) i vrada
rezultujudi polinom (predstavljen odgovarajudom listom). Prototip funkcije je:
CVOR* saberi(CVOR *p1, CVOR *p2);*/

typedef struct cvor{
double k; // koeficijent clana
unsigned s; // stepen clana
struct cvor *sljedeci;
} CVOR;

CVOR *noviCvor(double k, unsigned s){
    CVOR *novi = (CVOR*)calloc(1,sizeof(CVOR));
    novi->k = k;
    novi->s = s;
    return novi;
}

void dodaj_kraj(CVOR **pglava, double k, unsigned s){
    CVOR *novi = noviCvor(k, s);
    if(*pglava==0)*pglava = novi;
    else{
        CVOR *pom = *pglava;
        while(pom->sljedeci)pom=pom->sljedeci;
        pom->sljedeci = novi;
    }
}

CVOR* saberi(CVOR *p1, CVOR *p2){
    CVOR *zbir=0;
    while(p1 || p2){
        if(p1->s < p2->s){
            dodaj_kraj(&zbir, p2->k, p2->s);
            p2=p2->sljedeci;
        }else if(p1->s > p2->s){
            dodaj_kraj(&zbir, p1->k, p1->s);
            p1=p1->sljedeci;
        }else{
            dodaj_kraj(&zbir, p1->k+p2->k,p1->s);
            p2=p2->sljedeci;
            p1=p1->sljedeci;
        }
    }
    if(p2!=0){
        while(p2){
            dodaj_kraj(&zbir, p2->k, p2->s);
            p2=p2->sljedeci;
        }
    }
    if(p1!=0){
        while(p1){
            dodaj_kraj(&zbir, p1->k, p1->s);
            p1=p1->sljedeci;
        }
    }
    return zbir;
}

void pisi(CVOR *glava){
    while(glava){
        printf("%c%.2lf x^%u  ", glava->k<0?' ':'+', glava->k, glava->s);
        glava = glava->sljedeci;
    }
    printf("\n");
}

void brisi_listu(CVOR **glava){
    while(*glava){
        CVOR *pom = *glava;
        *glava = pom->sljedeci;
        free(pom);
    }
}

int main()
{
    CVOR *l1=0, *l2=0;
    int n;
    double k;
    unsigned s;
    printf("Unesi broj clanova prvog polinoma: ");
    scanf("%d", &n);
    printf("Unesi polinom (k, s):\n");
    while(n--){
        scanf("%lf%u", &k, &s);
        dodaj_kraj(&l1, k, s);
    }

    printf("Unesi broj clanova drugog polinoma: ");
    scanf("%d", &n);
    printf("Unesi polinom (k, s):\n");
    while(n--){
        scanf("%lf%u", &k, &s);
        dodaj_kraj(&l2, k, s);
    }

    pisi(l1);
    pisi(l2);
    CVOR *zbir = saberi(l1, l2);
    pisi(zbir);
    free(l1);free(l2);free(zbir);
    return 0;
}
