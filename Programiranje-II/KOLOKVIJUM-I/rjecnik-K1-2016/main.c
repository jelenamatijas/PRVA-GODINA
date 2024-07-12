#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**U ulaznoj tekstualnoj datoteci, čiji je
naziv prvi argument komandne linije, u svakom redu
su zasebno i nesortirano upisani parovi riječi: riječ na
srpskom i riječ na engleskom jeziku. Jedan par riječi se
može opisati tipom:
typedef struct srp_eng
{
char srp[16], eng[16];
} SRP_ENG;
Napisati program u programskom jeziku C koji iz
ulazne datoteke čita podatke o nepoznatom broju
parova riječi. Potom se sa standardnog ulaza unosi
jedna riječ na srpskom jeziku, a na standardni izlaz se
ispisuje njen prevod na engleski jezik.
Pretragu (sekvencijalno pretraživanje) riječi potrebno
je implementirati u funkciji čiji je prototip:
int seq_search(SRP_ENG *parovi, int n,
char *rijec_srp);
Primjer pokretanja i izvršavanja programa:
C:\>prevodilac.exe RJECNIK.TXT
Unesite rijec (srp): kiseonik
kiseonik -> oxygen*/

typedef struct srp_eng
{
    char srp[16], eng[16];
} SRP_ENG;

int seq_search(SRP_ENG *parovi, int n,
               char *rijec_srp);

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("Ime datoteke nije uneseno.\n");
        return -1;
    }
    FILE *in = fopen(argv[1], "r");
    if(!in){
        printf("Nije moguce otvoriti datoteku.\n");
        return -2;
    }

    char rijec[16];
    int p=0;
    SRP_ENG rijec_rjecnik;

    printf("Unesi rijec: ");
    scanf("%s", &rijec);

    while(fscanf(in, "%s %s\n", &rijec_rjecnik.srp, &rijec_rjecnik.eng)!=EOF && !p){
        if(strcmp(rijec, rijec_rjecnik.srp)==0){
            printf("%s -> %s\n", rijec, rijec_rjecnik.eng), p=1;
        }
    }
    if(!p){
        printf("Ne postoji data rijec u rjecniku.\n");
    }
    fclose(in);
    return 0;
}
