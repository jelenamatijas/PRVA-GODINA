#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n, a zatim niz od n cijelih brojeva. Potom je potrebno obrnuti
redoslijed elemenata učitanog niza, pa ga ispisati.*/
int main()
{
    int n;
    do{
        printf("Unesi prirodan broj n: ");
        scanf("%d", &n);
    }while(n<1);
    int niz[n];
    printf("Unesi niz: \n");
    for(int i=0;i<n;i++){
        scanf("%d", &niz[i]);
    }
    for(int i=0;i<n/2;i++){
        int x=niz[i];
        niz[i]=niz[n-1-i];
        niz[n-1-i]=x;
    }
    printf("Obrnuti niz:\n");
    for(int i=0;i<n;i++){
        printf("%d ", niz[i]);
    }
    return 0;
}
