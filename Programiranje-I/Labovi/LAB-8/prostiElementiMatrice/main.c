#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava kvadratnu matricu prirodnih brojeva, reda n (n < 20), a zatim pronalazi i
ispisuje sve elemente matrice koji su prosti brojevi.*/
int main()
{
    int n;
    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    }
    while(n<1 || n>=20);
    int m[n][n];
    printf("Unesi matricu: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int prost=1;
            for(int k=2;k<=m[i][j]/2;k++){
                if(m[i][j]%k==0){
                    prost=0;
                    break;
                }
            }
            if(prost){
                printf("%d ",m[i][j]);
            }
        }
    }
    return 0;
}
