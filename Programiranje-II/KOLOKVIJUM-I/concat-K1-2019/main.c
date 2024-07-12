#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**Napisati funkciju concat koja kao
obavezne parametre prihvata pokazivač na funkciju
(parametar f) i broj n, a zatim n cijelih brojeva
(neobavezni parametri).
Parametar f treba da pokazuje na funkciju koja kao
parametar prihvata cijeli broj, a kao rezultat vraća
vrijednost 0 ako neki uslov nije ispunjen za dati cijeli
broj, a vrijednost 1 ako taj uslov jeste ispunjen za dati
cijeli broj.
Funkcija concat treba da cijele brojeve (neobavezni
parametri) za koje je ispunjen neki uslov koji se
provjerava korištenjem parametra f, pretvori u
stringove i spoji ih u jedan dinamički string koji se
vraća kao rezultat izvršavanja funkcije. Ako dati uslov
nije ispunjen niti za jedan cijeli broj, funkcija treba da
vrati NULL.
Prototip funkcije concat je:
char* concat(int (*f)(int), int n, ...);*/


int f(int x)
{
    return x>0 ? 1 : 0;
}

char* concat(int (*f)(int), int n, ...)
{
    int c=20, br=0;
    char *str = (char*)calloc(sizeof(char), c+1);
    if(str==NULL)return NULL;
    va_list args;
    va_start(args, n);

    for(int i=0; i<n; i++)
    {
        int broj = va_arg(args, int);
        if((*f)(broj))
        {
            char temp[21];
            sprintf(temp, "%d", broj);
            br+=strlen(temp);
            if(br>=c)
            {
                str = (char*)realloc(str, sizeof(char)*c*2);
                if(str==NULL)return NULL;
                c*=2;
            }
            strcat(str, temp);

        }
    }
    if(br==0)return NULL;
    if(br==c)
    {
        str = (char*)realloc(str, sizeof(char)*(c+1));
        if(str==NULL)return NULL;
    }
    str[br]=0;
    return str;

}

int main()
{
    int n=5;
    char *str = concat(f, n, 12, -32, 5, 44, 0);
    if(str==NULL)return -1;
    printf("%s\n", str);
    free(str);
    return 0;
}
