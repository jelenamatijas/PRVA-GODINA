#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/** Neka je dat tip:
typedef struct predmet {
char id[15]; //identifikator
char naziv[64];
int ects;
} PREDMET;
kojim se reprezentuju informacije o jednom predmetu.
Napisati funkciju fun sa promjenljivim brojem
argumenata koja prihvata pokazivač na funkciju
(parametar u), cijeli broj n i n pokazivača na PREDMET
(neobavezni argumenti).
Parametar u predstavlja pokazivač na funkciju koja
provjerava da li je ispunjen neki uslov za dati PREDMET
(funkcija vraća vrijednost 0 ako uslov nije ispunjen, a
vrijednost 1 ako uslov jeste ispunjen).
Funkcija fun treba da podatke o predmetima
(neobavezni argumenti) koji ispunjavaju dati uslov
upiše u binarnu datoteku sa nazivom
"predmeti_izlazna.dat".
Prototip funkcije fun je:
void fun(int (*u)(PREDMET *), int n,...);
Napisati funkciju provjeri_sadrzaj koja za zadati
predmet (parametar p) provjerava da li se nalazi u
tekstualnoj datoteci sa nazivom "predmeti_ulazna.txt".
Ukoliko su podaci o predmetu upisani u datoteku,
funkcija treba da vrati 1, inače treba da vrati 0.
Predmeti su jednaki ukoliko su im jednaki identifikatori.
U svakom redu datoteke je upisan podatak o jednom
predmetu u sljedećem formatu: identifikator naziv ects.
Prototip funkcije provjeri_sadrzaj je:
int provjeri_sadrzaj(PREDMET *p);*/

typedef struct predmet
{
    char id[15]; //identifikator
    char naziv[64];
    int ects;
} PREDMET;

int provjeri_sadrzaj(PREDMET *p)
{
    FILE *file=fopen("predmeti_ulazna.txt", "r");
    if(file)
    {
        char id[15];
        while(fscanf(file, "%s %*s %*d\n", &id)!=EOF)
        {
            ///printf("%s %s\n", p->id, id);
            if(strcmp(id, p->id)==0)
            {
                ///printf("OK\n");
                fclose(file);
                return 1;
            }
        }
        fclose(file);
        return 0;
    }
    else
    {
        printf("GRESKA! -1\n");
        return -1;
    }
}

void fun(int (*u)(PREDMET *), int n,...)
{
    FILE *file = fopen("predmeti_izlazna.dat", "wb");
    if(file)
    {
        va_list args;
        va_start(args, n);
        for(int i=0;i<n;i++){
            PREDMET *p = (PREDMET*)va_arg(args, PREDMET*);
            if((*u)(p)==1){
                fwrite(p, sizeof(PREDMET), 1, file);
                ///printf("%s %s %d\n", p->id, p->naziv, p->ects);
            }
        }
        va_end(args);
    }else{
        printf("GRESKA! -2\n");
    }
    fclose(file);
}

int main()
{
    PREDMET p[2]={{"P12", "Programiranje_2", 5}, {"M1", "Matematika_1", 6}};
    fun(provjeri_sadrzaj, 2, &p[0], &p[1]);
    return 0;
}
