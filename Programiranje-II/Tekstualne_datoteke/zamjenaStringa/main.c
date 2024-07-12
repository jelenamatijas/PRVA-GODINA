#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program koji u datoteci, čije se ime navodi kao prvi argument komandne linije, zamjenjuje sva pojavljivanja stringa koji se
navodi kao drugi argument komandne linije stringom koji se navodi kao treći argument komandne linije.*/
int main(int argc, char *argv[])
{
    if(argc!=4){
        printf("Pogresan broj argumenata.");
        return 1;
    }
    FILE *file;
    if(file = fopen(argv[1], "r")){
        char *s1 = (char*)calloc(1,strlen(argv[2]));
        strcpy(s1, argv[2]);
        char *s2 = (char*)calloc(1,strlen(argv[3]));
        strcpy(s2, argv[3]);
        char *str = (char*)calloc(1,1);
        char rijec[100]="";


    }else{
        printf("GRESKA!");
        return 1;
    }
    return 0;
}
