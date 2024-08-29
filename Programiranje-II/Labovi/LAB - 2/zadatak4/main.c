#include <stdio.h>
#include <stdlib.h>
#define MAX 20
/**Napisati program koji učitava prirodan broj n, a zatim ispisuje n-ti član (fn) sljedećeg niza:
f1 = 1, f2 = 2, f3 = 3 fk = fk-1 + fk-2 + fk-3, k ≥ 4.
n-ti član datog niza treba da se računa u rekurzivnoj funkciji čiji je prototip:
int clan(int n);*/

int clan(int n);

int main()
{
    int n;
    do
    {
        printf("Unesi broj n: ");
        scanf("%d", &n);
    }
    while(n<4);
    printf("f(n) = %d.", clan(n));
    return 0;
}

int clan(int n)
{
    static int f[MAX]= {1,2,3};
    if(f[n-1]!=0)return f[n-1];
    return f[n-1] = clan(n-1)+clan(n-2)+clan(n-3);
}
