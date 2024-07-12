#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program kojim se vrši šifrovanje unesenog teksta korištenjem Cezarove šifre. Koristiti engleski
alfabet. Cezarovom šifrom se vrši zamjena svakog slova otvorenog teksta sa slovom koje je pomjereno
za određeni broj mjesta. Koristiti Cezarovu šifru sa desnim pomjerajem od tri mjesta:
Otvoreno: ABCDEFGHIJKLMNOPQRSTUVWXYZ
Šifra: DEFGHIJKLMNOPQRSTUVWXYZABC
Napomena: uzeti u obzir i mala i velika slova.
Nakon pokretanja programa bira se jedna od sljedeće dvije opcije:
 unos novog teksta,
 prikaz šifrovanog teksta koji se učitava iz binarne datoteke na standardnom izlazu.
Unos novih podataka:
Nakon unosa proizvoljnog teksta isti se šifruje i snima u binarnu datoteku koja se prosljeđuje kao prvi
argument komandne linije.
Čitanje podataka:
Podaci se čitaju iz datoteke čiji se naziv unosi putem standardnog ulaza ili iz datoteke koja se
prosljeđuje kao prvi argument komandne linije ukoliko se za naziv datoteke navede znak „#“.
*/

int main(int argc, char *argv[])
{
    int n;
    printf("1. unos novog teksta\n2.prikaz sifrovanog teksta\nn=");
    scanf("%d", &n);
    if(n==1)
    {
        FILE *file;
        if(argc==1)
        {
            printf("Unesi ime datoteke: ");
            char s[100]={};
            scanf("%s", s);
            file=fopen(s, "wb");
        }
        else
        {
            file=fopen(argv[1], "wb");
        }
        if(file!=NULL)
        {
            printf("Novi tekst: ");
            char tekst[100]={};
            scanf("%s", &tekst);
            int i;
            for(i=0; i<=strlen(tekst); i++)
            {
                if (tekst[i] >= 'A' && tekst[i] <= 'Z')
                {
                    tekst[i] = 'A' + (tekst[i] - 'A' + 3) % 26;
                }
                else if (tekst[i] >= 'a' && tekst[i] <= 'z')
                {
                    tekst[i] = 'a' + (tekst[i] - 'a' + 3) % 26;
                }

            }
            fwrite(tekst, sizeof(char), i, file);
            fclose(file);
        }
    }
    else if(n==2)
    {
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
            char tekst[100]={};
            fseek(file, -1, SEEK_END);
            int kraj = ftell(file);
            rewind(file);
            fread(tekst, sizeof(char), kraj, file);
            printf("%s", tekst);
            fclose(file);
        }
    }
    else
    {
        printf("GRESKA!");
    }
    return 0;
}
