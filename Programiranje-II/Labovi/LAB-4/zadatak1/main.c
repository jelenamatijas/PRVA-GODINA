#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program koji iz datoteke čiji je naziv prvi argument komandne linije, čita riječi i upisuje ih
(svaku riječ u zasebnom redu) u datoteku čiji je naziv drugi argument komandne linije. Pored toga,
program treba da na standardni izlaz ispiše najdužu riječ. Riječ je jedno ili više uzastopnih slova od
drugih riječi odvojena znakom koje nije slovo.*/

int main(int argc, char *argv[])
{
    FILE *file1, *file2;
    file1 = fopen(argv[1], "r"), file2=fopen(argv[2], "w");
    if(file1!=NULL && file2!=NULL)
    {
        char s[30], smax[30],c;
        int br=0, brMax=0;
        while((c=fgetc(file1))!=EOF)
        {

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                s[br++] = c;
                fprintf(file2, "%c", c);
            }
            else if(br)
            {

                fprintf(file2, "\n");
                if(br>brMax)
                {
                    s[br]='\0';
                    strcpy(smax, s), brMax=br;
                }
                br=0;
            }
        }
        printf("Najduza rijec: %s", smax);
        fclose(file1), fclose(file2);

    }
    else
    {
        printf("GRESKA!\n");
    }
    return 0;
}
