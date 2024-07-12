#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**Napisati rekurzivnu funkciju invert koja
kao parametre prima niz stringova (parametar niz) i
cijeli broj n koji predstavlja broj stringova u nizu.
Funkcija invert invertuje svaki string u nizu i vraća na
istu poziciju u niz. Invertovani string ne smije da sadrži
cifre. Obradu svakog stringa potrebno je vršiti u
odvojenom rekurzivnom pozivu.
Prototip funkcije invert je:
void invert(char **niz, int n);*/

void invert(char **niz, int n)
{
    if (n >= 0)
    {
        int len = strlen(niz[n]);
        char s[len + 1];
        int i = 0, j = 0;
        while (i < len)
        {
            if (isdigit(niz[n][len - i - 1])==0)
            {
                s[j++] = niz[n][len - i - 1];
            }
            i++;
        }
        s[j] = '\0';
        strcpy(niz[n], s);
        invert(niz, n - 1);
    }
}


int main()
{
    int n=3;
    char **niz = (char**)calloc(sizeof(char*), n);
    for(int i=0;i<n;i++){
        niz[i] = (char*)calloc(sizeof(char), 20);
    }
    strcpy(niz[0],"Marko");
    strcpy(niz[1],"Jan1ko");
    strcpy(niz[2],"Ansta#sija");
    invert(niz, n-1);
    for(int i=0; i<n; i++)
    {
        printf("%s\n", niz[i]);
    }
        for(int i=0;i<n;i++){
        free(niz[i]);
    }
    free(niz);
    return 0;
}
