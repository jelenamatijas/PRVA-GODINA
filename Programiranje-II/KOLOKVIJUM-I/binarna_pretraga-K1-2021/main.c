#include <stdio.h>
#include <stdlib.h>
/**Napisati nerekurzivnu funkciju pretrazi
koja binarno pretražuje niz od n cijelih brojeva tipa long
long, pri čemu je ključ pretrage zadat kao parametar
funkcije (kljuc).
U slučaju uspješne pretrage funkcija pretrazi vraća
indeks pronađenog elementa, a u slučaju neuspješne
pretrage funkcija vraća -1.
Prilikom pretrage, posjećene elemente niza (elemente
niza sa kojima je vršeno poređenje) potrebno je
upisivati u binarnu datoteku čiji je naziv zadat kao
parametar funkcije (parametar dat_naziv).
Prototip funkcije pretrazi je:
int pretrazi(const char *dat_naziv, long long
*niz, int n, long long kljuc);*/

int pretrazi(const char *dat_naziv, long long *niz, int n, long long kljuc){
    int begin=0, end=n-1, sredina;
    FILE *out = fopen(dat_naziv,"w");
    if(out==NULL){
        printf("Nije moguce otvoriti datoteku.\n");
        return -2;
    }
    do{
        sredina = (begin+end)/2;
        if(niz[sredina]==kljuc)return sredina;
        if(kljuc<niz[sredina]){
            end=sredina-1;
        }
        else{
            begin = sredina+1;
        }
        fprintf(out, "%ld\n", niz[sredina]);
    }while(begin<=end);
    fclose(out);
    return -1;
}

int main()
{
    long long niz[]={1,2,3,4,5,6,7,10,11,15};
    int n=10;
    printf("Rezultat pretrage:\n");
    int i=pretrazi("OUT2.txt", niz, n, 7);
    if(i==-1){
        printf("Nema trazenog broja u nizu.\n");
    }else{
        printf("Broj je pronadjen na indeksu %d i to je broj %ld.\n", i, niz[i]);
    }
    return 0;
}
