#include <stdio.h>
#include <stdlib.h>
/**Neka je dat tip:
typedef struct {
char autor[30], zaduzeni[30], status[15];
int prioritet;
} ZADATAK;
Polja autor i zaduzeni predstavljaju string u formi
Ime-Prezime. Polje prioritet može imati vrijednosti 0, 1
i 2, pri čemu manja vrijednost predstavlja viši prioritet.
Iz tekstualne datoteke čiji je naziv prvi argument
komandne linije, treba učitati formatirano upisane
podatke o zadacima (svaki zadatak u novom redu) i u
datoteku čiji je naziv drugi argument komandne linije,
treba upisati zadatke sortirano opadajuće prema
prioritetu. Za sortiranje koristiti merge sort algoritam.*/

typedef struct {
char autor[30], zaduzeni[30], status[15];
int prioritet;
} ZADATAK;

void merge_sort(ZADATAK *niz, int begin, int end){
    int i, j, k, len = end-begin+1;
    int sredina = (begin+end)/2;
    ZADATAK *pom = (ZADATAK*)calloc(sizeof(ZADATAK), len);
    if(begin<end){

        merge_sort(niz, begin, sredina);
        merge_sort(niz, sredina+1, end);

        i=begin, j=sredina+1, k=0;

        while(i<=sredina && j<=end){
            pom[k++]=(niz[i].prioritet<niz[j].prioritet)?niz[j++]:niz[i++];
        }
        while(i<=sredina){
            pom[k++] = niz[i++];
        }
        while(j<=end){
            pom[k++]=niz[j++];
        }
        for(i=0;i<len;i++){
            niz[begin+i] = pom[i];
        }
        free(pom);
    }
}

int main(int argc, char *argv[])
{
    /**FILE *in = fopen("IN.txt", "w");
    for(int i=0;i<4;i++){
        ZADATAK z;
        scanf("%s%s%s%d", &z.autor,&z.zaduzeni, &z.status, &z.prioritet);
        fprintf(in, "%s %s %s %d\n", z.autor, z.zaduzeni, z.status, z.prioritet);
    }
    fclose(in);*/
    if(argc<3){
        printf("Nije unesen dovoljan broj argumenata.\n");
        return -1;
    }
    FILE *in = fopen(argv[1], "r"), *out = fopen(argv[2], "w");
    if(in && out){

        int br=0;
        while(fscanf(in, "%*s %*s %*s %*d\n")!=EOF){
            br++;
        }
        rewind(in);
        ZADATAK niz[br];
        for(int i=0;i<br;i++){
            fscanf(in, "%s %s %s %d\n", &niz[i].autor, &niz[i].zaduzeni, &niz[i].status, &niz[i].prioritet);
        }
        merge_sort(niz, 0, br-1);
        for(int i=0;i<br;i++){
            fprintf(out, "%s %s %s %d\n", niz[i].autor, niz[i].zaduzeni, niz[i].status, niz[i].prioritet);
        }
        fclose(in);
        fclose(out);

    }else{
        printf("Greska pri otvaranju datoteke.\n");
        return -2;
    }
    return 0;
}
