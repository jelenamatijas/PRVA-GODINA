#include <stdio.h>
#include <stdlib.h>
/*Napisati program koji učitava dva prirodna broja, a zatim provjerava da li oni predstavljaju par prijateljskih
brojeva. Za dva broja kažemo da su prijateljski ako je prvi jednak sumi djelilaca drugog, a drugi jednak sumi
djelilaca prvog broja.*/
int main()
{
    int a, b, sumA=0, sumB=0;
    printf("Unesi dva broja: ");
    scanf("%d%d", &a, &b);
    for(int i=1; i<=a/2; i++)
    {
        sumA+= a%i==0 ? i : 0;
    }
    for(int i=1; i<=b/2; i++)
    {
        sumB+= b%i==0 ? i : 0;
    }
    printf("Broj %d i broj %d %s dva prijateljska broja.",a, b, sumA == b && sumB == a ? "jesu" : "nisu");
    return 0;
}
