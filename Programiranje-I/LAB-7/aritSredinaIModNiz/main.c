#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n te niz dužine n, a zatim pronalazi i ispisuje aritmetičku sredinu
te element najbliži aritmetičkoj sredini. Nakon toga, sortirati niz na takav način da prvi element najbliži
aritmetičkoj sredini zadrži svoju poziciju, a da su elementi prije njega sortirani u rastućem, a poslije njega u
opadajućem poretku.
Primjer:
n=12
Elementi niza: 1 6 4 7 8 3 5 10 4 6 8 2
==================================================
Aritmeticka sredina je 5.33.
Najblizi element je 5.
Modifikovani niz: 1 3 4 6 7 8 5 10 8 6 4 2*/
int main()
{
    int n,sum=0, index=0;
    do
    {
        printf("Unesi prirodan broj n: ");
        scanf("%d", &n);
    }
    while(n<1);
    int niz[n], najblizi;
    printf("Unesi niz: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &niz[i]);
        sum+=niz[i];
    }
    float artSr = (float)sum/n;
    printf("Aritmeticka sredina je %.2f.", artSr);
    najblizi=niz[0];
    for(int i=1; i<n; i++)
    {
        float raz1 = artSr-najblizi;
        float raz2 = artSr-niz[i];
        raz1 = raz1<0?raz1*(-1):raz1;
        raz2 = raz2<0?raz2*(-1):raz2;
        if(raz2<raz1)
        {
            najblizi=niz[i];
            index=i;
        }
    }
    printf("Najblizi element je %d.\n", najblizi);
    for(int i=0; i<index-1; i++)
    {
        for(int j=i+1; j<index; j++)
        {
            if(niz[i]>niz[j])
            {
                int x=niz[i];
                niz[i]=niz[j];
                niz[j]=x;
            }
        }
    }
    for(int i=index+1; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(niz[i]<niz[j])
            {
                int x=niz[i];
                niz[i]=niz[j];
                niz[j]=x;
            }

        }
    }
    printf("Sortiran niz: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", niz[i]);
    }
    return 0;
}
