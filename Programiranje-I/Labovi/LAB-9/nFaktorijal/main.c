#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n (n ≤ 100), a zatim ispisuje n!.*/

#define MAXC 1000
int main()
{
    int n,index;
    int niz[MAXC]={1};
    do{
        printf("Unesi n: ");
        scanf("%d", &n);
    }while(n<1 || n>100);
    for(int i=2;i<=n;i++){
        for(int j=0, prenos=0;j<MAXC;j++){
            int x = niz[j]*i+prenos;
            niz[j]=x%10;
            prenos = x/10;
        }
    }
    for(index=MAXC-1; niz[index]==0;index--);
    printf("Faktorijal %d = ", n);
    for(;index>=0;index--){
        printf("%d", niz[index]);
    }
    return 0;
}
