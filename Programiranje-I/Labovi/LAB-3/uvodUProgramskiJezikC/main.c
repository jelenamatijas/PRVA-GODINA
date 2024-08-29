// PRVI ZADATAK
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Jelena Matijaš 1102/23");
    return 0;
}
*/

//---------------------------------------------------------------

// DRUGI ZADATAK
//pogresno
/*
#include <stdio.h>
int MAIN()
{
 integer n, kv;
 scanf("%d", n);
 kv = n * n
 printf('Kvadrat broja je: %d", kv);
 return 0;
}*/

//ispravno
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int n, kv;
 scanf("%d", &n);
 kv = n * n;
 printf("Kvadrat broja je: %d", kv);
 return 0;
}
*/

//---------------------------------------------------------------

//TRECI ZADATAK

#include <stdio.h>
#include <stdlib.h>
int main()
{
    /*int number;
    printf("Unesi cijeli broj: ");
    scanf("%d", &number);
    if(number > 0)
    {
        while(number>0)
        {
            number -= 2;
        }
    }
    else
    {
        while(number<0)
        {
            number += 2;
        }
    }
    if(number == 0 )
    {
        printf("Broj je paran.");
    }
    else
    {
        printf("Broj je neparan.");
    }*/

    int x=1235;
    printf("%d",((x/10)%10)%2==0);
    return 0;
}


//---------------------------------------------------------------
//CETVRTI ZADATAK
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    float radijani=0,stepeni;
    printf("Unesi ugao izrazen u stepenima: ");
    scanf("%f", &stepeni);
    radijani = stepeni /180;
    printf("%.0f stepeni = %.2fPI radijana", stepeni, radijani);

    return 0;
}*/












