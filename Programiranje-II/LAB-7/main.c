#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Neka je dat tip:
typedef struct node {
 void *data; // dinamicki podatak
 struct node *prev, *next;
} NODE;
kojim se reprezentuje čvor dvostruko povezane uređene liste podataka proizvoljnog tipa.
Napisati funkciju koja dodaje novi podatak (data) u listu (onemogućiti dodavanje istih podataka više
puta) tako da je poredak elemenata u listi uvijek u rastućem redoslijedu, pri čemu je prototip funkcije:
void add(NODE **phead, NODE **ptail, void *data,
 int (*cmp)(const void *, const void *));
Napisati funkciju koja briše zadati podatak (data) iz liste, a čiji je prototip:
void delete(NODE **phead, NODE **ptail, void *data,
 int (*cmp)(const void *, const void *));
Napisati funkciju koja omogućava pretraživanje liste prema zadatom podatku (data), a čiji je prototip:
NODE* search(NODE *head, NODE *tail, const void *data,
 int (*cmp)(const void *, const void *));
Napisati funkciju koja na standardni izlaz ispisuje sve podatke iz liste (svaki podatak u novom redu), a
čiji je prototip:
void write(NODE *head, void (*write_one)(const void *));
Napisati funkciju koja briše listu (obratiti pažnju na dinamički alocirane podatke u čvorovima):
void delete_list(NODE **phead, NODE **ptail);
Koristeći prethodno definisane funkcije (i neophodne dodatne funkcije), u glavnom programu ilustrovati
rad sa uređenom dvostruko povezanom listom stringova. Ilustrovati pravljenje liste sa sljedećim
stringovima: “ponedjeljak”, “utorak”, “srijeda”, “cetvrtak”, “petak” i “subota”, a zatim ispisati sadržaj
liste. Obrisati čvor sa podatkom “subota” i ponovo ispisati sadržaj liste. Pri implementaciji funkcije za
poređenje dva stringa potrebno je koristiti leksikografski poredak.
Napomene:
• Parametar cmp predstavlja pokazivač na funkciju koja vrši poređenje dva podatka proizvoljnog
tipa prema nekom kriterijumu. Funkcija za poređenje vraća negativnu vrijednost ako je prvi
podatak manji od drugog, vrijednost 0 ako su podaci jednaki te pozitivnu vrijednost ako je prvi
podatak veći od drugog.
• Parametar write_one predstavlja pokazivač na funkciju koja na standardni izlaz ispisuje jedan
podatak proizvoljnog tipa.*/


typedef struct node
{
    void *data; // dinamicki podatak
    struct node *prev, *next;
} NODE;

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

void write_one(const void *string)
{
    printf("%s\n", (char*)string);
}

NODE* search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *))
{
    if(head==0)return NULL;
    while(cmp(head->data, data)<0 && cmp(tail->data, data)>0)
    {
        head = head->next;
        tail = tail->prev;
    }
    return cmp(head->data, data)==0?head:(cmp(tail->data, data)==0?tail:0);
}


void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    if(search(*phead, *ptail, data, cmp)!=NULL)return;

    NODE *newNode = (NODE*)calloc(sizeof(NODE), 1);
    newNode->data = calloc(sizeof(void),1);
    newNode->data = data;

    if(*phead == NULL)*phead = *ptail = newNode;
    else if(cmp((*phead)->data, newNode->data)>0)
    {
        newNode->next = *phead;
        (*phead)->prev = newNode;
        *phead = newNode;
    }
    else if(cmp((*ptail)->data, newNode->data)<0)
    {
        newNode->prev = *ptail;
        (*ptail)->next = newNode;
        *ptail = newNode;
    }
    else
    {
        NODE *p = *phead, *q = (*ptail)->prev;
        for(; cmp(p->next->data, newNode->data)<0 && cmp(q->data, newNode->data)>0; p=p->next, q=q->prev);

        if(cmp(q->data, newNode->data)<0)p=q;
        newNode->next = p->next;
        newNode->prev = p;
        p->next->prev = newNode;
        p->next = newNode;
    }
}


void write(NODE *head, void (*write_one)(const void *))
{
    printf("================================\n");
    while(head)
    {
        write_one(head->data);
        head = head->next;
    }
}

void delete_node(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    NODE *del = search(*phead, *ptail, data, cmp);
    if(del==NULL)return;

    if(*phead == del && *ptail==del)*phead=*ptail=0;
    else if(*phead == del)
    {
        *phead = del->next;
        (*phead)->prev=0;
    }
    else if(*ptail == del)
    {
        *ptail = del->prev;
        (*ptail)->next=0;
    }
    else
    {
        del->next->prev = del->prev;
        del->prev->next = del->next;
    }
    free(del->data);
    free(del);
}

void delete_list(NODE **phead, NODE **ptail)
{
    while(*phead)
    {
        NODE *p = (*phead)->next;
        free((*phead)->data);
        free(*phead);
        *phead=p;
    }
    *ptail=0;
}

int main()
{
    NODE *head=0, *tail=0;
    void *days[] = {"ponedjeljak", "utorak", "srijeda", "cetvrtak", "petak", "subota"};
    for (int i = 0; i < 6; i++)
    {
        add(&head, &tail, days[i], cmp);
    }
    write(head, write_one);
    delete_node(&head, &tail, days[5], cmp);
    write(head, write_one);
    delete_list(&head, &tail);
    return 0;
}
