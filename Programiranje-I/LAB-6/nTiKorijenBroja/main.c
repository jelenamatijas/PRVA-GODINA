#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Napisati program koji učitava vrijednosti x i n (n > 0), a zatim izračunava n-ti korijen broja x s preciznošću
0.00001 i ispisuje izračunatu vrijednost. n-ti korijen broja x ∈ R može da se izračuna korištenjem Njutnove
iterativne formule*/

#define EPS 1e-5
int main()
{
    double n, x, Xs, Xn, pom;
    do
    {
        printf("Unesi broj x i korijen n:");
        scanf("%lf%lf",&x, &n);
    }
    while(n<1 || x<0);

    Xn = (x+1)/n;
    do
    {
        Xs=Xn;
        double s=1;
        for(int i=0; i<n-1; i++)
        {
            s*=Xs;
        }
        Xn = ((n-1)*Xs + x/s)/n;
    }
    while(fabs(Xs-Xn)>EPS);
    printf("Korijen je: %lf.", Xn);

    return 0;
}
