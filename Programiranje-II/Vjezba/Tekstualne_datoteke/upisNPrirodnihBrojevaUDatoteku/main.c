#include <stdio.h>
#include <stdlib.h>
/**Napisati program koji u datoteku, čije se ime navodi kao argument komandne linije, upisuje prvih n prirodnih brojeva (n se zadaje sa
standardnog ulaza), a zatim računa veličinu datoteke u bajtovima.*/
int main(int argc, char *argv[])
{
    if(argc!=3){
        printf("Pogresan broj argumenata.");
        return 1;
    }
    FILE *fp;
    if(fp = fopen(argv[1], "w")){
        int n = atoi(argv[2]);
        for(int i=1;i<=n;i++){
            fprintf(fp, "%d ", i);
        }
        fseek(fp, 0, SEEK_END);
        printf("Velicina datoteke: %d B.", ftell(fp));
        fclose(fp);
    }
    return 0;
}
