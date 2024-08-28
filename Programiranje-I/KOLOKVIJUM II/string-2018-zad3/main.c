#include <stdio.h>
#include <stdlib.h>
/**U programskom jeziku C (bez korištenja funkcija iz
string.h), definisati sljedeće funkcije:
• funkciju koja u zadatom stringu str pronalazi
najduži niz malih slova. Funkcija treba da vrati
pokazivač na početak najdužeg niza malih slova.
Ukoliko se mala slova ne pojavljuju u stringu,
umjesto odgovarajućeg pokazivača na početak
najdužeg niza, potrebno je vratiti NULL. Dužinu
pronađenog niza potrebno je upisati na
odgovarajuću memorijsku lokaciju korištenjem
parametra length. Prototip funkcije je:
char* max_string(char *str, int *length);
• funkciju koja kao parametre prima niz stringova
niz i broj stringova n, a koja za svaki string
(korištenjem funkcije max_string) ispisuje njegov
najduži podniz malih slova. Pri tome, originalni
stringovi ne smiju biti promjenjeni. Prototip
funkcije je:
void max_print(char **niz, int n);
Primjer korištenja funkcije:
char* niz[] =
{ "Danas je petak.", "ETF BL, Patre 5"};
max_print(niz, 2);
// Ispisuje:
// petak
// atre
• funkciju koja kao parametre prima niz stringova
niz i broj stringova n, a koja kreira i vraća
dinamički niz stringova koji se sastoji od stringova
koji predstavljaju najduže nizove malih slova u
nizu stringova niz. Funkcija treba da modifikuje niz
stringova niz na način da se iz svakog stringa
izbaci pronađeni najduži niz malih slova. Prototip
funkcije je:
char** max_array(char **niz, int n);*/
/** NIJE URADJEN DO KRAJA!!!*/
char* max_string(char *str, int *length);

int main()
{
    printf("Hello world!\n");
    return 0;
}

char* max_string(char *str, int *length){
    int br=0, index=0, max=0;
    for(int i=0;str[i];i++){
        if(str[i]>='a' && str[i]<='z'){
            if(!br){
                index=i;
            }
            br++;
        }else{
            if(*length<br){
                *length = br;
                i+=br;
                br=0;
                max=index;
            }
        }
    }
    return str[max];
}
