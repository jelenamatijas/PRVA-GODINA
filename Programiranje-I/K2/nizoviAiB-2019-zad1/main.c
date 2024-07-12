#include <stdio.h>
#include <stdlib.h>
/*Napisati funkciju koja računa i vraća
sumu cifara broja |n|, a čiji je prototip:
int suma(int n);
Napisati funkciju (korištenjem funkcije suma) koja
na osnovu niza celih brojeva a, formira niz celih
brojeva b, pri čemu je broj bi jednak sumi cifra
broja ai. Parametar n predstavlja broj elemenata
niza a. Prototip funkcije je:
void formiraj(int a[], int b[], int n);
Napisati glavnu funkciju u kojoj treba ilustrovati
korištenje funkcije formiraj na nizu od pet
proizvoljnih trocifrenih celih brojeva.*/

#define N 5
int suma(int n);
void formiraj(int a[], int b[], int n);

int main()
{
    int a[N] = {111,222,333,444,555};
    int b[N];
    formiraj(&a, &b, N);
    for(int i=0;i<N;i++){
        printf("%d ", b[i]);
    }
    return 0;
}

int suma(int n){
    int sum=0;
    if(n<0){
        n*=-1;
    }
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void formiraj(int a[], int b[], int n){
    for(int i=0;i<n;i++){
        b[i]=suma(a[i]);
    }
}
