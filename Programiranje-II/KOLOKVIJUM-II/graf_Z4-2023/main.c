#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**Neka je dat tip:
typedef struct grad {
char naziv[101];
} GRAD;
kojim se reprezentuju podaci o gradu.
Neka je dat tip:
typedef struct graf {
int n; // broj čvorova
GRAD gradovi[100]; // informacioni
//sadržaj
int ms[100][100]; //matrica
//susjednosti
//težinskog,
//neusmjerenog
//grafa
} GRAF;
kojim se reprezentuje neusmjeren težinski graf sa
najviše stotinu čvorova kojim su predstavljeni
gradovi i njihova povezanost (rastojanje u km).
Napisati funkciju koja za dati graf gf i grad gr
ispisuje najkraće rastojanje od grada gr do svih
dostupnih gradova. Za svaki dostupni grad ispisati
naziv i koja je najkraća udaljenost od zadatog
grada.
Prototip funkcije je:
void dostupni(GRAF gf, GRAD gr);*/

#define MAX 100

typedef struct grad
{
    char naziv[101];
} GRAD;

typedef struct graf
{
    int n; // broj čvorova
    GRAD gradovi[100]; // informacioni
//sadržaj
    int ms[100][100]; //matrica
//susjednosti
//težinskog,
//neusmjerenog
//grafa
} GRAF;

void floyd(GRAF gf, int d[MAX][MAX])
{
    for(int k=0; k<gf.n; k++)
    {
        for(int i=0; i<gf.n; i++)
        {
            for(int j=0; j<gf.n; j++)
            {
                if(d[i][k]!=INT_MAX && d[k][j]!=INT_MAX && d[i][j]<d[i][k]+d[k][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
}

void dostupni(GRAF gf, GRAD gr)
{
    int d[MAX][MAX];
    int gr_i=-1;

    for(int i=0;i<gf.n;i++){
        if(!strcmp(gf.gradovi[i].naziv, gr.naziv))gr_i=i;
        for(int j=0;j<gf.n;j++){
            d[i][j] = i==j ? 0 : (gf.ms[i][j] ? gf.ms[i][j] : INT_MAX);
        }
    }
    if(gr_i==-1){
        printf("Ne postoji dati grad.\n");
        return;
    }

    floyd(gf, d);
    printf("Najkrace rastojanja od grada %s do drugih gradova:\n", gr.naziv);
    for(int j=0;j<gf.n;j++){
        if(gr_i!=j && d[gr_i][j]<INT_MAX)
            printf("%s: %dkm\n", gf.gradovi[j].naziv, d[gr_i][j]);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
