#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
/**Napisati funkciju sa promjenljivim brojem
argumenata, koja redom prihvata vrijednosti x i n, te n
pokazivača na funkcije sa zaglavljem:
double f(double);
te izračunava i u istom redu ispisuje vrijednosti tih
funkcija za proslijeđenu vrijednost x.
Napisati program u programskom jeziku C koji
demonstrira rad te funkcije za funkcije cos(x), sin(x) i
exp(x) u intervalu [-1,1) sa korakom 0.01. Rezultat
izvršavanja programa treba da bude tabelarni ispis
vrijednosti tih funkcija, kao što je ilustrovano.*/


void izracunavanje(double x, int n, ...){
    va_list arg;
    double (*niz[n])(double);
    va_start(arg, n);
    for(int i=0;i<n;i++){
        niz[i]= va_arg(arg, double (*)(double));
    }
    va_end(arg);
    for(double i=x;i<1;i+=0.1){
        printf("%-5.2lf ", i);
        for(int j=0;j<n;j++){
            printf("%9.2lf ", niz[j](i));
        }
        printf("\n");
    }
}

int main()
{
    printf("  x %6s(x) %6s(x) %6s(x)\n===== ========= ========= =========\n", "sin", "cos", "exp");
    izracunavanje(-1,3,sin,cos,exp);
    return 0;
}
