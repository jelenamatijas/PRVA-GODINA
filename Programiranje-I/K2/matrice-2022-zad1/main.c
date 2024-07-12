#include <stdio.h>
#include <stdlib.h>
/*Napisati funkciju koja učitava i vraća
dimenzije i elemente (dinamičke) matrice celih
brojeva. Broj redova i broj kolona matrice treba
vratiti preko parametara n i m, respektivno.
Prototip funkcije je:
int** ucitaj(int *n, int *m);
Napisati funkciju koja sabira dve matrice (m1 i
m2) istih dimenzija (n x m). Rezultat treba da
bude nova (dinamička) matrica. Prototip funkcije
je:
int** saberi(int **m1, int **m2, int n, int m);
Napisati funkciju koja transponuje datu matricu
mat dimenzija n x m. Rezultat treba da bude nova
(dinamička) matrica. Prototip funkcije je:
int** transponuj(int **mat, int n, int m);*/

int** ucitaj(int *n, int *m);
int** saberi(int **m1, int **m2, int n, int m);
int** transponuj(int **mat, int n, int m);
void ispisi(int**mat, int n, int m)
{
    printf("Matrica: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void oslobodi(int **mat, int n)
{
    for(int i=0; i<n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

int main()
{
    int **m1, **m2, n,m,nn,mm, **sum, **trn;
    m1=ucitaj(&n,&m);
    //ispisi(m1, n,m);
    m2=ucitaj(&nn,&mm);
    if(m1!=NULL && m2!=NULL)
    {
        if(n==nn && m==mm)
        {
            sum=saberi(m1,m2,n,m);
            ispisi(sum, n, m);
            oslobodi(sum, n);
        }
        else
        {
            printf("Nije moguce sabrati ove matrice.\n");
        }
        trn=transponuj(m1,n,m);
        ispisi(trn, m, n);
        oslobodi(trn, n);
    }
    oslobodi(m1, n);
    oslobodi(m2, nn);
    return 0;
}
int** ucitaj(int *n, int *m)
{
    printf("Unesi dimenzije matrice: ");
    scanf("%d%d", n,m);
    printf("Unesi matricu:\n");
    int **mat = (int **)malloc(sizeof(int*)**n);
    if(mat==NULL)
    {
        return NULL;
    }
    for(int i=0; i<*n; i++)
    {
        mat[i]=(int *)malloc(sizeof(int)**m);
        if(mat[i]==NULL)
        {
            return NULL;
        }
        for(int j=0; j<*m; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    return mat;
}

int** saberi(int **m1, int **m2, int n, int m)
{
    int **mat = (int **)malloc(sizeof(int*)*n);
    if(mat==NULL)
    {
        return NULL;
    }
    for(int i=0; i<n; i++)
    {
        mat[i]=(int *)malloc(sizeof(int)*m);
        if(mat[i]==NULL)
        {
            return NULL;
        }
        for(int j=0; j<m; j++)
        {
            mat[i][j]=m1[i][j]+m2[i][j];
        }
    }
    return mat;
}

int** transponuj(int **mat, int n, int m)
{
    int **tr = (int **)malloc(sizeof(int*)*m);
    if(tr==NULL)
    {
        return NULL;
    }
    for(int i=0; i<m; i++)
    {
        tr[i]=(int *)malloc(sizeof(int)*n);
        if(tr[i]==NULL)
        {
            return NULL;
        }
        for(int j=0; j<n; j++)
        {
            tr[i][j]=mat[j][i];
        }
    }
    return tr;
}
