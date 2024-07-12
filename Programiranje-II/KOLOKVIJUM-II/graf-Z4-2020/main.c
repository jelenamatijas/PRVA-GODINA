#include <stdio.h>
#include <stdlib.h>

/**Neka je dat tip:
typedef struct {
int n; // broj cvorova
char znakovi[100]; // inf. sadrzaj
int ms[100][100];
} GRAF;
kojim se reprezentuje usmjeren graf sa najviše sto
čvorova. Napisati funkciju koja za zadati graf g
(parametar funkcije) vraća redni broj čvora sa
indeksom kraj (parametar funkcije) prilikom obilaska
grafa po dubini (DFS), pri čemu obilazak treba da
započne od čvora čiji je indeks start (parametar
funkcije). Ukoliko čvor sa indeksom kraj nije dostižan
pri DFS obilasku počevši od čvora sa indeksom start,
funkcija treba da vrati 0. Prototip funkcije je:
int dfs_rb(GRAF *g, int start, int kraj);*/

typedef struct {
int n; // broj cvorova
char znakovi[100]; // inf. sadrzaj
int ms[100][100];
} GRAF;

int dfs_visit(GRAF *g, int u, int kraj, int *visited, int *indeks)
{
    visited[u]=1;

    if(u==kraj)return *indeks;

    for (int i = 0; i < g->n; i++) {
        if (g->ms[u][i] && !visited[i]) {
            (*indeks)++;
            int result = dfs_visit(g, i, kraj, visited, indeks);
            if (result != 0) {
                return result;
            }
            (*indeks)--;
        }
    }
    visited[u]=0;
    return 0;
}

int dfs_rb(GRAF *g, int start, int kraj)
{
    int visited[100]= {0};
    int indeks=1;
    return dfs_visit(g, start, kraj, visited, &indeks);
}

int main()
{
    GRAF g = { 6, { '1', '2', '3', '4', '5', '6' },
             { { 0, 1, 1, 1, 0, 0 },
               { 1, 0, 0, 1, 0, 0 },
               { 1, 0, 0, 1, 1, 0 },
               { 1, 1, 1, 0, 1, 0 },
               { 0, 0, 1, 1, 0, 1 },
               { 0, 0, 0, 0, 1, 0 } } };

    int start = 0; // indeks čvora 1
    int kraj = 2;  // indeks čvora 4

    int rezultat = dfs_rb(&g, start, kraj);
    printf("Redni broj cvora %d prilikom DFS obilaska: %d\n", kraj, rezultat);
    return 0;
}
