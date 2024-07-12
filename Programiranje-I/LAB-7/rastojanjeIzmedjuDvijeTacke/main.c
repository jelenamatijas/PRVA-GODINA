#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Napisati program koji učitava prirodan broj n koji predstavlja dimenzionalnost hiperprostora, a zatim učitava
dvije tačke iz tog prostora (tačka n-dimenzionog prostora se može predstaviti vektorom od n elemenata).
Primjenom Pitagorine teoreme koja važi bez obzira na dimenzionalnost prostora, odrediti i ispisati Euklidsko
rastojanje između učitanih tačaka.*/
int main()
{
    int n;
    double sum=0.0;
    do{
        printf("Unesi prirodan broj n: ");
        scanf("%d", &n);
    }while(n<1);
    int a[n], b[n];
    printf("Unesi prvu tacku: \n");
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Unesi drugu tacku: \n");
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
        sum+=pow(b[i]-a[i], 2);
    }
    double rast=sqrt(sum);
    printf("Rastojanje izmedju tacaka je %lf.", rast);
    return 0;
}
