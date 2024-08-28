#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju (bez korištenja
drugih funkcija) koja proverava i vraća informaciju
o tome da li se dati string (s) sastoji isključivo od
malih slova (1 – string se sastoji isključivo od
malih slova, 0 – string sadrži i znakove koji nisu
mala slova). Prototip funkcije je:
int mslova(const char *s);
Napisati funkciju (dozvoljeno je korištenje samo
funkcija iz stdlib.h) koja kreira i vraća dinamičku
kopiju datog stringa (s). Prototip funkcije je:
char* dupliraj(const char *s);
Napisati funkciju (dozvoljeno je korištenje samo
funkcija mslova i dupliraj) koja kreira i vraća
dinamičku kopiju datog stringa s ako se taj string
sastoji isključivo od malih slova. U suprotnom,
funkcija treba da vrati NULL. Prototip funkcije je:
char* dupliraj_mslova(const char *s);*/

int mslova(const char *s);
char* dupliraj(const char *s);
char* dupliraj_mslova(const char *s);

int main()
{
    printf("Unesi neki string: ");
    char str[30];
    gets(str);
    char *dupli = dupliraj_mslova(str);
    if(dupli!=NULL){
        printf("Dupli string: ");
        puts(dupli);
        free(dupli);
    }else{
        printf("GRESKA!");
    }
    return 0;
}

int mslova(const char *s){
    for(int i=0;s[i];i++){
        if(s[i]<'a' || s[i]>'z'){
            return 0;
        }
    }
    return 1;
}

char* dupliraj(const char *s){
    int d=0;
    while(s[d++]);
    char *str = (char*)calloc(d+1, sizeof(char));
    if(str==NULL){
        return NULL;
    }
    for(int i=0;s[i];i++){
        str[i]=s[i];
    }
    str[d]=0;
    return str;
}

char* dupliraj_mslova(const char *s){
    if(mslova(s)){
        return dupliraj(s);
    }
    return NULL;
}
