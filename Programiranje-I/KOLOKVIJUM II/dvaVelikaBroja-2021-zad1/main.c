#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju koja sabira dva
velika prirodna broja koja mogu da imaju MAXCIF
cifara. Veliki broj se reprezentuje kao niz od
MAXCIF cifara (uključujući vodeće nule), pri čemu
prvi element niza predstavlja najlakšu cifru, a
poslednji element najtežu cifru broja. Parametri b1
i b2 predstavljaju sabirke, dok rezultat treba vratiti
preko parametra r. Prototip funkcije je:
void saberi(int *b1, int *b2, int *r);
Napisati funkciju koja poredi dva velika prirodna
broja, a vraća vrednost -1 ako je b1<b2, 0 ako je
b1=b2 te 1 ako je b1>b2. Prototip funkcije je:
int uporedi(int *b1, int *b2);
Napisati funkciju koja, bez vodećih nula, na
standardni izlaz ispisuje dati veliki prirodni broj.
Prototip funkcije je:
void pisi(int *b);*/

#define MAXCIF 10
void saberi(int *b1, int *b2, int *r);
int uporedi(int *b1, int *b2);
void pisi(int *b);

int main()
{
    int br1[MAXCIF] = {1,2,8};
    int br2[MAXCIF] = {1,2,8};
    int r[MAXCIF];
    saberi(br1, br2, &r);
    int upr = uporedi(br1,br2);
    if(upr==1){
        printf("Prvi broj je veci od drugog.\n");
    }else if(upr == -1){
        printf("Drugi broj je veci od prvog.\n");
    }else{
        printf("Brojevi su jednaki.\n");
    }
    printf("Suma = ");
    pisi(r);
    return 0;
}
void saberi(int *b1, int *b2, int *r)
{
    for(int i=0,prenos=0; i<MAXCIF; i++)
    {
        int x=prenos+b1[i]+b2[i];
        r[i]=x%10;
        x/=10;
        prenos=x;
    }
}

int uporedi(int *b1, int *b2)
{
    int i;
    for(i=MAXCIF-1; b1[i]==0 && b2[i]==0; i--);
    for(; i>=0; i--)
    {
        if(b1[i]>b2[i]){
            return 1;
        }
        if(b1[i]<b2[i]){
            return -1;
        }
    }
    return 0;
}

void pisi(int *b)
{
    int i;
    for(i=MAXCIF-1; b[i]==0; i--);
    for(; i>=0; i--)
    {
        printf("%d", b[i]);
    }
}
