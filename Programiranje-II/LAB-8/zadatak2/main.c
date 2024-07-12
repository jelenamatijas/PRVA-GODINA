#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/**Potrebno je definisati strukturu kružni bafer koja služi za smještanje prirodnih brojeva, pri čemu je
potrebno koristiti sekvencijalnu reprezentaciju bafera bez prepisivanja. U baferu se može nalaziti
maksimalno pet elemenata.
Korisniku se prikazuje meni putem kojeg može da vrši:
• dodavanje novog elementa u bafer,
• uklanjanje elementa iz bafera i
• ispis svih elemenata iz bafera na standardnom izlazu.
Unosom broja 0 korisnik prekida izvršavanje programa, nakon čega se na standardnom izlazu ispisuju
svi elementi koji su uneseni tokom izvršavanja programa, ali u obrnutom redoslijedu. Za čuvanje i ispis
svih unesenih elemenata koristiti ulančanu reprezentaciju steka (LIFO disciplina pristupa).
Napomena: ukoliko korisnik pokuša da doda novi element u pun bafer ili da ukloni element iz praznog
bafera potrebno je ispisati poruku upozorenja na standardni izlaz.*/

typedef struct red
{
    int niz[MAX], f, r;
} RED;

typedef struct cvor
{
    int br;
    struct cvor *next;
} CVOR;

/** ==================== BAFER ==================== */

int isFULL(RED *bafer)
{
    return (bafer->r+1)%MAX == bafer->f;
}
int isEmpty(RED *bafer)
{
    return bafer->f == -1;
}

int dodaj(RED *bafer, int br)
{
    if(isFULL(bafer))return 0;
    if(bafer->f == -1)
        bafer->f = 0;
    bafer->r = (bafer->r+1)%MAX;
    bafer->niz[bafer->r]=br;
    return 1;
}

int brisi(RED *bafer, int *br)
{
    if(isEmpty(bafer))return 0;
    *br = bafer->niz[bafer->f];
    if(bafer->f == bafer->r)
        bafer->f = bafer->r = -1;
    else
        bafer->f = (bafer->f+1)%MAX;
    return 1;
}

int citaj(RED *bafer)
{
    if(bafer->f == -1)return 0;
    int i=bafer->f;
    if(i<=bafer->r)
    {
        while(i<=bafer->r)
            printf("%d ", bafer->niz[i++]);
    }
    else
    {
        while(i<=MAX-1){
            printf("%d ", bafer->niz[i++]);
        }
        i=0;
        while(i<=bafer->r){
            printf("%d ", bafer->niz[i++]);
        }
    }
    printf("\n");
    return 1;
}

/** ==================== STEK ==================== */

void push(CVOR **tos, int br)
{
    CVOR *novi = (CVOR*)calloc(sizeof(CVOR), 1);
    novi->br = br;
    novi->next = *tos;
    *tos=novi;
}

int pop(CVOR **tos, int *br)
{
    if(*tos == 0)return 0;
    *br = (*tos)->br;
    CVOR *p = *tos;
    *tos = p->next;
    free(p);
    return 1;
}

int main()
{
    RED bafer;
    bafer.f = bafer.r = -1;
    CVOR *tos=0;
    int x;
    char c;
    do
    {
        printf("=======================================================\n");
        printf("Dodavanje [D], uklanjanje [U], ispisivanje [I], kraj [0]? ");
        scanf("\n%c", &c);
        if (c == 'D')
        {
            scanf("%d", &x);
            if(!dodaj(&bafer, x))printf("Bafer je pun!\n");
            push(&tos, x);
        }
        else if (c == 'U')
        {
            if (brisi(&bafer, &x))
                printf("  Obrisano je: %d\n", x);
            else
                printf("  Bafer je prazan!\n");
        }
        else if(c == 'I')
        {
            if (!citaj(&bafer))
                printf("  Bafer je prazan!\n");
        }
    }
    while (c != '0');
    printf("KRAJ!\n");

    printf("Svi uneseni brojevi:\n");
    while(pop(&tos, &x))printf("%d ", x);

    return 0;
}
