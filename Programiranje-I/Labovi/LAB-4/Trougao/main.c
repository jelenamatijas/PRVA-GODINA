#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    printf("Unesi stranicu a: ");
    scanf("%f", &a);
    printf("Unesi stranicu b: ");
    scanf("%f", &b);
    printf("Unesi stranicu c: ");
    scanf("%f", &c);
    if(a+b>c && a+c>b && b+c>a)
    {
        if(a==b && a==c && b==c)
        {
            printf("Trougao je jednakostranicni.\n");
        }
        else if((a==b && a!=c) || (a==c && a!=b) || (b==c && b!=a))
        {
            printf("Trougao je jednakokraki.\n");
        }
        else
        {
            printf("Trougao je raznostranicni.\n");
        }
        if((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
        {
            printf("Trougao je pravougli.\n");
        }
        float povrsina=0.0, obim=0;
        povrsina = a*b/2;
        obim = a+b+c;
        printf("Povrsina: %.2f\nObim: %.2f\n", povrsina, obim);
    }
    else
    {
        printf("Trougao se ne moze konstruisati.\n");
    }
    return 0;
}
