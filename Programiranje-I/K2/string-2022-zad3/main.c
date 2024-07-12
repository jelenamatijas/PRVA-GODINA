#include <stdio.h>
#include <stdlib.h>
/**Napisati funkciju (nije dozvoljeno
korištenje drugih funkcija) koja proverava i vraća
informaciju o tome da li je dati znak malo slovo.
Prototip funkcije je:
int is_lower(char c);
Napisati funkciju (dozvoljeno je korištenje samo
funkcije is_lower) koja sva mala slova u datom
stringu pretvara u velika. Prototip funkcije je:
void upper(char *s);
Napisati glavnu funkciju u kojoj treba učitati jedan
string sa standardnog ulaza, a zatim (korištenjem
funkcije upper) sva mala slova pretvoriti u velika,
pa modifikovani string ispisati na standardni izlaz.*/

int is_lower(char c);
void upper(char *s);


int main()
{
    char str[50];
    printf("Unesi jedan string: ");
    gets(str);
    for(int i=0;str[i];i++){
        if(is_lower(str[i])){
            upper(&str[i]);
        }
    }
    printf("Novi string: ");
    puts(str);
    return 0;
}

int is_lower(char c){
    if(c>='a' && c<='z'){
        return 1;
    }
    return 0;
}

void upper(char *s){
    int raz = 'A'-'a';
    *s+=raz;
}
