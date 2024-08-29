#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265359
/**Napisati program koji iz datoteke čiji je naziv prvi argument komandne linije, čita podatke o krugovima,
a zatim pronalazi i, na standardni izlaz, ispisuje podatke o krugu koji ima najveću površinu. Ulazna
datoteka u kojoj su upisani podaci o krugovima formatirana je tako da je u svakom redu datoteke upisan
podatak o jednom krugu u obliku:
(x,y,r)
gdje su x i y koordinate centra kruga, a r poluprečnik kruga.
Primjer pokretanja i izvršavanja programa:
D:\>krug.exe KRUGOVI.TXT
Najvecu povrsinu (P=52.810) ima krug:
(-2.500,-2.250,4.100)*/

typedef struct krug
{
    double x,y,r;
} KRUG;

int main(int argc, char *argv[])
{
    FILE *file;
    if((file = fopen(argv[1], "r"))!=NULL)
    {
        KRUG k, max= {};
        while((fscanf(file, "%*c%lf%*c%lf%*c%lf%*c\n",&k.x,&k.y,&k.r))!=EOF)
        {
            double p1=pow(k.r, 2)*PI, p2=pow(max.r,2)*PI;
            if(p1>p2)
                max = k;
        }
        printf("Najvecu povrsinu (P=%.2lf) ima krug: (%.2lf,%.2lf,%.2lf).", pow(max.r,2)*PI, max.x,max.y,max.r);
        fclose(file);
    }
    else
    {
        printf("GRESKA!\n");
    }
    return 0;
}
