#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji učitava prirodan broj n te dva vektora dimenzije n, a zatim ispisuje zbir učitanih
vektora. Računanje zbira dva vektora treba da se vrši u rekurzivnoj funkciji čiji je prototip:
void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n);*/

void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n);

int main()
{
    int n;
    printf("Unesi broj elemenata vektora: ");
    scanf("%d", &n);
    double v1[n],v2[n], rez[n];
    printf("Unesi elemente prvog vektora:\n");
    for(int i=0; i<n; i++)
        scanf("%lf", &v1[i]);
    for(int i=0; i<n; i++)
        scanf("%lf", &v2[i]);
    saberi(v1, v2, rez, n);
    return 0;
}

void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n)
{
    if(n==0)
    {
        printf("Zbir ova dva vektora je:\n");
    }
    else
    {
        saberi(vektor_a, vektor_b, vektor_rez, n-1);
        vektor_rez[n-1] = vektor_a[n-1]+ vektor_b[n-1];
        printf("%.2lf ", vektor_rez[n-1]);
    }

}
