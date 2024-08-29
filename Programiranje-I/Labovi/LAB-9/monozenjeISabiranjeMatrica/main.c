#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava dvije matrice realnih brojeva, a zatim ispisuje njihov zbir (ako matrice mogu da
se saberu) i proizvod (ako matrice mogu da se pomnože). Učitavanje jedne matrice podrazumijeva učitavanje
njenih dimenzija nxm (n ≤ 10, m ≤ 10) i elemenata. Ako matrice ne mogu da se saberu, potrebno je ispisati
odgovarajuću poruku. Takođe, ako matrice ne mogu da se pomnože, potrebno je ispisati odgovarajuću poruku.*/
int main()
{
    int an,am,bn,bm;
    do
    {
        printf("Unesi dimenzije matrice A: ");
        scanf("%d%d", &an,&am);
    }
    while(an<1||am<1||an>10||am>10);
    do
    {
        printf("Unesi dimenzije matrice B: ");
        scanf("%d%d", &bn,&bm);
    }
    while(bn<1||bm<1||bn>10||bm>10);

    int a[an][am],b[bn][bm], zbir[an][am];
    int proizvod[an][bm];
    printf("Unesi matricu A:\n");
    for(int i=0; i<an; i++)
    {
        for(int j=0; j<am; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Unesi matricu B:\n");
    for(int i=0; i<bn; i++)
    {
        for(int j=0; j<bm; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    if(an==bn && am==bm)
    {
        for(int i=0; i<an; i++)
        {
            for(int i=0; i<an; i++)
            {
                for(int j=0; j<am; j++)
                {
                    zbir[i][j]=a[i][j]+b[i][j];
                }
            }
        }
        printf("A+B=\n");
        for(int i=0; i<an; i++)
        {
            for(int j=0; j<am; j++)
            {
                printf("%d ", zbir[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Nije moguce sabrati ove dvije matrice.\n");
    }
    printf("\n-----------------------------------\n");
    if(am==bn)
    {
        for (int i = 0; i < an; i++)
        {
            for (int j = 0; j < bm; j++)
            {
                proizvod[i][j]=0;
                for (int k = 0; k < am; k++)
                {
                    proizvod[i][j]+=a[i][k]*b[k][j];
                    //printf("%d ", proizvod[i][j]);
                }
                //printf("\n");
            }
        }

        printf("A*B=\n");
        for(int i=0; i<an; i++)
        {
            for(int j=0; j<bm; j++)
            {
                printf("%d ", proizvod[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Nije moguce pomnoziti ove matrice.");
    }

    return 0;
}
