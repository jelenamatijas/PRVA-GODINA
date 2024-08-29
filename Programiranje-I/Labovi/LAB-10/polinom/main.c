#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct polinom
{
    int k;
    int niz[MAX];
} POLINOM;

POLINOM citaj();
POLINOM saberi(POLINOM, POLINOM);
POLINOM pomnozi(POLINOM, POLINOM);
void ispisi(POLINOM);

int main()
{
    POLINOM p1,p2;
    p1=citaj();
    p2=citaj();
    printf("Zbir:\n");
    ispisi(saberi(p1,p2));
    printf("Proizvod:\n");
    ispisi(pomnozi(p1,p2));
    return 0;
}
POLINOM pomnozi(POLINOM p1, POLINOM p2)
{
    POLINOM pr;
    pr.k=p1.k+p2.k;
    for (int i=0; i<=pr.k; i++ )
    {
       pr.niz[i]=0;
    }
    for (int i=0; i<=p1.k; i++ )
    {
        for (int j=0; j<=p2.k; j++ )
        {
            pr.niz[i+j] += p1.niz[i] * p2.niz[j];
        }
    }
    return pr;
}

POLINOM saberi(POLINOM p1, POLINOM p2)
{
    if(p1.k<p2.k)
    {
        for(int i=0; i<=p1.k; i++)
        {
            p2.niz[i]+=p1.niz[i];
        }
        return p2;
    }
    else
    {
        for(int i=0; i<=p2.k; i++)
        {
            p1.niz[i]+=p2.niz[i];
        }
        return p1;
    }
}
POLINOM citaj()
{
    int k;
    POLINOM p;
    do
    {
        printf("Unesi k: ");
        scanf("%d", &k);
    }
    while(k<1 || k>100);
    printf("Unesi polinom:\n");
    p.k=k;
    for(int i=0; i<=k; i++)
    {
        printf("k[%d]=", i);
        scanf("%d",&p.niz[i]);
    }
    return p;
}

void ispisi(POLINOM p)
{
    for(int i=0; i<=p.k; i++)
    {
        printf("%c%dx^%d",(p.niz[i]<0)?' ':' +', p.niz[i], i);
    }
    printf("\n");
}
