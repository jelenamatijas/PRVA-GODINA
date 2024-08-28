#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**Neka su definisani tipovi:
typedef struct duz {
double duzina;
} DUZ;
typedef struct trougao {
DUZ a, b, c;
} TROUGAO;
kojima se reprezentuju duž i trougao, respektivno.
Napisati funkciju koja proverava i vraća
informaciju o tome da li se od date tri duži može
formirati trougao, a čiji je prototip:
int validan(DUZ a, DUZ b, DUZ c);
Napisati funkciju koja sa standardnog ulaza učitava
i vraća (validan) trougao, a čiji je prototip:
TROUGAO ucitaj();
Napisati funkciju koja proverava i vraća
informaciju o tome da li su dva trougla podudarna,
a čiji je prototip:
int podudarni(TROUGAO *t1, TROUGAO *t2);
Napisati funkciju koja računa i vraća površinu
trougla, a čiji je prototip:
double povrsina(TROUGAO *t);
Ako su a, b i c dužine stranica trougla, tada
površina trougla može da se izračuna preko
poluobima (s=(a+b+c)/2):*/

typedef struct duz
{
    double duzina;
} DUZ;
typedef struct trougao
{
    DUZ a, b, c;
} TROUGAO;

int validan(DUZ a, DUZ b, DUZ c);
TROUGAO ucitaj();
int podudarni(TROUGAO *t1, TROUGAO *t2);
double povrsina(TROUGAO *t);

int main()
{
    TROUGAO t1=ucitaj();
    TROUGAO t2=ucitaj();
    double p1 = povrsina(&t1);
    printf("Povrsina prvog trougla je %.2lf.\n", p1);
    double p2 = povrsina(&t2);
    printf("Povrsina prvog trougla je %.2lf.\n", p2);
    printf("Trouglovi %s podudarni.",(podudarni(&t1, &t2))?"jesu":"nisu");
    return 0;
}

int validan(DUZ a, DUZ b, DUZ c){
    if(a.duzina+b.duzina<=c.duzina || a.duzina+c.duzina<=b.duzina || b.duzina+c.duzina<=a.duzina){
        return 0;
    }
    return 1;
}

TROUGAO ucitaj(){
    DUZ a,b,c;
    do{
        printf("Unesi stranice trougla: ");
        scanf("%lf%lf%lf", &a.duzina,&b.duzina,&c.duzina);
    }while(!validan(a,b,c));
    TROUGAO t = {a,b,c};
    return t;
}

int podudarni(TROUGAO *t1, TROUGAO *t2){
    double a1=t1->a.duzina, b1=t1->b.duzina, c1=t1->c.duzina;
    double a2=t2->a.duzina, b2=t2->b.duzina, c2=t2->c.duzina;
    if(a1==a2 && b1==b2 && c1==c2){
        return 1;
    }
    return 0;
}

double povrsina(TROUGAO *t){
    double s = (t->a.duzina + t->b.duzina + t->c.duzina)/2;
    return sqrt(s*(s-t->a.duzina)*(s-t->b.duzina)*(s-t->c.duzina));
}
