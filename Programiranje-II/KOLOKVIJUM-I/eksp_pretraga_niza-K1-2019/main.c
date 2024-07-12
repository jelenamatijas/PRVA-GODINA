#include <stdio.h>
#include <stdlib.h>
/**Napisati rekurzivnu funkciju koja nad
cjelobrojnim nizom podataka vrši eksponencijalnu
pretragu. Svaki novi segment eksponencijalne
pretrage se definiše u novom rekurzivnom pozivu.
Ukoliko je tražena vrijednost u traženom opsegu,
nastaviti pretragu sekvencijalno. Ukoliko je
početak/kraj eksponencijalnog opsega izvan opsega
niza, izvršiti sekvencijalnu pretragu u dijelu niza koji
je preostao. U slučaju uspješne pretrage funkcija
vraća vrijednost 1, a u suprotnom vrijednost 0.
Prototip funkcije je:
int pretrazi (int *niz, int n, int begin,
int end, int kljuc);
Pri tome je niz – adresa početka niza, n – dužina niza,
begin – početak eksponencijalnog opsega, end – kraj
eksponencijalnog opsega i kljuc – ključ pretrage.
Smatra se da su vrijednosti begin i end unesene
ispravno prilikom poziva funkcije i da je niz sortiran.*/

int pretrazi (int *niz, int n, int begin,int end, int kljuc)
{
    if(end<n && kljuc>niz[end])
        pretrazi(niz, n, end, end*2, kljuc);
    if(begin>=n)return 0;
    for(int i=begin; i<n; i++)
    {
        if(niz[i]==kljuc)return 1;
    }
    return 0;
}

int main()
{
    int niz[10]= {1,3,5,6,7,12,28,34,40, 41};
    printf("Broj %s pronadjen u nizu.\n", pretrazi(niz, 10, 0, 1, -3)?"je":"nije");
    return 0;
}
