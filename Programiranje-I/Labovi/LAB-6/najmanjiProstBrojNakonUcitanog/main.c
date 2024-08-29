#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n, a zatim ispisuje najmanji prost broj veći od učitanog broja.*/
int main()
{
    int n, min;
    do
    {
        printf("Unesi prirodan broj:");
        scanf("%d", &n);
    }
    while(n<1);
    while(++n)
    {
        int i;
        for(i=2; i<n/2; i++)
        {
            if(n%i==0)
            {
                i=0;
                break;
            }
        }
        if(i!=0)
        {
            printf("Prvi veci prost prirodan broj je %d.", n);
            break;
        }
    }

    return 0;
}
