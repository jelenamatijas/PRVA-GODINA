#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati funkciju koja na osnovu niza riječi a formira niz riječi b, pri čemu se riječ bi
(dinamički string) dobije tako što se na riječ ai primijeni odgovarajuća transformacija, a da se pri
tome ne mijenja riječ ai. Prototip funkcije je:
void formiraj(char **a, char **b, int n, char* (*t)(char *));
Napisati program u kojem treba iz tekstualne datoteke, čiji je naziv prvi argument komandne linije,
pročitati riječi i formirati odgovarajući dinamički niz riječi a, a zatim formirati (korištenjem funkcije
formiraj) dinamički niz riječi b takav da je riječ bi jednaka inverzu riječi ai. Inverz riječi je riječ koja
se sastoji od istih slova, ali u obrnutom redoslijedu. Upisati niz riječi b (svaku riječ u zasebnom redu)
u tekstualnu datoteku čiji je naziv drugi argument komandne linije.
Napomena: Riječ je jedno ili više uzastopnih (nebijelih) znakova, a od drugih riječi odvojena je
bjelinom.
Primjer poziva programa:
D:\>transformacija.exe RIJECI.TXT OBRNUTO.TXT*/

char* obrni(char*);
void formiraj(char **a, char **b, int n, char* (*t)(char *));

int main(int argc, char *argv[])
{
    if(argc==3)
    {
    FILE *file = fopen(argv[1], "r");
    FILE *novi = fopen(argv[2], "w");
    if((file!=NULL) && (novi!=NULL))
    {
        int brRijeci=0;
        while(fscanf(file, "%*s ")!=EOF)
        {
            brRijeci++;
        }
        rewind(file);
        char **rijeci = (char**)calloc(brRijeci, sizeof(char*));
        char **obrRijeci = (char**)calloc(brRijeci, sizeof(char*));
        for(int i=0; i<brRijeci; i++)
        {
            char *rijec =(char*)calloc(sizeof(char), 20);
            if(fscanf(file, "%s", rijec)!=EOF)
            {
                rijeci[i] = (char*)calloc(sizeof(char), strlen(rijec)+1);
                obrRijeci[i] = (char*)calloc(sizeof(char), strlen(rijec)+1);
                strcpy(rijeci[i], rijec);
            }
            free(rijec);
            rijec=NULL;
        }
        fclose(file);
        formiraj(rijeci, obrRijeci, brRijeci, obrni);
        for(int i=0; i<brRijeci; i++)
        {
            fprintf(novi, "%s\n", obrRijeci[i]);
        }
        fclose(novi);
        for(int i=0; i<brRijeci; i++)
        {
            free(rijeci[i]);
            free(obrRijeci[i]);
        }
        free(rijeci);
        free(obrRijeci);
    }
    else
    {
        printf("GRESKA!\n");
    }
}
    return 0;
}

char* obrni(char *rijec)
{
    int i=strlen(rijec)-1, j=0;
    char *obrRijec = (char*)calloc(sizeof(char), strlen(rijec)+1);
    while(i>=0)
    {
        obrRijec[j++] = rijec[i--];
        ///printf("%s\n", obrRijec);
    }
    return obrRijec;
}

void formiraj(char **a, char **b, int n, char* (*t)(char *))
{
    for(int i=0; i<n; i++)
    {
        strcpy(b[i],(*t)(a[i]));
        ///printf("%s\n", b[i]);
    }
}
