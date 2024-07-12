#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji u datoteci, čije se ime navodi kao prvi argument komandne linije, zamjenjuje sva pojavljivanja karaktera
koji se navodi kao drugi argument komandne linije karakterom koji se navodi kao treći argument komandne linije.*/
int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("Pogresan unos argumenata.");
        return 1;
    }
    FILE *file;
    if(file = fopen(argv[1], "r"))
    {
        fseek(file, 0, SEEK_END);
        int br = ftell(file);
        rewind(file);
        char *str = (char*)calloc(1,br+1);
        fread(str, 1, br, file);
        char a = argv[2][0], b=argv[3][0];
        int i=0;
        fclose(file);
        if(file = fopen(argv[1], "w"))
        {
            while(str[i])
            {
                if(str[i]==a)
                {
                    fputc(b, file);
                }
                else
                {
                    fputc(str[i], file);
                }
                i++;
            }
        }
        fclose(file);
        free(str);
    }
    return 0;
}
