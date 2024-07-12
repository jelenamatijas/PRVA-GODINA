#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju (bez korištenja
funkcija iz string.h) koja kao rezultat vraća novi
dinamički string koji se sastoji samo od velikih i
malih slova iz datog stringa. Prototip funkcije je:
char* slova(const char *s);
Napisati funkciju koja sortira dati string (tj.
znakove stringa) u rastućem redosledu. Prototip
funkcije je:
void sortiraj(char *s);
Napisati glavnu funkciju u kojoj je potrebno sa
standardnog ulaza učitati string, a zatim
(korištenjem funkcije slova) na osnovu učitanog
stringa kreirati novi dinamički string koji se sastoji
samo od velikih i malih slova iz učitanog stringa.
Na kraju, novi string sortirati korištenjem funkcije
sortiraj, pa ispisati na standardni izlaz.*/

char* slova(const char *s);
void sortiraj(char *s);

int main()
{
    printf("Unesi string: ");
    char str[30];
    gets(str);
    char *novi = slova(str);
    sortiraj(novi);
    printf("Novi string: %s", novi);
    free(novi);
    return 0;
}

char* slova(const char *s)
{
    int br=0;
    for(int i=0; s[i]; i++)
    {
        if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z'))
        {
            br++;
        }
    }
    char *str = (char*)malloc((br+1)*sizeof(char));
    if(str==NULL){
        return NULL;
    }
    for(int i=0, j=0; s[i]; i++)
    {
        if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z'))
        {
            str[j]=s[i];
            j++;
        }
    }
    str[br]=0;
    return str;
}

void sortiraj(char *s){
    int duzina = 0;
    while(s[duzina]) duzina++;
    for(int i=0;i<duzina-1;i++){
        for(int j=i+1;j<duzina;j++){
            if(s[i]>s[j]){
                //printf("%d %d\n", s[i], s[j]);
                char c=s[i];
                s[i]=s[j];
                s[j]=c;
            //printf("%d %d\n", s[i], s[j]);
            }
        }
    }
}
