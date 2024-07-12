#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava prirodan broj n, a zatim ispisuje najveći broj koji je jednak sumi faktorijela
svojih cifara, a koji je manji od prirodnog broja n. Na primjer, broj 145 je jednak sumi faktorijela svojih cifara
(1! + 4! + 5! = 1 + 24 + 120 = 145).*/
int main()
{
    int n, sum=0;
    do
    {
        printf("Unesi prirodan broj:");
        scanf("%d", &n);
    }
    while(n<1);
    while(--n)
    {
        int x=n;
        while(x)
        {
            int f=1;
            for(int i=2; i<=x%10; i++)
            {
                f*=i;
            }
            x/=10;
            sum+=f;
            f=1;
        }
        if(sum==n)
        {
            printf("Najveci broj ciji zbir faktorijala cifara mu je jednak je: %d.", n);
            break;
        }
        sum=0;
    }
    return 0;
}
