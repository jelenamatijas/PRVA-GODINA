#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava dva prirodna broja, a zatim računa i ispisuje NZS ta dva broja.*/
int main()
{
    int a, b, nzs;
    printf("Unesi dva broja: ");
    scanf("%d%d", &a, &b);
    nzs = a>b ? a : b;
    while(nzs != a*b){
        if(nzs %a==0 && nzs%b==0){
            break;
        }
        nzs++;
    }
    printf("Najmanji zajednicki sadrzilac brojeva %d i %d je %d.", a, b, nzs);
    return 0;
}
