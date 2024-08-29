#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji učitava prirodan broj b, a zatim ispisuje sumu cifara učitanog broja. Računanje
sume cifara treba da se vrši u rekurzivnoj funkciji čiji je prototip:
int suma_cifara(int b);
*/

int suma_cifara(int b);

int main()
{
    int b;
    printf("Unesi broj b: ");
    scanf("%d", &b);
    printf("Suma cifara broja b je: %d.\n", suma_cifara(b));
    return 0;
}

int suma_cifara(int b){
    if(!b)return 0;
    return b%10 + suma_cifara(b/10);
}
