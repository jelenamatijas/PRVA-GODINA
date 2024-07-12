#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji učitava prirodan broj n te podatke (šifra – string od pet znakova, naziv – string od
najviše 20 znakova, i cijena – realan broj) o n artikala, a zatim učitane podatke upisuje u tekstualnu
datoteku čiji je naziv prvi argument komandne linije. Podaci treba da budu upisani u formatiranom
obliku kako je dato u primjeru.
Primjer pokretanja i izvršavanja programa
(vrijednosti koje se unose sa standardnog ulaza
su podvučene):
D:\>artikli.exe ARTIKLI.TXT
n=2
1. artikal: A0001 Banane 2
2. artikal: B1234 Jabuke 1.5
*/

typedef struct artikl{
    char sifra[6], naziv[21];
    double cijena;
}ARTIKL;

void header(FILE *file){
    fprintf(file, "=== ===== ==================== ======\n");
    fprintf(file, "RB. SIFRA NAZIV                CIJENA\n");
    fprintf(file, "=== ===== ==================== ======\n");
}

void footer(FILE *file){
    fprintf(file, "=== ===== ==================== ======\n");
}

void upisi_artikl(FILE *file, int rdBr, ARTIKL *art){
    fprintf(file, "%d. %-5s %-20s %-6.2lf\n", rdBr, art->sifra, art->naziv, art->cijena);
}

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "w");
    if(file!=NULL)
    {
        header(file);
        printf("n=");
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            printf("%d. artikl: ", i);
            ARTIKL art;
            scanf("%s%s%lf", &art.sifra, &art.naziv, &art.cijena);
            upisi_artikl(file, i, &art);
        }
        footer(file);
        fclose(file);
    }
    else
    {
        printf("GRESKA!");
    }
    return 0;
}
