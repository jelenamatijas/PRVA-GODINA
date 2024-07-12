#include <stdio.h>
#include <stdlib.h>
/**Dat je sljedeći tip podatka:
typedef struct {
char proizvodjac[16], model[16], gorivo[11];
int godiste, kilometraza, cijena;
} VOZILO;
Napisati glavnu funkciju (main) u kojoj treba iz
datoteke pročitati binarno upisane podatke o
nepoznatom broju vozila i u tekstualnu datoteku
upisati podatke o onim vozilima čija je cijena manja od
ili jednaka zadatoj cijeni, a godište veće od ili jednako
zadatom godištu. Podaci se u tekstualnu datoteku
upisuju u formatiranom obliku.
Argumenti komandne linije:
• prvi – naziv binarne (ulazne) datoteke,
• drugi – naziv tekstualne (izlazne) datoteke
• treći – zadata cijena i
• četvrti – zadato godište.

Pretpostaviti da su implementirane sljedeće funkcije
za upis header-a i footer-a u tekstualnu datoteku:
void header(FILE *dat);
void footer(FILE *dat);*/

typedef struct
{
    char proizvodjac[16], model[16], gorivo[11];
    int godiste, kilometraza, cijena;
} VOZILO;

void header(FILE *dat)
{
    fprintf(dat, "=============== =============== ========== ==== ======= =======\n");
    fprintf(dat, "PROIVODJAC      MODEL           GORIVO     GOD. KILOM.  CIJENA  \n");
    fprintf(dat, "=============== =============== ========== ==== ======= =======\n");
}
void footer(FILE *dat)
{
    fprintf(dat, "=============== =============== ========== ==== ======= =======\n");
}

int main(int argc, char *argv[])
{
    /**FILE *file = fopen("VOZILO.bin", "wb");
    if(file){
        int n;
        printf("Unesi broj vozila koja zelis da uneses: ");
        scanf("%d", &n);
        VOZILO vozila[n];
        for(int i=0;i<n;i++){
            scanf("%s%s%s%d%d%d", &vozila[i].proizvodjac, &vozila[i].model,&vozila[i].gorivo, &vozila[i].godiste, &vozila[i].kilometraza, &vozila[i].cijena);
        }
        fwrite(vozila, sizeof(VOZILO), n, file);
        fclose(file);
    }*/
    if(argc<5)
    {
        printf("Nedovoljan unos argumenata.\n");
        return -1;
    }

    FILE *in = fopen(argv[1], "rb");
    FILE *out = fopen(argv[2], "w");
    int cijena = atoi(argv[3]);
    int godiste = atoi(argv[4]);
    if (!in)
    {
        printf("Ulazna datoteka nije uspjesno otvorena.\n");
        return -2;
    }
    if (!out)
    {
        printf("Izlazna datoteka nije uspjesno otvorena.\n");
        fclose(in);
        return -3;
    }

    VOZILO vozilo;

    header(out);
    while(fread(&vozilo, sizeof(VOZILO), 1, in)!=NULL)
    {
        if ((vozilo.cijena <= cijena) && (vozilo.godiste >= godiste))
        {
            fprintf(out, "%-15s %-15s %-10s %-4d %-7d %-7d\n",
                    vozilo.proizvodjac, vozilo.model, vozilo.gorivo, vozilo.godiste, vozilo.kilometraza, vozilo.cijena);
        }
    }

    footer(out);

    fclose(in);
    fclose(out);

    return 0;
}
