#include <stdio.h>
#include <stdlib.h>

/**(10 bodova) Neka je dat tip:
typedef struct node {
int info;
struct node *next;
} NODE;
kojim se reprezentuje čvor jednostruko ulančane
liste.
Neka je dat tip:
typedef struct graph {
int n; // broj cvorova
NODE **al; // liste susjednosti tj. niz od
// n ulancanih listi
} GRAPH;
koji predstavlja ulančanu reprezentaciju
usmjerenog grafa kod kojeg liste susjednosti ne
moraju biti uređene.
Napisati funkciju koja određuje i vraća broj
susjeda čvora čiji je indeks u. Prototip funkcije
je:
int broj_susjeda(GRAPH *g, int u);
Napisati funkciju koja dodaje novu granu između
čvorova čiji su indeksi u i v. Ako ta grana već
postoji u grafu, ignorisati pokušaj dodavanja
grane. Prototip funkcije je:
void dodaj_granu(GRAPH *g, int u, int v);*/

#define MAX 100

typedef struct cvor
{
    int info;
    struct cvor *sljedeci;
} CVOR;

typedef struct graf
{
    int n;
    CVOR *cvorovi[MAX];
} GRAF;

typedef struct red
{
    int niz[MAX];
    int f, r;
} RED;

int isFull(RED *red)
{
    return red->r == MAX;
}

int isEmpty(RED *red)
{
    return red->f == -1 || red->f == red->r;
}

int dodaj(RED *red, int podatak)
{
    if (isFull(red)) return 0;
    if (red->f == -1) red->f = 0;
    red->niz[red->r++] = podatak;
    return 1;
}

int obrisi(RED *red, int *podatak)
{
    if (isEmpty(red)) return 0;
    *podatak = red->niz[red->f++];
    return 1;
}
void bfs(GRAF g, int start)
{
    RED red;
    red.f = -1;
    red.r = 0;
    int v;
    char visit[MAX] = { 0 };
    visit[start] = 1;
    dodaj(&red, start);
    while (obrisi(&red, &v))
    {
        printf("%d ", v + 1);
        CVOR *tekuci=g.cvorovi[v];
        while (tekuci)
        {
            int u = tekuci->info;
            if (!visit[u])
            {
                visit[u] = 1;
                dodaj(&red, u);
            }
            tekuci = tekuci->sljedeci;
        }
    }
}
void pisi_susjede(CVOR *glava)
{
    while (glava)
    {
        printf(" %d", glava->info + 1);
        glava = glava->sljedeci;
    }
}
void brisi_graf(GRAF *g)
{
    int i;
    for (i = 0; i<g->n; i++)
        brisi_listu(&g->cvorovi[i]);
}
CVOR* dodaj_kraj(CVOR **pglava, int info)
{
    CVOR *p, *novi = (CVOR *) malloc(sizeof(CVOR));
    novi->info = info;
    novi->sljedeci = 0;
    if (*pglava == 0)
        *pglava = novi;
    else
    {
        for (p = *pglava; p->sljedeci; p=p->sljedeci);
        p->sljedeci = novi;
    }
    return novi;
}
void brisi_listu(CVOR **pglava)
{
    while (*pglava)
    {
        CVOR *p = (*pglava)->sljedeci;
        free(*pglava);
        *pglava = p;
    }
}

void ucitaj_graf(GRAF *g)
{
    int i, j, br_susjeda, susjed;
    printf("Unesite broj cvorova grafa : ");
    scanf("%d", &g->n);
    for (i = 0; i<g->n; i++)
    {
        g->cvorovi[i] = NULL;
        printf("  Broj susjeda cvora %d: ", i + 1);
        scanf("%d", &br_susjeda);
        for (j = 0; j<br_susjeda; j++)
        {
            do
            {
                printf("    %d. susjed cvora %d: ", j + 1, i + 1);
                scanf("%d", &susjed);
            }
            while (susjed<1 && susjed>g->n);
            dodaj_kraj(&g->cvorovi[i], susjed - 1);
        }
    }
}

/**------------------------------------------*/

int br_s(CVOR *head)
{
    int br=0;
    while(head)
    {
        br++;
        head = head->sljedeci;
    }
    return br;
}

int broj_susjeda(GRAF g, int u)
{
    return br_s(g.cvorovi[u]);
}

void dodaj_granu(GRAF *g, int u, int v){
    CVOR *pom = g->cvorovi[u];
    while(pom!=NULL){
        if(pom->info == v)
            return;
        pom=pom->sljedeci;
    }

    CVOR *novi = (CVOR*)calloc(1, sizeof(CVOR));
    novi->info = v;
    novi->sljedeci = g->cvorovi[u];
    g->cvorovi[u] = novi;
}

int main()
{
    GRAF g;
    int i;
    ucitaj_graf(&g);
    printf("\nBroj susjeda cvorova:\n");
    for (i = 0; i<g.n; i++)
    {
        printf("  %d: %d\n", i + 1,broj_susjeda(g,i));
    }

    int u, v;
    printf("\nDodaj novu granu: \n");
    printf("Unesite cvor u: ");
    scanf("%d", &u);
    printf("Unesite cvor v: ");
    scanf("%d", &v);
    dodaj_granu(&g, u - 1, v - 1);

    printf("\nBroj susjeda nakon dodavanja nove grane:\n");
    for (int i = 0; i < g.n; i++) {
        printf("  %d: %d\n", i + 1, broj_susjeda(g, i));
    }

    brisi_graf(&g);
    return 0;
}
