#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n te n cijelih brojeva, a zatim ispisuje koliko među njima ima pozitivnih.*/
int main()
{
    int n, suma=0;
    printf("Unesi n: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);
        suma += x>0 ? 1 : 0;
    }
    printf("Broj unesenih pozitivnih brojeva je %d.", suma);
    return 0;
}
