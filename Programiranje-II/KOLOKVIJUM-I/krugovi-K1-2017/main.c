#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14
/**U ulaznoj tekstualnoj datoteci upisani su
podaci o n krugova. Pri tome, prvi upisani podatak u
datoteci je broj n, nakon čega slijede podaci o
krugovima – u svakom redu podatak o jednom krugu u
formatu (x,y,r), gdje su x i y koordinate centra
kruga, a r je dužina poluprečnika kruga. Podrazumijeva
se da su podaci u datoteci pravilno navedeni. Neka je
tip KRUG definisan na sljedeći način:
typedef struct krug{double x, y, r;} KRUG;
Napisati funkciju koja iz ulazne datoteke čita broj n i
upisuje ga na odgovarajuću memorijsku lokaciju
korištenjem parametra pn, a zatim učitava u memoriju
(heap) podatke o n krugova i kao rezultat vraća adresu
alociranog memorijskog segmenta. Prototip funkcije je:
KRUG* ucitaj(FILE *f, int *pn);
Napisati funkciju koja korištenjem shell-sort algoritma
sortira niz podataka o krugovima po površini u
rastućem redoslijedu. U glavnom programu,
korištenjem funkcije ucitaj, učitati podatke o
krugovima iz datoteke čiji je naziv prvi argument
komandne linije. Zatim sortirati podatke o krugovima i
upisati ih u tekstualnu datoteku čiji je naziv drugi
argument komandne linije. Izlazna datoteka treba biti
formatirana na isti način kao i ulazna datoteka. Kao
treći argument komandne linije, navodi se način
sortiranja podataka o krugovima: ako se kao treći
argument komandne linije navede opcija -sh, tada se
podaci o krugovima sortiraju primjenom
implementiranog shell-sort algoritma, a ako se navede
opcija -qs tada se podaci o krugovima sortiraju
korištenjem qsort funkcije (funkcija iz stdlib.h).*/

typedef struct krug{double x, y, r;} KRUG;
KRUG* ucitaj(FILE *f, int *pn);
void shell_sort(KRUG *k, int n);
int uporedi(const void *r1, const void *r2);

int main(int argc, char *argv[])
{
    if(argc<4){
        printf("Nedovoljan broj argumenata.");
        return -1;
    }
    FILE *file = fopen(argv[1], "r");
    FILE *novi = fopen(argv[2], "w");
    if(file!=NULL && novi!=NULL){
        int n;
        KRUG *krugovi = ucitaj(file, &n);
        if(strcmp(argv[3], "-sh")==0){
            shell_sort(krugovi, n);
        }else if(strcmp(argv[3], "-qs")==0){
            qsort(krugovi, n, sizeof(KRUG), uporedi);
        }else{
            printf("Pogresan unos argemnta.");
            return -1;
        }
        fprintf(novi, "%d\n", n);
        for(int i=0;i<n;i++){
            fprintf(novi, "(%.2lf,%.2lf,%.2lf)\n", krugovi[i].x, krugovi[i].y, krugovi[i].r);
        }
        fclose(file);
        fclose(novi);
    }
    return 0;
}

KRUG* ucitaj(FILE *f, int *pn){
    fscanf(f, "%d\n", pn);
    KRUG *krugovi = (KRUG*)calloc(sizeof(KRUG), *pn);
    for(int i=0;i<*pn;i++){
        if(fscanf(f, "%*c%lf%*c%lf%*c%lf%*c\n", &krugovi[i].x, &krugovi[i].y,&krugovi[i].r)!=3){printf("GRESKA!\n");}
    }
    return krugovi;
}

int uporedi(const void *r1, const void *r2){
    if(pow(*(double*)r1,2)*PI - pow(*(double*)r2,2)*PI < 0)
        return 1;
    else if(pow(*(double*)r1,2)*PI - pow(*(double*)r2,2)*PI >0)
        return -1;
    else
        return 0;
}

void shell_sort(KRUG *krugovi, int n){
    int i,j,h;
    for(h=n/2;h>0;h/=2){
        for(i=h;i<n;i++){
            KRUG krug = krugovi[i];
            for(j=i;j>=h && uporedi(&krug.r, &krugovi[j-h].r)==1;j-=h){
                krugovi[j]=krugovi[j-h];
            }
            krugovi[j]=krug;
        }
    }
}
