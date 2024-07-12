#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji učitava (neoznačen) broj n, a zatim ispisuje cifre broja n počevši od najteže.
 Ispis cifara treba da se vrši u rekurzivnoj funkciji cifra.*/

void ispis_cifara(unsigned n)
{
    if(n/10 == 0)
        printf("%d ", n);
    else{
        ispis_cifara(n/10);
        printf("%d ", n%10);
    }

}
int main()
{
    unsigned n;
    printf("Unesi broj: ");
    scanf("%u", &n);
    ispis_cifara(n);
    return 0;
}
