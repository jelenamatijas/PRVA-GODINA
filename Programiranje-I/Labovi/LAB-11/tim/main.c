#include <stdio.h>
#include <stdlib.h>
/*Definisati tip TIM kojim se reprezentuje fudbalski tim čiji su atributi naziv, broj postignutih i primljenih
golova, te broj bodova. Napisati program koji sa standardnog ulaza učitava podatke za n timova i formira
odgovarajući dinamički niz, a zatim sortira niz po opadajućoj vrijednosti broja bodova (ako ima više timova sa
istim brojem bodova, dodatni kriterijum za sortiranje je gol razlika, pa onda broj postignutih golova) i ispisuje
sortirani niz.
Za učitavanje jednog tima treba definisati i koristiti funkciju čiji je prototip:
void ucitaj(TIM *);
Za formiranje dinamičkog niza timova, koristeći funkciju ucitaj, treba definisati i koristiti funkciju čiji je
prototip:
TIM* formiraj(int *);
Za sortiranje niza podataka o timovima treba definisati i koristiti funkciju čiji je prototip:
void sortiraj(TIM *, int);
Za ispis niza podataka o timovima treba definisati i koristiti funkciju čiji je prototip:
void ispisi(TIM *, int);
pri čemu podatke o timovima treba ispisati u obliku:
RB. NAZIV GPO GPR GR BOD*/

typedef struct tim
{
    char naziv [10];
    int brPostignutih, brPrimljenih, bodovi;
} TIM;

void ucitaj(TIM *);
TIM* formiraj(int *);
void sortiraj(TIM *, int);
void ispisi(TIM *, int);

int main()
{
    int n;
    TIM *timovi = formiraj(&n);
    if(timovi!=NULL)
    {
        sortiraj(timovi, n);
        ispisi(timovi, n);
        free(timovi);
        timovi=NULL;
    }
    else
    {
        printf("Neusopjesna alokacija memorije.");
    }
    return 0;
}
void ucitaj(TIM *t)
{
    printf("Unesi naziv tima: ");
    scanf("%s", &(t->naziv));
    printf("Unesi broj postignutih golova tima %s: ",t->naziv);
    scanf("%d", &(t->brPostignutih));
    printf("Unesi broj primljenih golova tima %s: ",t->naziv);
    scanf("%d", &(t->brPrimljenih));
    printf("Unesi broj bodova tima %s: ",t->naziv);
    scanf("%d", &(t->bodovi));
}

TIM* formiraj(int *n)
{
    do
    {
        printf("Unesi broj timova: ");
        scanf("%d", n);
    }
    while(*n<1);
    TIM *timoviNiz = (TIM *)malloc(sizeof(TIM) **n);
    if(timoviNiz==NULL)
    {
        return NULL;
    }
    for(int i=0; i<*n; i++)
    {
        ucitaj(&timoviNiz[i]);
    }
    return timoviNiz;
}

void sortiraj(TIM *timovi, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(timovi[i].bodovi<timovi[j].bodovi)
            {
                zamijeni(&timovi[i], &timovi[j]);
            }
            else if(timovi[i].bodovi==timovi[j].bodovi)
            {
                int glr1 = timovi[i].brPostignutih-timovi[i].brPrimljenih;
                int glr2 = timovi[j].brPostignutih-timovi[j].brPrimljenih;
                if(glr1<glr2)
                {
                    zamijeni(&timovi[i], &timovi[j]);
                }
                else if(glr1==glr2)
                {
                    if(timovi[i].brPostignutih<timovi[j].brPostignutih)
                    {
                        zamijeni(&timovi[i], &timovi[j]);
                    }
                }
            }
        }
    }
}

void zamijeni(TIM *t1, TIM *t2)
{
    TIM temp = *t1;
    *t1=*t2;
    *t2=temp;
}

void ispisi(TIM *timovi, int n)
{
    printf("Sortirani timovi: \n");
    printf("RB. NAZIV------GPO-GPR-GR-BOD \n");
    for(int i=0; i<n; i++)
    {
        int glr = timovi[i].brPostignutih-timovi[i].brPrimljenih;
        printf("%d. %11s %3d %3d %2d %3d\n", i+1,timovi[i].naziv, timovi[i].brPostignutih, timovi[i].brPrimljenih, glr, timovi[i].bodovi);
    }
}
