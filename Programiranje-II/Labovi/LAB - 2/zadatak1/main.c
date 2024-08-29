#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji učitava prirodan broj n te niz od n cijelih brojeva, a zatim ispisuje sumu brojeva
učitanog niza. Elementi niza treba da se sumiraju u rekurzivnoj funkciji čiji je prototip:
int suma(int *niz, int n);
*/

int suma(int *niz, int n);

int main()
{
    int n;
    printf("Unesi broj elemenata niza: ");
    scanf("%d", &n);
    int niz[n];
    printf("Unesi elemente niza:\n");
    for(int i=0;i<n;i++)
        scanf("%d", &niz[i]);
    printf("Suma elemenata niza: %d.\n", suma(niz, n));
    return 0;
}

int suma(int *niz, int n){
    if(n==0)return 0;
    return niz[n-1]+suma(niz, n-1);
}
