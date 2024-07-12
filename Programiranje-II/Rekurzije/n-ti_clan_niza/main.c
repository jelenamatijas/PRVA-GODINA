#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji učitava prirodan broj n, a zatim ispisuje n-ti član niza:
f1 = 1, f2 = 2, f3 = 3         fn+3 = fn+2 + fn+1 + fn,  n > 0
n-ti član datog niza treba da se računa u rekurzivnoj funkciji clan.
*/

int nti_clan(int n)
{
    static int niz[100] = {1,2,3};
    if(n<0)
    {
        return 0;
    }
    else if(niz[n] != 0)
    {
        return niz[n];
    }
    else
    {
        return niz[n] = nti_clan(n-1) + nti_clan(n-2) + nti_clan(n-3);
    }
}
int main()
{
    int n;
    do
    {
        printf("Unesi broj clana: ");
        scanf("%d", &n);
    }
    while(n<=0);
    printf("%d. clan niza je: %d.\n", n,nti_clan(n-1));
    return 0;
}
