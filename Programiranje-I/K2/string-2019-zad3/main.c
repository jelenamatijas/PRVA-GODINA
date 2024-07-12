#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju (bez korištenja
drugih funkcija) koja veliko slovo (parametar z)
konvertuje u malo slovo. Ako znak z nije veliko
slovo, funkcija vraća originalnu vrednost. Prototip
funkcije je:
char v2m(char z);
Napisati funkciju (korištenjem funkcije v2m) koja u
svakom stringu datog niza stringova (parametar
niz) konvertuje velika slova u mala. Parametar n
predstavlja broj elemenata niza niz. Prototip
funkcije je:
void konvertuj(char **niz, int n);
Napisati glavnu funkciju u kojoj treba ilustrovati
korištenje funkcije konvertuj na nizu od pet
proizvoljnih stringova. Nakon konverzije, potrebno
je ispisati (modifikovani) niz stringova.*/

char v2m(char z);
void konvertuj(char **niz, int n);
void copystr(char *s1, char *s2){
    while(*s1++=*s2++);
}

int main()
{
    char **stringovi = (char**)malloc(sizeof(char*)*5);
    for(int i=0;i<5;i++){
        stringovi[i]=(char*)malloc(sizeof(char)*20);
    }
    copystr(stringovi[0], "Jelena");
    copystr(stringovi[1], "MARKO");
    copystr(stringovi[2], "sTefan");
    copystr(stringovi[3], "milica");
    copystr(stringovi[4], "ANA Marija");
    /**char *stringovi[] = {"Jelena", "MARKO", "sTefan", "milica","ANA Marija"};*/

    konvertuj(stringovi, 5);
    printf("Modifikovani stringovi:\n");
    for(int i=0;i<5;i++){
        puts(stringovi[i]);
        free(stringovi[i]);
    }
    free(stringovi);
    return 0;
}

char v2m(char z){
    return (z>='A' && z<='Z') ? (z-('A'-'a')) : z;
}

void konvertuj(char **niz, int n){
    for(int i=0;i<n;i++){
        for(int j=0;niz[i][j];j++){
            niz[i][j]=v2m(niz[i][j]);
        }
    }

}
