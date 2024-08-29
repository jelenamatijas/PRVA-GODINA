#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n (n ≤ 30), a zatim ispisuje prvih n redova sljedeće piramide
cifara:
          1
         121
        12321
       1234321
          ⋮
 1234567890987654321
123456789010987654321*/
int main()
{
    int n;
    do
    {
        printf("Unesi prirodan broj:");
        scanf("%d", &n);
    }
    while(n<1 || n>30);
    for(int red=1; red<=n; red++)
    {
        for(int pr=0; pr<n-red; pr++)
        {
            printf(" ");
        }
        for(int rast=1; rast<=red; rast++)
        {
            printf("%d", rast%10);
        }
        for(int opd=red-1; opd>=1; opd--)
        {
            printf("%d", opd%10);
        }
        printf("\n");
    }
    printf("\n\n\n\n\n");
    for(int red=1; red<n; red++)
    {
        for(int rast=1; rast<=red; rast++)
        {
            printf("%d", rast%10);

        }
        printf("\n");
    }
    for(int red=n; red>=1; red--)
    {
        for(int rast=1; rast<=red; rast++)
        {
            printf("%d", rast%10);

        }
        printf("\n");
    }
    printf("\n\n\n\n\n");
    for(int red=1; red<=n; red++)
    {
        for(int pr=1; pr<=n-red; pr++)
        {
            printf(" ");
        }
        for(int rast=1; rast<=red; rast++)
        {
            printf("%d", rast%10);
        }
        printf("\n");
    }
    for(int red=n; red>0; red--)
    {
        for(int pr=n-red; pr>=1; pr--)
        {
            printf(" ");
        }
        for(int opd=red; opd>=1; opd--)
        {
            printf("%d", opd%10);
        }
        printf("\n");
    }
    printf("\n\n\n\n\n");
    return 0;
}
