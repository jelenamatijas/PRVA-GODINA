#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji učitava (neoznačen) broj n, a zatim ispisuje sumu cifara broja n.
 Računanje sume cifara treba da se vrši u rekurzivnoj funkciji suma_cifara.*/

 unsigned suma_cifara(unsigned n){
    if(n==0){
        return 0;
    }
    return (n%10)+ suma_cifara(n/10);
 }
int main()
{
    unsigned n;
    printf("Unesi broj: ");
    scanf("%u", &n);
    printf("Suma cifara: %u", suma_cifara(n));
    return 0;
}
