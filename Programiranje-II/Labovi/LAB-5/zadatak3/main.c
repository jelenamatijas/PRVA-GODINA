#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program koji omogućava unos proizvoljnog broja cjelobrojnih podataka putem standardnog
ulaza, snimanje unesenih podataka sortiranih u opadajućem redoslijedu u binarnu datoteku i prikaz
cjelobrojnih podataka iz binarne datoteke na standardnom izlazu.
Unos novih podataka:
Podaci se snimaju u binarnu datoteku koja se prosljeđuje kao prvi argument komandne linije.
Čitanje podataka:
Podaci se čitaju iz datoteke čiji se naziv unosi putem standardnog ulaza ili iz datoteke koja se
prosljeđuje kao prvi argument komandne linije ukoliko se za naziv datoteke navede znak „#“.*/

void merge_sort(int *niz, int pocetak, int kraj)
{
    if(pocetak<kraj)
    {
        int sredina = (pocetak+kraj)/2, i,j,k,len = kraj-pocetak+1;
        int *pom;

        merge_sort(niz, pocetak, sredina);
        merge_sort(niz, sredina+1, kraj);

        pom = (int*)calloc(sizeof(int), len);
        i=pocetak, j=sredina+1, k=0;
        while(i<=sredina && j<=kraj)
            pom[k++] = (niz[i]<niz[j])?niz[j++]:niz[i++];
        while(i<=sredina)
            pom[k++]=niz[i++];
        while(j<=kraj)
            pom[k++]=niz[j++];
        for(i =0; i<len; i++)
            niz[pocetak+i]=pom[i];
        free(pom);
    }
}

void merge_sort2(int *niz, int pocetak, int kraj)
{
    if(pocetak<kraj)
    {
        int sredina = (pocetak+kraj)/2, i,j,k,len = kraj-pocetak+1;
        int *pom;

        merge_sort2(niz, pocetak, sredina);
        merge_sort2(niz, sredina+1, kraj);

        pom = (int*)calloc(sizeof(int), len);
        i=pocetak, j=sredina+1, k=0;
        while(i<=sredina && j<=kraj)
            pom[k++] = (niz[i]>niz[j])?niz[j++]:niz[i++];
        while(i<=sredina)
            pom[k++]=niz[i++];
        while(j<=kraj)
            pom[k++]=niz[j++];
        for(i =0; i<len; i++)
            niz[pocetak+i]=pom[i];
        free(pom);
    }
}

int main(int argc, char *argv[])
{
    printf("1. unos novih podataka\n2.prikaz postojecih podataka\nn=");
    int n;
    scanf("%d", &n);
    if(n==1)
    {
        printf("br=");
        int br, brojac=0;
        scanf("%d", &br);
        int *niz=(int*)calloc(br,sizeof(int));
        int *niz2=(int*)calloc(br,sizeof(int));
        printf("Unesi niz: ");
        for(int i=0; i<br; i++)
        {
            scanf("%d", &niz[i]);
        }
        merge_sort(niz, 0, br-1);
        FILE *file, *novi = fopen(argv[2], "wb");
        if(argc==1)
        {
            printf("Unesi ime datoteke: ");
            char s[100]= {};
            scanf("%s", s);
            file=fopen(s, "wb");
        }
        else
        {
            file=fopen(argv[1], "wb");
        }
        if(file!=NULL && novi!=NULL)
        {
            int broj;
            printf("Unesi broj: ");
            scanf("%d", &broj);
            int brojac=0;
            for(int i=0;i<br;i++){
                int x=niz[i], suma=0;
                while(x>0){
                    suma+=x%10;
                    x/=10;
                }
                if(suma>broj){
                    niz2[brojac++]=niz[i];
                }
            }
            merge_sort2(niz2, 0, brojac-1);
            fwrite(niz2, sizeof(int), brojac, novi);
            fwrite(niz, sizeof(int), br, file);
            free(niz);
            fclose(file);
            fclose(novi);
        }
    }
    else if(n==2)
    {
        printf("Unesi ime datoteke: ");
        char s[100]= {};
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
            fseek(file, 0, SEEK_END);
            int kraj = ftell(file);
            rewind(file);
            int *niz=(int*)calloc(kraj/sizeof(int),sizeof(int));
            fread(niz, sizeof(int), kraj/sizeof(int), file);
            for(int i=0; i<kraj/sizeof(int); i++)
            {
                printf("%d ", niz[i]);
            }
            free(niz);
            fclose(file);
        }
    }
    else
    {
        printf("GRESKA!");
    }
    return 0;
}
