#include <stdio.h>
#include <stdlib.h>
/*Definisati tip ARTIKAL kojim se reprezentuju podaci o jednom artiklu. Svaki artikl karakteriše identifikator
(prirodan broj), naziv (string), količina (realan broj) i cijena (realan broj). Napisati program koji učitava
prirodan broj n i niz od n podataka o artiklima. Učitani niz podataka o artiklima sortirati rastuće po
identifikatoru. Na kraju, formatirano ispisati sortirani niz podataka o artiklima, kao i ukupnu cijenu svih
artikala.
Primjer ispisa:
===== ==================== ====== ====== =========
ID NAZIV CIJENA KOL. UKUPNO
===== ==================== ====== ====== =========
11111 Jabuke 2.30 1.00 2.30
22222 Banane 3.10 1.50 4.65
==================================================
 UKUPNO: 6.95
==================================================*/
#define MAX 30
struct ARTIKL
{
    int id;
    char naziv[MAX];
    double kolicina, cijena;
};
int main()
{
    int n;
    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    }
    while(n<1 || n>100);
    struct ARTIKL nizArtikala[n];
    for(int i=0; i<n; i++)
    {
        printf("Unesi podatke za %d. artikla: \n", i+1);
        printf("\tUnesi identifikator: ");
        scanf("%d", &nizArtikala[i].id);
        printf("\tUnesi naziv: ");
        scanf("%s", &nizArtikala[i].naziv);
        printf("\tUnesi kolicinu: ");
        scanf("%lf", &nizArtikala[i].kolicina);
        printf("\tUnesi cijenu: ");
        scanf("%lf", &nizArtikala[i].cijena);
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(nizArtikala[i].id>nizArtikala[j].id)
            {
                struct ARTIKL pom = nizArtikala[i];
                nizArtikala[i]=nizArtikala[j];
                nizArtikala[j]=pom;
            }
        }
    }
    printf("===== ==================== ====== ====== =========\n");
    printf("ID    NAZIV                CIJENA KOL.   UKUPNO\n");
    printf("===== ==================== ====== ====== =========\n");
    for(int i=0; i<n; i++)
    {
        printf("%-4d ", nizArtikala[i].id);
        printf("%-20s ", nizArtikala[i].naziv);
        printf("%-6.2lf ", nizArtikala[i].cijena);
        printf("%-6.2lf ", nizArtikala[i].kolicina);
        printf("%-9.2lf\n", nizArtikala[i].kolicina*nizArtikala[i].cijena);
    }
    return 0;
}
