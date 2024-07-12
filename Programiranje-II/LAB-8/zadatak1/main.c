#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
/**Potrebno je definisati linearnu strukturu sa FIFO disciplinom pristupa (red) koja služi za smještanje
podataka o procesima, pri čemu je potrebno koristiti ulančanu reprezentaciju reda. Podaci koji se vode o
procesu su: naziv procesa i vrijeme izvršavanja u sekundama. Potrebno je napisati program kojim se
simulira izvršavanje procêsa u realnom vremenu. Korisnik sa standardnog ulaza unosi broj procêsa koji
će se izvršavati. Naziv procesa (“proces” + redni_broj_procesa) i vrijeme izvršavanja (poziv funkcije
rand() iz stdlib.h biblioteke) se dodjeljuju automatski prilikom kreiranja novog elementa reda i ispisuju
na standardni izlaz.
Primjer:
naziv_procesa: proces1; vrijeme_izvrsavanja: 3s
naziv_procesa: proces2; vrijeme_izvrsavanja: 5s
naziv_procesa: proces3; vrijeme_izvrsavanja: 4s
Izvršavanje procesa se pokreće kada korisnik unese riječ “START” sa standardnog ulaza. Izvršavanje
jednog procesa podrazumijeva ispis naziva procesa na standardni izlaz i zaustavljanje izvršavanja
glavnog programa pozivom funkcije sleep() iz unistd.h biblioteke (ili neke druge funkcije koja ima istu
namjenu). Program se završava kada se izvrše (uklone) svi procesi iz reda.
Napomene:
• Za generisanje različitih cijelih brojeva, prije poziva funkcije rand() pozvati sljedeću liniju
kôda:
srand (time(NULL));
• Maksimalno vrijeme izvršavanja procesa ograničiti na pet sekundi, a minimalno na jednu
sekundu.*/

typedef struct proces
{
    char naziv[13];
    unsigned int vrijeme;
} PROCES;

typedef struct red
{
    PROCES p;
    struct red *next;
} RED;

void dodaj(RED **f, RED **r, PROCES *p)
{
    RED *novi = (RED*)calloc(sizeof(RED), 1);
    novi->p = *p;
    if(*f==NULL)*f=*r=novi;
    else
    {
        (*r)->next = novi;
        *r = novi;
    }
}

int brisi(RED **f, RED **r, PROCES *proces)
{
    if(*f==NULL)return 0;
    RED *pom=*f;
    *proces = pom->p;
    if(*f == *r)*f = *r = 0;
    else *f = pom->next;
    free(pom);
    return 1;
}

int main()
{
    RED *f=0, *r=0;
    int br;
    PROCES p;
    printf("Unesi broj procesa: ");
    scanf("%d", &br);
    srand(time(NULL));

    for(int i = 1; i <= br; i++) {
        snprintf(p.naziv, sizeof(p.naziv), "proces%d", i);
        p.vrijeme = rand() % 5 + 1;
        dodaj(&f, &r, &p);
    }

    char start[6];

    printf("Unesi 'START' za pokretanje procesa: ");
    scanf("%s", start);

    if (strcmp(start, "START") == 0) {
        while(brisi(&f, &r, &p)) {
            printf("naziv_procesa: %s; vrijeme_izvrsavanja: %ds\n", p.naziv, p.vrijeme);
            Sleep(p.vrijeme * 1000);
        }
    }

    printf("Svi procesi su izvrseni.\n");
    return 0;
}
