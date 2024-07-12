#include <stdio.h>
#include <stdlib.h>
/*Definisati tip DATUM koji je opisan atributima dan, mjesec i godina. Definisati tip STUDENT kojim se
reprezentuju podaci o studentu. Svakog studenta karakteriše broj indeksa, ime, prezime, datum rođenja i
prosjek. Napisati program koji učitava prirodan broj n i niz od n podataka o studentima. Učitani niz podataka o
studentima sortirati po datumu rođenja (počevši od najstarijeg studenta), pa formatirano ispisati sortirani niz
podataka o studentima.
Primjer ispisa:
RB. PREZIME IME DATUM RODJ. PROSJEK
=== =============== =============== =========== =======
1. Bojanic Bojana 15.09.2001. 9.31
2. Jankovic Janko 10.03.2003. 8.74
=== =============== =============== =========== =======*/
#define MAX 20

struct DATUM
{
    int dan, mjesec, godina;
};

struct STUDENT
{
    int brIndeksa;
    char ime[10], prezime[20];
    struct DATUM datRodj;
    double prosjek;
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
    struct STUDENT studenti[n];
    for(int i=0; i<n; i++)
    {
        printf("Unesi podatke za %d. studenta>>\n",i+1);
        printf("  Broj indeksa: ");
        scanf("%d", &studenti[i].brIndeksa);
        printf("  Ime: ");
        scanf("%s", &studenti[i].ime);
        printf("  Prezime: ");
        scanf("%s", &studenti[i].prezime);
        printf("  Dan, mjesec i godinu rodjenja: ");
        scanf("%d%d%d", &studenti[i].datRodj.dan, &studenti[i].datRodj.mjesec,&studenti[i].datRodj.godina);
        printf("  Prosjek ocjena: ");
        scanf("%lf", &studenti[i].prosjek);
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(studenti[i].datRodj.godina>studenti[j].datRodj.godina)
            {
                struct STUDENT pom = studenti[i];
                studenti[i]=studenti[j];
                studenti[j]=pom;
            }
            else if(studenti[i].datRodj.godina==studenti[j].datRodj.godina)
            {
                if(studenti[i].datRodj.mjesec>studenti[j].datRodj.mjesec)
                {
                    struct STUDENT pom = studenti[i];
                    studenti[i]=studenti[j];
                    studenti[j]=pom;
                }
                else if(studenti[i].datRodj.mjesec==studenti[j].datRodj.mjesec)
                {
                    if(studenti[i].datRodj.dan>studenti[j].datRodj.dan)
                    {
                        struct STUDENT pom = studenti[i];
                        studenti[i]=studenti[j];
                        studenti[j]=pom;
                    }
                }
            }
        }
    }
    printf("RB. PREZIME         IME             DATUM RODJ. PROSJEK\n");
    printf("=== =============== =============== =========== =======\n");

    for(int i=0; i<n; i++)
    {
        printf("%-3d ",i+1);
        printf("%-15s ", studenti[i].prezime);
        printf("%-15s ", studenti[i].ime);
        printf("%-2d.%-2d.%-4d. ", studenti[i].datRodj.dan, studenti[i].datRodj.mjesec, studenti[i].datRodj.godina);
        printf("%-7.2lf\n", studenti[i].prosjek);
    }
    return 0;
}
