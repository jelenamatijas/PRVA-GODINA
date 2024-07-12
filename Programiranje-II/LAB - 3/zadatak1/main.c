#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
/**Napisati funkciju sa promjenljivim brojem argumenata koja cjelobrojne podatke konvertuje i spaja u
jedan dinamički string. Prototip funkcije je:
char* formiraj(int n, ...);
Napisati program kojim se ilustruje rad sa datom funkcijom. Dozvoljena je upotreba funkcija iz
string.h.
Primjer:
formiraj(3, 123, 456, 789);
 Funkcija kao rezultat vraća string čija je vrijednost "123456789".*/
#define MAX 10
char* formiraj(int n, ...);

int main()
{
    char *string = formiraj(4, 123, 456, 789,246);
    if(string)
    {
        printf("%s\n", string);
        free(string);
    }
    else
    {
        printf("GRESKA!");
    }
    return 0;
}

char* formiraj(int n, ...)
{
    char *string = calloc(1,1);
    int len=0;
    va_list argumenti;
    va_start(argumenti, n);

    for(int i=0; i<n; i++)
    {
        int niz[MAX]= {};
        int br = va_arg(argumenti, int), j=0;
        while(br)
        {
            niz[j] = br%10;
            br/=10;
            j++;
        }
        int newlen = len+j+1;
        char *temp = (char*)calloc(1, newlen);
        strcat(temp, string);
        string = temp;
        temp = NULL;
        if(string)
        {
            for(j=MAX-1; niz[j]==0; j--);
            while(j>=0)
            {
                string[len] = niz[j] + '0';
                j--;len++;
            }
            string[newlen]=0;
        }
        else
        {
            return NULL;
        }
    }
    return string;
}
