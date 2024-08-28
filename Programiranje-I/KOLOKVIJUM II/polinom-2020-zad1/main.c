#include <stdio.h>
#include <stdlib.h>
/*Neka je definisan tip:
typedef struct polinom {
double koef[100]; // vrednost koeficijenata
} POLINOM;
kojim se reprezentuje polinom P(x) stepena ne
većeg od 99. Pri tome, prvi element niza koef
predstavlja vrednost slobodnog člana polinoma,
drugi element niza predstavlja vrednost
koeficijenta uz član x, treći element niza
predstavlja vrednost koeficijenta uz član x2 itd.
Napisati funkciju (bez korištenja drugih funkcija)
koja računa vrednost xn (n≥0), a čiji je prototip:
double stepen(double x, int n);
Napisati funkciju (pri čemu je dozvoljeno korištenje
samo funkcije stepen) koja određuje vrednost
polinoma P(x) za zadato x. Prototip funkcije je:
double px(POLINOM p, double x);
Napisati glavnu funkciju u kojoj treba definisati
polinom P(x)=5x3-2x2+4, a zatim (korištenjem
funkcije px) odrediti i ispisati vrednost P(3.5).*/

typedef struct polinom
{
    double koef[100]; // vrednost koeficijenata
} POLINOM;

double stepen(double x, int n);
double px(POLINOM p, double x);

int main()
{
    POLINOM p;
    double koef[100] = {4,0,-2,5};
    for(int i=0;i<100;i++){
        p.koef[i]=koef[i];
    }
    printf("P(3.5) = %lf.", px(p,3.5));
    return 0;
}

double px(POLINOM p, double x){
    double vrd=p.koef[0];
    for(int i=1;i<100;i++){
        vrd+=p.koef[i]*stepen(x, i);
    }
    return vrd;
}

double stepen(double x, int n){
    double st=x;
    for(int i=1;i<n;i++){
        st*=x;
    }
    return st;
}
