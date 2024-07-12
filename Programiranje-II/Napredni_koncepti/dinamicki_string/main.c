#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/**Napisati funkciju sa promjenljivim brojem argumenata koja formira dinamički string na osnovu zadatog formata (%d, %s, %f, %lf, %c).*/

char* din_string(char *s, ...)
{
    char *string = (char*)calloc(1,1), *pos, val[52], *tren, *str;
    int br=0;
    char c;
    va_list args;
    va_start(args, s);

        while(pos = strstr(s, "%")){
        if(pos[1] == 's')
        {
            str = va_arg(args, char*);
            tren = (char*)calloc(1,strlen(string) + (pos-s) + strlen(str) +1);
            strcat(tren, string);
            strncat(tren, s, pos-s);
            strcat(tren, str);
        }
        else if(pos[1] == 'c')
        {
            c = (char)va_arg(args, int);
            tren = (char*)calloc(1,strlen(string) + (pos-s) + 2);
            strcat(tren, string);
            strncat(tren, s, pos-s);
            tren[strlen(tren)]=c;
            tren[strlen(tren)+1] = 0;
        }
        else
        {
            if(pos[1] == 'd')
            {
                itoa(va_arg(args, int), val, 10);
            }
            else if(pos[1] == 'f')
            {
                sprintf(val,"%f",va_arg(args, float));
            }
            /**else if(pos[1] == 'l' && pos[2] == 'f')
            {
                fltoa(val, 52, "%lf", va_arg(args, double));
                br=1;
            }*/
            tren = (char*)calloc(1,strlen(string) + (pos-s) + strlen(val) +1);
            strcat(tren, string);
            strncat(tren, s, pos-s);
            strcat(tren, val);
        }
        if(br)
        {
            s = pos+3;
            br=0;
        }
        else
        {
            s = pos+2;
        }
        free(string);
        string = tren;
        tren = 0;
    }
    va_end(args);
    tren = (char*)calloc(1,strlen(string) + strlen(s) +1);
    strcat(tren, string);
    strcat(tren, s);
    free(string);
    string = tren;
    tren=0;
    return string;
}
int main()
{
    char *s;
    s = din_string("Petar ima %d godina i ide u %s razred.\nJabuke kostaju %f maraka.", 7, "drugi", 2.35);
    printf("%s", s);
    free(s);

    return 0;
}
