#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju (nije
dozvoljeno korištenje drugih funkcija) koja
proverava i vraća informaciju o tome da li je
dati znak cifra (0 – nije, 1 – jeste). Prototip
funkcije je:
int is_digit(char c);
Napisati funkciju (bez korištenja funkcija iz
string.h) koja vraća dinamičku kopiju stringa
str, iz koje su izbačene sve cifre. Prototip
funkcije je:
char* remove_digits(const char *str);
Napisati glavnu funkciju (korištenjem funkcije
remove_digits) u kojoj treba na standardni
izlaz ispisati string koji se dobije izbacivanjem
cifara iz stringa "Danas je 2. kolokvijum!".*/

int is_digit(char c)
{
    if(c>='0' && c<='9')
    {
        return 1;
    }
    return 0;
}

char* remove_digits(const char *str)
{
    int br=0, duzina=0;
    while(str[duzina])duzina++;
    for(int i=0; i<duzina; i++)
    {
        if(!is_digit(str[i]))
            br++;
    }
    char *novi = (char*)malloc(sizeof(char)*br);
    if(novi==NULL || br==0)return NULL;
    for(int i=0, j=0; i<duzina; i++)
    {
        if(!is_digit(str[i])){
            novi[j]=str[i];
            j++;
        }
    }
    return novi;
}

int main()
{
    char *str = "Danas je 2. kolokvijum!";
    char *novi = remove_digits(str);
    if(novi){
        puts(novi);
        free(novi);
        novi=NULL;
    }else{
        printf("GRESKA!");
    }
    return 0;
}
