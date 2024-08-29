#include <stdio.h>
#include <stdlib.h>
void ucitaj(int [][10], int, int);
void ispisi(int [][10], int, int);
void pomnozi(int [][10], int [][10], int [][10], int, int, int, int);
#define MAX 10
int main()
{
    int an, am, bn, bm;
    int a[MAX][MAX],b[MAX][MAX];
    do
    {
        printf("Unesi an i am: ");
        scanf("%d%d", &an, &am);
    }
    while(an<1 || am<1 || an>10 || am>10);
    ucitaj(a, an, am);
    do
    {
        printf("Unesi bn i bm: ");
        scanf("%d%d", &bn, &bm);
    }
    while(bn<1 || bm<1 || bn>10 || bm>10);
    ucitaj(b, bn, bm);
    if(am==bn){
        int pr[an][bm];
        pomnozi(pr, a, b, an,am,bn,bm);
        ispisi(pr,an, bm);
    }else{
        printf("Nije moguce pomnoziti ove dvije matrice.");
    }
    return 0;
}
void pomnozi(int pr[][10], int a[][10], int b[][10], int an, int am, int bn, int bm){
    for(int i=0;i<am;i++){
        for(int j=0;j<bm;j++){
            pr[i][j]=0;
            for(int k=0;k<bn;k++){
                pr[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
void ucitaj(int mat[][10], int n, int m)
{
    printf("Unesi matricu a:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

void ispisi(int mat[][10], int n, int m)
{
    printf("Matrica a*b:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
