#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**Napisati funkciju sa promjenljivim brojem argumenata koja računa proizvod proizvoljnog broja realnih brojeva.*/

double proizvod(int n, ...){
    double pr=1.0;
    va_list argumenti;
    va_start(argumenti, n);

    for(int i=0;i<n;i++){
        pr *= va_arg(argumenti, double);
    }
    va_end(argumenti);
    return pr;
}

int main()
{
    printf("Proizvod(3,1.0,2.0,3.0) = %.2lf.\n",proizvod(3,1.0,2.0,3.0));
    return 0;
}
