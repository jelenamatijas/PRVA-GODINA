#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju koja na
osnovu niza niz od n celih brojeva formira i
vraća (dinamički) niz celih brojeva koji se
sastoji samo od prirodnih brojeva (iz zadatog
niza) koji sadrže cifru c (proveru da li
prirodan broj sadrži cifru c izdvojiti u zasebnu
funkciju). Broj elemenata u rezultujućem nizu
vratiti preko parametra m. Ukoliko u zadatom
nizu nema prirodnih brojeva koji sadrže cifru
c, funkcija treba da vrati NULL. Prototip
funkcije je:
long* cifra(long *niz, int n, int c, int *m);
Napisati funkciju (koristeći funkciju cifra) koja
u zadatoj matrici mat dimenzija nxm
pronalazi vrstu koja sadrži najveći broj
prirodnih brojeva koji sadrže cifru c, ispisuje
te prirodne brojeve i vraća indeks pronađene
vrste. Ukoliko više vrsta sadrži isti broj
prirodnih brojeva koji sadrže cifru c vratiti
indeks prve takve vrste. Ukoliko matrica ne
sadrži nijedan broj koji ispunjava uslove
vratiti -1. Prototip funkcije je:
int cfr(long mat[][10], int n, int m, int c);
Napisati glavnu funkciju u kojoj treba
definisati i inicijalizovati (proizvoljnim
brojevima) matricu dimenzija 3x3, a zatim
ilustrovati korištenje funkcije cfr*/

long* cifra(long *niz, int n, int c, int *m)
{
    int br=0;
    for(int i=0; i<n; i++)
    {
        if(niz[i]>0)
        {
            long x=niz[i];
            while(x)
            {
                if(x%10==c)
                {
                    br++;
                    break;
                }
                x/=10;
            }
        }
    }
    if(br!=0)
    {
        *m=br;
        long *novi = (long*)calloc(sizeof(long), n);
        if(novi==NULL)
            return NULL;
        for(int i=0; i<n; i++)
        {
            novi[i]=niz[i];
        }

        return novi;
    }
    return NULL;
}

int cfr(long mat[][10], int n, int m, int c)
{
    int max=0, trenMax, index=-1;
    long *p, *pMax=NULL;
    for(int i=0; i<n; i++)
    {
        p=cifra(mat[i], m, c, &trenMax);
        if(p)
        {
            if(trenMax>max)
            {
                pMax = p;
                max = trenMax;
                index=i;
            }
            else
            {
                free(p);
            }
        }
    }
    if(index>=0)
    {
        for(int i=0; i<m; i++)
        {
            printf("%ld ", pMax[i]);
        }
        free(pMax);
    }
    return index;
}

int main()
{
    long m[3][10]= {};
    m[0][0]=1;
    m[0][1]=-123;
    m[0][2]=23;
    m[1][0]=413;
    m[1][1]=-502;
    m[1][2]=30;
    m[2][0]=12;
    m[2][1]=-31;
    m[2][2]=401;
    int ind=cfr(m,3,3,1);
    if(ind<0)
    {
        printf("Ne postoji takva vrsta u matrici.");
    }
    else
    {
        printf("To je vrsta sa indeksom %d.", ind);
    }
    return 0;
}
