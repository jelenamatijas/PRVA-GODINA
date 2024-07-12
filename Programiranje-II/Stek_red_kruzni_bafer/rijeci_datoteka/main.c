#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program koji čita riječi iz datoteke čiji se naziv navodi kao prvi argument komandne linije i upisuje
ih nazad u datoteku, ali u obrnutom poretku. Za čuvanje riječi u programu potrebno je koristiti ulančanu reprezentaciju steka.
*/

typedef struct cvor
{
    char *s;
    struct cvor *next;
} CVOR;

void push(CVOR **tos, char *s)
{
    CVOR *novi = (CVOR*)calloc(sizeof(CVOR), 1);
    novi->s = (char*)calloc(sizeof(char), strlen(s)+1);
    strcpy(novi->s, s);
    novi->next = *tos;
    *tos=novi;
}

int pop(CVOR **tos, char *s)
{
    if(*tos==NULL)return 0;
    CVOR *p = *tos;
    strcpy(s, p->s);
    *tos = (*tos)->next;
    free(p->s);
    free(p);
}

void procitaj(FILE *f, CVOR **tos)
{
    char rijec[31];
    while(fscanf(f, "%s ", rijec)!=EOF)
    {
        push(tos, rijec);
    }
}

void upisi(FILE *f, CVOR **tos)
{
    char s[31];
    while(pop(tos, s))
    {
        fprintf(f, "%s\n", s);
    }
    *tos=0;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("Pogresan unos!\n");
        return -1;
    }
    CVOR *tos=0;
    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        printf("Nije bilo moguce otvoriti datoteku.\n");
        return -2;
    }
    procitaj(file, &tos);
    fclose(file);

    file = fopen(argv[1], "w");
    if(!file)
    {
        printf("Nije bilo moguce otvoriti datoteku.\n");
        return -3;
    }
    upisi(file, &tos);
    fclose(file);
    return 0;
}
