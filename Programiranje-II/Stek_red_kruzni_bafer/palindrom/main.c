#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program koji provjerava da li je unesena riječ palindrom pomoću steka. Potrebno je koristiti sekvencijalnu reprezentaciju steka.*/

#define MAX 31

typedef struct stek
{
    char s[MAX];
    int tos;
} STEK;

int isFull(STEK *s)
{
    return s->tos == MAX-1;
}

int isEmpty(STEK *s)
{
    return s->tos == -1;
}

int push(STEK *s, char *p)
{
    if(isFull(s))return 0;
    s->s[++s->tos]=*p;
    return 1;
}

int pop(STEK *s, char *p)
{
    if(isEmpty(s))return 0;
    *p= s->s[s->tos--];
    return 1;
}

int main()
{
    STEK s;
    s.tos=-1;
    int x=1;
    char *palindrom = "Ana voli Milovana";
    for(int i=0; i<strlen(palindrom); i++)
    {
        if(isalpha(palindrom[i]))
        {
            char c = tolower(palindrom[i]);
            push(&s, &c);
        }
    }
    for(int i=0; i<strlen(palindrom); i++)
    {
        if(isalpha(palindrom[i]))
        {
            char c;
            pop(&s, &c);
            if(tolower(palindrom[i])!= c){
                x=0;
                break;
            }
        }
    }

    printf("%s palindrom.\n", x?"Jeste":"Nije");
    return 0;
}
