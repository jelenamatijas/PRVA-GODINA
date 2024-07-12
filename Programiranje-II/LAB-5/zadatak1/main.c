#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji omogućava unos podataka u imenik, kao i prikaz postojećih podataka iz imenika.
Nakon pokretanja programa bira se jedna od sljedeće dvije opcije:
 unos novih podataka,
 prikaz postojećih podataka iz binarne datoteke na standardnom izlazu.
Unos novih podataka:
Podaci se unose za proizvoljan broj osoba. Za svaku osobu se čuvaju sljedeći podaci: ime, prezime i
broj telefona. Nakon unosa podataka o osobama vrši se snimanje podataka u binarnu datoteku koja se
prosljeđuje kao prvi argument komandne linije. Podaci se unose u sljedećem formatu:
ime prezime broj_telefona
Primjer:
Marko Markovic +38766123123
Janko Jankovic 051789789
Napomena: nije potrebno raditi validaciju unesenih podataka.
Čitanje podataka:
Podaci se čitaju iz datoteke čiji se naziv unosi putem standardnog ulaza ili iz datoteke koja se
prosljeđuje kao prvi argument komandne linije ukoliko se za naziv datoteke navede znak „#“.*/

typedef struct kontakt
{
    char ime[20], prezime[20], br_tel[13];
} KONTAKT;

int main(int argc, char *argv[])
{
    printf("1. unos novih podataka\n2.prikaz postojecih podataka\nn=");
    int n;
    scanf("%d", &n);
    if(n==1)
    {
        printf("Unesi broj novih kontakata: ");
        int br;
        scanf("%d", &br);
        KONTAKT k;
                FILE *file;
        if(argc==1)
        {
            printf("Unesi ime datoteke: ");
            char s[100]={};
            scanf("%s", s);
            file=fopen(s, "ab");
        }
        else
        {
            file=fopen(argv[1], "ab");
        }
        if(file!=NULL)
        {
            for(int i=0; i<br; i++)
            {
                printf("%d. osoba: ", i+1);
                scanf("%s%s%s", &k.ime, &k.prezime, &k.br_tel);
                fwrite(&k, sizeof(KONTAKT), 1, file);
            }
        }
        fclose(file);
    }
    else if(n==2)
    {
        KONTAKT k;
        printf("Unesi ime datoteke: ");
        char s[100]={};
        scanf("%s", s);
        FILE *file;
        if(strcmp(s,"#")==0)
        {
            file=fopen(argv[1], "rb");
        }
        else
        {
            file=fopen(s,"rb");
        }
        if(file!=NULL)
        {
            int i=0;
            while(fread(&k, sizeof(KONTAKT), 1, file))
            {
                printf("%d. osoba: %s %s %s\n", ++i,k.ime, k.prezime, k.br_tel);

            }
        }
        fclose(file);
    }
    else
    {
        printf("GRESKA!");
    }
    return 0;
}
