#include <stdio.h>
#include <stdlib.h>
/*Definisati tip KOMPLEKS kojim se reprezentuje kompleksan broj (svaki kompleksan broj ima realni i
imaginarni dio). Napisati program koji učitava prirodan broj n i niz od n kompleksnih brojeva. Učitani niz
kompleksnih brojeva sortirati opadajuće po modulu. Na kraju, ispisati sortirani niz kompleksnih brojeva*/

struct KOMPLEKS{
    double re,im;
};
int main()
{
    int n;
    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    }while(n<1);
    struct KOMPLEKS nizKompleksih[n];
    printf("Unosi brojeve:\n");
    for(int i=0;i<n;i++){
        printf("Unesi realni i imaginarni dio %d. broja: ", i+1);
        scanf("%lf%lf", &nizKompleksih[i].re,&nizKompleksih[i].im);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double modul1 = sqrt(pow(nizKompleksih[i].re,2)+pow(nizKompleksih[i].im,2));
            double modul2 = sqrt(pow(nizKompleksih[j].re,2)+pow(nizKompleksih[j].im,2));
            if(modul1<modul2){
                struct KOMPLEKS pom = nizKompleksih[i];
                nizKompleksih[i]=nizKompleksih[j];
                nizKompleksih[j]=pom;
            }
        }
    }
    printf("Sortiran niz kompleksnih brojeva:\n");
    for(int i=0;i<n;i++){
        printf("%.2lf %ci%.2lf\n", nizKompleksih[i].re, (nizKompleksih[i].im<0)?'-':'+', nizKompleksih[i].im);
    }
    return 0;
}
