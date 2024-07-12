#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati funkciju strsort koja niz od n
stringova sortira u rastućem redoslijedu korištenjem
insert-sort algoritma. Pri tome, parametar k
predstavlja pokazivač na funkciju koja vrši poređenje
dva stringa prema nekom kriterijumu po kojem se vrši
sortiranje. Funkcija za poređenje dva stringa vraća
negativnu vrijednost ako je prvi string manji od
drugog, vrijednost 0 ako su stringovi jednaki te
pozitivnu vrijednost ako je prvi string veći od drugog.
Prototip funkcije je:
void strsort(char **niz, int n,
int (*k)(const char *, const char *));*/


void strsort(char **niz, int n,int (*k)(const char *, const char *))
{
    int i,j;
    for(i=1; i<n; i++)
    {
        char *temp = (char*)calloc(sizeof(char), strlen(niz[i])+1);
        strcpy(temp, niz[i]);
        for(j=i; j>0 && (*k)(niz[j-1], temp)>0; j--)
        {

            niz[j] = (char*)realloc(niz[j], strlen(niz[j-1])+1);
            strcpy(niz[j], niz[j-1]);

        }
        niz[j] = (char*)realloc(niz[j], strlen(temp)+1);
        strcpy(niz[j], temp);
        free(temp);
    }
}

int main()
{
    char **str = (char**)calloc(sizeof(char*), 3);
    for(int i=0; i<3; i++)
    {
        printf("Unesi string: ");
        char pom[30];
        scanf("%s", &pom);
        str[i] = (char*)calloc(sizeof(char), strlen(pom)+1);
        strcpy(str[i], pom);
    }
    strsort(str, 3, strcmp);
    for(int i=0; i<3; i++)
    {
        printf("%s\n", str[i]);
        free(str[i]);
    }
    free(str);
    return 0;
}
