#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Neka je dat tip:
typedef struct nastavnik {
char *ime, *prezime;
} NASTAVNIK;
kojim se reprezentuje tip nastavnik.
Neka je dat tip:
typedef struct predmet {
char *naziv;
NASTAVNIK *niz;
int n;
} PREDMET;
kojim se reprezentuje tip predmet, pri čemu je
niz adresa početka niza nastavnika, a n broj
elemenata niza.
Neka je dat tip:
typedef struct node {
PREDMET predmet;
struct node *left, *right;
} NODE;
kojim se reprezentuje čvor dvostruko povezane
liste čiji je informacioni sadržaj predmet.
Napisati funkciju koja briše iz dvostruko
povezane liste (parametri head i tail) sve čvorove
koji ispunjavaju određeni uslov. Čvorovi za
brisanje ispunjavaju uslov ukoliko pokazivač na
funkciju (parametar criteria) koji je proslijeđen
kao argument funkcije vraća vrijednost 1 za
trenutni čvor. Prototip funkcije je:
void deleteNodes(NODE **head, NODE **tail , int
(*criteria)(NODE *n))*/


typedef struct nastavnik
{
    char *ime, *prezime;
} NASTAVNIK;

typedef struct predmet
{
    char *naziv;
    NASTAVNIK *niz;
    int n;
} PREDMET;

typedef struct node
{
    PREDMET predmet;
    struct node *left, *right;
} NODE;

int criteria(NODE *node)
{
    return node->predmet.n > 1 ? 1 : 0;
}

void deleteNodes(NODE **head, NODE **tail , int(*criteria)(NODE *n))
{
    NODE *pom = *head;
    while(pom)
    {
        NODE *next = pom->right;
        if(criteria(pom)==1)
        {
            if(*head == pom)
            {
                *head = pom->right;
                (*head)->left=0;
            }
            else if(*tail == pom)
            {
                (*tail)->left->right = 0;
                *tail = (*tail)->left;
            }
            else
            {
                pom->left->right = pom->right;
                pom->right->left = pom->left;
            }
            freeNode(pom);
        }
        pom = next;
    }
}

void addNode(NODE **head, NODE **tail, PREDMET *p)
{
    NODE *newNode = (NODE*)calloc(1, sizeof(NODE));
    newNode->predmet = *p;
    if(*head == 0)*head=*tail=newNode;
    else
    {
        newNode->left = *tail;
        (*tail)->right = newNode;
        *tail = newNode;
    }
}

void freeNode(NODE *head)
{
    free(head->predmet.naziv);
    for(int i=0; i<head->predmet.n; i++)
    {
        free(head->predmet.niz[i].ime);
        free(head->predmet.niz[i].prezime);
    }
    free(head->predmet.niz);
    free(head);
}

void deleteList(NODE **head, NODE **tail)
{
    while(*head)
    {
        NODE *pom = (*head)->right;
        freeNode(*head);
        *head = pom;
    }
    *tail = NULL;
}

void write(NODE *head)
{
    while(head)
    {
        printf("%s\n", head->predmet.naziv);
        head = head->right;
    }
}

void unesiPredmet(PREDMET *p)
{
    char s[20], s1[20];
    printf("Unesi naziv predmeta: ");
    scanf("%s", s);
    p->naziv = (char*)calloc(sizeof(char), strlen(s)+1);
    strcpy(p->naziv, s);
    printf("Unesi koliko nastavnika predaje taj predmet: ");
    int n;
    scanf("%d", &n);
    p->n = n;
    p->niz = (NASTAVNIK*)calloc(n, sizeof(NASTAVNIK));
    for(int i=0; i<n; i++)
    {
        printf("Unesi ime i prezime %d. nastavnika: ", i+1);
        scanf("%s%s", s, s1);

        p->niz[i].ime = (char*)calloc(sizeof(char), strlen(s)+1);
        strcpy(p->niz[i].ime, s);
        p->niz[i].prezime = (char*)calloc(sizeof(char), strlen(s1)+1);
        strcpy(p->niz[i].prezime, s1);
    }
}

int main()
{
    NODE *head=0, *tail=0;
    PREDMET p;
    unesiPredmet(&p);
    addNode(&head, &tail, &p);
    unesiPredmet(&p);
    addNode(&head, &tail, &p);
    unesiPredmet(&p);
    addNode(&head, &tail, &p);
    unesiPredmet(&p);
    addNode(&head, &tail, &p);
    write(head);

    deleteNodes(&head, &tail, criteria);
    printf("==========================\n");
    write(head);

    deleteList(&head, &tail);
    return 0;
}
