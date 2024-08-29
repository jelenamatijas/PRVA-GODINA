#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/**Napisati program za obradu artikala. Potrebno je koristiti kružni bafer za čuvanje artikala. Artikal se smatra obrađenim
nakon što se doda u kružni bafer, tako da nakon obrade više nije potreban, tj. moguće ga je prebrisati novim artiklom koji dođe u bafer.
Definisati tip ARTIKAL kojim se reprezentuje artikal (podaci koji se vode o artiklu su: naziv, količina i cijena).*/

typedef struct artikli
{
    char naziv[11];
    float kolicina, cijena;
} ARTIKLI;

typedef struct red
{
    ARTIKLI niz[MAX];
    int f,r;
} RED;

int isFull(RED *bafer)
{
    return (bafer->r+1)%MAX == bafer->f;
}
int isEmpty(RED *bafer)
{
    return bafer->f == -1;
}

void dodaj(RED *bafer, ARTIKLI *a)
{
    if(isFull(bafer))
        bafer->f = (bafer->f+1)%MAX;
    if(bafer->f == -1)
        bafer->f = 0;
    bafer->r = (bafer->r+1)%MAX;
    bafer->niz[bafer->r] = *a;
}

int brisi(RED *bafer, ARTIKLI *a)
{
    if(isEmpty(bafer))return 0;
    *a = bafer->niz[bafer->f];
    if(bafer->f == bafer->r)
        bafer->f = bafer->r = -1;
    else
        bafer->f = (bafer->f+1)%MAX;
    return 1;
}


void citaj(ARTIKLI *a)
{
    printf("Unesi naziv, kolicinu i cijenu artikla:\n");
    scanf("%s%f%f", a->naziv, &a->kolicina, &a->cijena);
}

int main()
{
    RED bafer;
    bafer.f = bafer.r = -1;
    ARTIKLI a;
    char c;
    do
    {
        printf("=======================================================\n");
        printf("Dodavanje [D], obrada [O], kraj [0]? ");
        scanf("\n%c", &c);
        if (c == 'D')
        {
            citaj(&a);
            dodaj(&bafer, &a);
        }
        else if (c == 'O')
        {
            if (brisi(&bafer, &a))
                printf("  Obradjen artikl: %s %.2f %.2f\n", a.naziv, a.kolicina, a.cijena);
            else
                printf("  Bafer je prazan!\n");
        }
        else if (c != '0') printf("  Nepoznata opcija - '%c'.\n", c);
    }
    while (c != '0');
    printf("KRAJ!\n");

    return 0;
}

