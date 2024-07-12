#include <stdio.h>
#include <stdlib.h>
int prost(int );
int main()
{
    int n;
    do{
        printf("Unesi n: ");
        scanf("%d", &n);
    }while(n<1);
    int niz[n];
    printf("Unesi brojeve:\n");
    for(int i=0;i<n;i++){
        scanf("%d", &niz[i]);
    }
    printf("Prosti brojevi:\n");
    for(int i=0;i<n;i++){
        if(prost(niz[i])){
            printf("%d ", niz[i]);
        }
    }
    return 0;
}
int prost(int x){
    for(int i=2;i<=x/2;i++){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}
