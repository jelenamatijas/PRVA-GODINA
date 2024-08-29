#include <stdio.h>
#include <stdlib.h>
/*Definisati tip RAZLOMAK kojim se reprezentuje razlomak (svaki razlomak ima cjelobrojni imenilac i prirodni
brojilac). Napisati program koji učitava dva razlomka, a zatim ih sabira te ispisuje rezultujući razlomak. Uzeti
u obzir kraćenje rezultujućeg razlomka.
*/


struct RAZLOMAK
{
    int brojilac, imenilac;
};
int main()
{
    struct RAZLOMAK r1, r2, zbir;
    printf("Unesi imenilac i brojilac prvog broja: \n");
    scanf("%d%d",&r1.brojilac, &r1.imenilac);
    printf("Unesi imenilac i brojilac drugog broja: \n");
    scanf("%d%d",&r2.brojilac, &r2.imenilac);
    zbir.imenilac = r1.imenilac*r2.imenilac;
    zbir.brojilac = r1.imenilac*r2.brojilac + r1.brojilac*r2.imenilac;

    int k = (abs(zbir.imenilac)<abs(zbir.brojilac))?abs(zbir.imenilac):abs(zbir.brojilac);
    for(int i=2; i<=k;)
    {
        if(zbir.imenilac%i==0 && zbir.brojilac%i==0)
        {
            zbir.imenilac/=2;
            zbir.brojilac/=2;
        }
        else
        {
            i++;
        }
    }
    printf("Zbir = %d/%d", zbir.brojilac, zbir.imenilac);
    return 0;
}
