#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava kvadratnu matricu reda n (n < 20), a zatim ispisuje sumu elemenata glavne
dijagonale i sumu elemenata sporedne dijagonale matrice.
*/
int main()
{
    int n;
    do{
        printf("Unesi n: ");
        scanf("%d", &n);
    }while(n<1 || n>=20);
    int m[n][n];
    printf("Unesi matricu: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("Elementi glavne dijagonale: \n");
    for(int i=0;i<n;i++){
        printf("%d ", m[i][i]);
    }
    printf("\nElementi sporedne dijagonale: \n");
    for(int i=0;i<n;i++){
        printf("%d ", m[i][n-1-i]);
    }
    return 0;
}
