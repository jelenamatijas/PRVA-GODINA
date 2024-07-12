#include <stdio.h>
#include <stdlib.h>

/**Neka je dat tip IMAGE i funkcija cmpimg
koja poredi dva podatka tipa IMAGE. Funkcija cmpimg
prihvata adrese dva podatka tipa IMAGE, a vraća
vrijednost -1 (prvi podatak manji od drugog), 0 (podaci
su jednaki) ili 1 (prvi podatak veći od drugog). Prototip
funkcije je:
int cmpimg(const IMAGE *podatak1, const IMAGE
*podatak2);
Napisati funkciju (korištenjem funkcije cmpimg) koja
vrši indirektno (originalni niz ne smije biti modifikovan)
sortiranje niza od n podataka tipa IMAGE. Funkcija
treba da vrati dinamički niz adresa elemenata
originalnog niza sortiranih u rastućem redoslijedu
prema vrijednostima elemenata originalnog niza.
Sortiranje treba izvršiti bubble-sort algoritmom.
Prototip funkcije je:
IMAGE** sortimg(IMAGE *niz, int n);*/

typedef struct image
{
    int a;
} IMAGE;

int cmpimg(const IMAGE *podatak1, const IMAGE *podatak2)
{
    if(podatak1->a>podatak2->a) return 1;
    if(podatak1->a<podatak2->a) return -1;
    return 0;
}

IMAGE** sortimg(IMAGE *niz, int n)
{
    IMAGE **sort=(IMAGE**)calloc(sizeof(IMAGE*), n);
    for(int i=0; i<n; i++)
    {
        sort[i] = (IMAGE*)calloc(sizeof(IMAGE), 1);
        sort[i] = &niz[i];
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(cmpimg(sort[j], sort[j+1])==1)
            {
                IMAGE *pom = sort[j];
                sort[j]=sort[j+1];
                sort[j+1]=pom;
            }
        }
    }
    return sort;
}

int main()
{
    IMAGE niz[5] ={1,-3,2,6,0};
    IMAGE **sortiran = sortimg(niz, 5);
    for(int i=0; i<5; i++)
    {
        printf("%d ", sortiran[i]->a);
    }
    for(int i=0; i<5; i++)
    {
        free(sortiran[i]);
    }
    free(sortiran);
    return 0;
}
