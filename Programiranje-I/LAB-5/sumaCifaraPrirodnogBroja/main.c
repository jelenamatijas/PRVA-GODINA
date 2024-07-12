#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum=0;
    do
    {
        printf("Unesi broj: ");
        scanf("%d", &n);
    }
    while(n<1);
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    printf("Suma cifara %d.",sum);
    return 0;
}
