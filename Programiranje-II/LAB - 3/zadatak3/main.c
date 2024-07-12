#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati funkciju koji vrši konkatenaciju (spajanje) stringova i sabiranje cjelobrojnih podataka koji su
argumenti komandne linije te nakon toga ispisuje rezultat. Stringovi se navode poslije argumenta
komandne linije –s a brojevi poslije argumenta komandne linije –b.
Prototip funkcije je:
void spoji_saberi(int argc, char *argv[], char* (*dodaj)(char*, char*),int (*saberi)(int, int));
Pri tome prva funkcija dodaje naredni string koji je argument komandne linije na string koji je do tog
trenutka kreiran i vraća novi string, a druga funkcija na trenutnu sumu dodaje naredni broj koji je
argument komandne linije i vraća novu sumu. U glavnom programu ilustrovati upotrebu funkcije.
Uzeti u obzir samo kombinacije koje su navedene u narednim primjerima uz pretpostavku da će
argumenti biti uneseni pravilno. Primjeri poziva i izvršavanja programa:
D:\>program.exe -s ab cd ef –b 1 2 3
String je 'abcdef'. Suma brojeva je 6.
D:\>program.exe -s ab cd ef
String je 'abcdef'.
D:\>program.exe –b 1 2 3
Suma brojeva je 6.
D:\>program.exe –b 1 2 3 -s ab cd ef
Suma brojeva je 6. String je 'abcdef'.*/

void spoji_saberi(int argc, char *argv[], char* (*dodaj)(char*, char*),int (*saberi)(int, int));
char* dodaj(char *s1, char *s2);
int saberi(int s, int b2);

int main(int argc, char *argv[])
{
    spoji_saberi(argc, argv, &dodaj, &saberi);
    return 0;
}

void spoji_saberi(int argc, char *argv[], char* (*dodaj)(char*, char*),int (*saberi)(int, int))
{
    int i=2,suma=0;
    char *string = (char*)calloc(1,1);
    if(strcmp(argv[1],"-b")==0) //ako su prvo brojevi
    {
        while(i<argc && (strcmp(argv[i],"-s")!=0)) // saberi brojeve dok ne dodjes do kraja ili do novog specifikatora
        {
            suma = saberi(suma, atoi(argv[i]));
            i++;
        }
        if(i!=argc && (strcmp(argv[i],"-s")==0)) // ako nije kraj i ako postoji drugi specifikator
        {
            i++;
            while(i<argc) // dok ne dodjes do kraja dodaj novi string
            {
                string = dodaj(string, argv[i]);
                i++;
            }
        }

    }
    else if(strcmp(argv[1],"-s")==0) // ako su prvo stringovi
    {
        while(i<argc && (strcmp(argv[i],"-b")!=0)) // sve dok ne dodjes do kraja ili do drugog specifikatora dodaj novi string
        {
            string = dodaj(string, argv[i]);
            i++;
        }
        if(i!=argc && (strcmp(argv[i],"-b")==0)) // ako nije kraj i ako postoji drugi specifikator
        {
            i++;
            while(i<argc) // dok ne dodjes do kraja sabiraj
            {
                suma = saberi(suma, atoi(argv[i]));
                i++;
            }
        }

    }
    if(strlen(string)>0){
        printf("String je '%s'. ", string);
    }
    if(suma){
        printf("Suma je %d.", suma);
    }
    free(string);
}
char* dodaj(char *s1, char *s2)
{
    char *temp = (char*)calloc(strlen(s1)+strlen(s2)+1, sizeof(char));
    strcat(temp, s1);
    strcat(temp, s2);
    free(s1);
    return temp;
}
int saberi(int s, int br)
{
    return s+br;
}
