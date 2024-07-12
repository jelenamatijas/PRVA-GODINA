#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n te n realnih brojeva, a zatim ispisuje najmanjeg.*/
int main()
{
    int n;
    float min, number;
    printf("Unesi n: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Unesi brojeve: ");
        scanf("%f", &number);
        if(i==0 || number<min)
        {
            min=number;
        }
    }
    printf("Minimum unesenih brojeva je %f.", min);
    return 0;
}
