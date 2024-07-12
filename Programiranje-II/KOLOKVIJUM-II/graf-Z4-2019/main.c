#include <stdio.h>
#include <stdlib.h>

/**Neka su dati tipovi:
typedef struct node {
int ind; // inf. sadrzaj
struct node *next;
} NODE;
i
typedef struct graph {
int n; // broj cvorova grafa, 0 <= n <= 50
char *infos[50]; // inf. sadrzaj cvorova grafa
NODE *heads[50]; // niz zaglavlja
} GRAPH;
kojima se reprezentuju čvor jednostruko povezane
liste i netežinski graf (ulančana reprezentacija),
respektivno.
Napisati funkciju koja određuje i vraća ulazni stepen
čvora sa indeksom ind datog usmjerenog grafa g. Ako
je indeks čvora izvan opsega, funkcija treba da vrati
vrijednost -1. Prototip funkcije je:
int in_degree(const GRAPH *g, int ind);*/

typedef struct node {
int ind; // inf. sadrzaj
struct node *next;
} NODE;

typedef struct graph {
int n; // broj cvorova grafa, 0 <= n <= 50
char *infos[50]; // inf. sadrzaj cvorova grafa
NODE *heads[50]; // niz zaglavlja
} GRAPH;

void add_edge(GRAPH *g, int from, int to) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->ind = to;
    newNode->next = g->heads[from];
    g->heads[from] = newNode;
}

// Funkcija za kreiranje grafa
GRAPH* create_graph(int n) {
    GRAPH *g = (GRAPH*)malloc(sizeof(GRAPH));
    g->n = n;
    for (int i = 0; i < n; i++) {
        g->infos[i] = NULL;
        g->heads[i] = NULL;
    }
    return g;
}

// Funkcija za dodavanje informacije o čvoru
void set_node_info(GRAPH *g, int ind, const char *info) {
    g->infos[ind] = (char*)malloc(strlen(info) + 1);
    strcpy(g->infos[ind], info);
}


// Funkcija za ispisivanje grafa
void print_graph(const GRAPH *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d (%s): ", i, g->infos[i]);
        NODE *temp = g->heads[i];
        while (temp) {
            printf("-> %d ", temp->ind);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Funkcija za oslobađanje memorije grafa
void free_graph(GRAPH *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->infos[i]);
        NODE *temp = g->heads[i];
        while (temp) {
            NODE *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(g);
}

int in_degree(const GRAPH *g, int ind){
    if(ind<0 || ind>=50)return -1;
    int degree=0;

    for(int i=0;i<g->n;i++){
        NODE *list = g->heads[i];
        while(list){
            if(list->ind == ind)
                degree++;
            list = list->next;
        }
    }

    return degree;
}

int main()
{
    int n = 5; // broj čvorova u grafu
    GRAPH *g = create_graph(n);

    set_node_info(g, 0, "Node 0");
    set_node_info(g, 1, "Node 1");
    set_node_info(g, 2, "Node 2");
    set_node_info(g, 3, "Node 3");
    set_node_info(g, 4, "Node 4");

    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 0);
    add_edge(g, 4, 1);

    print_graph(g);

    for (int i = 0; i < n; i++) {
        printf("Ulazni stepen za cvor %d (%s) je: %d\n", i, g->infos[i], in_degree(g, i));
    }

    free_graph(g);
    return 0;
}
