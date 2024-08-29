#include <stdio.h>
#include <stdlib.h>
/*Definisati tip TROUGAO kojim se reprezentuje trougao (svaki trougao je opisan dužinama stranica). Napisati
program koji učitava jedan trougao, a zatim ispisuje njegov obim i površinu. Pri učitavanju trougla, voditi
računa o tome da se učitaju validne dužine stranica, tj. validan trougao.*/

struct TROUGAO{
    double a,b,c;
};
int main()
{
    double a, b, c;
    do{
        printf("Unesi stranice trougla: ");
        scanf("%lf%lf%lf",&a, &b, &c);
    }while(a<0 || b<0 || c<0 || a+b<=c || a+c<=b || c+b<=a);
    struct TROUGAO trougao = {a, b, c};
    double s = trougao.a + trougao.b+trougao.c;
    double p = sqrt(s*(s-trougao.a)*(s-trougao.b)*(s-trougao.c));
    printf("Obim: %.2lf\nPovrsina: %.2lf", s,p);
    return 0;
}
