#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**Napisati program u kojem treba učitati n riječi i formirati odgovarajući dinamički niz, a
potom učitani niz riječi ispisati sortirano u opadajućem redoslijedu, pri čemu je kriterijum poređenja broj samoglasnika u riječi.*/

int brSamoglasnika(char *s)
{
    int br=0, i=0;
    while(s[i++])
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            br++;
    }
    return br;
}

void selection_sort(char **rijeci, int n)
{
    int i,j,min;
    for(i=0; i<n-1; i++)
    {
        for(min=i, j=i+1; j<n; j++)
        {
            if(brSamoglasnika(rijeci[min])<brSamoglasnika(rijeci[j]))min=j;
            if(min!=i)
            {
                char *s = (char*)calloc(sizeof(char), strlen(rijeci[i])+1);
                strcpy(s, rijeci[i]);
                strcpy(rijeci[i], rijeci[min]);
                strcpy(rijeci[min], s);
                free(s);
            }
        }
    }
}

void insertion_sort(char **rijeci, int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        char *s = (char *)calloc(sizeof(char), strlen(rijeci[i])+1);
        strcpy(s, rijeci[i]);
        for(j=i; j>0 && brSamoglasnika(s)>brSamoglasnika(rijeci[j-1]); j--)
        {
            strcpy(rijeci[j], rijeci[j-1]);
        }
        strcpy(rijeci[j], s);
        free(s);
    }
}

void shell_sort(char **rijeci, int n)
{
    int i, j, h;
    for(h=n/2; h>0; h/=2)
    {
        for(i=h; i<n; i++)
        {
            char *s = (char *)calloc(sizeof(char), strlen(rijeci[i])+1);
            strcpy(s, rijeci[i]);
            for(j=i; j>=h && brSamoglasnika(s)>brSamoglasnika(rijeci[j-h]); j-=h)
            {
                strcpy(rijeci[j], rijeci[j-h]);
            }
            strcpy(rijeci[j], s);
            free(s);
        }
    }
}

void bubble_sort(char **rijeci, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(brSamoglasnika(rijeci[j])<brSamoglasnika(rijeci[j+1])){
                char pom[20]={};
                strcpy(pom, rijeci[j]);
                strcpy(rijeci[j], rijeci[j+1]);
                strcpy(rijeci[j+1], pom);
            }
        }
    }
}

void merge_sort(char **rijeci, int begin, int end){
    if(begin<end){
        int sredina = (begin+end)/2, i, j, k,len = end-begin+1;
        merge_sort(rijeci, begin, sredina);
        merge_sort(rijeci, sredina+1, end);

        char **pom = (char**)calloc(sizeof(char*), len);
        for(int m=0;m<len;m++)
            pom[m] = (char*)calloc(sizeof(char), 21);
        i=begin, j=sredina+1, k=0;
        while(i<=sredina && j<=end){
            strcpy(pom[k++], (brSamoglasnika(rijeci[i])>brSamoglasnika(rijeci[j]))?rijeci[i++]:rijeci[j++]);
        }
        while(i<=sredina) strcpy(pom[k++], rijeci[i++]);
        while(j<=end) strcpy(pom[k++], rijeci[j++]);
        for(i=0;i<len;i++)
            strcpy(rijeci[begin+i], pom[i]);
        free(pom);
    }
}

int split(char **rijeci, int begin, int end){
    int i=begin, j=end;
    char *pivot = (char*)calloc(sizeof(char), strlen(rijeci[begin])+1);
    strcpy(pivot, rijeci[begin]);
    while(i<j){
        while((brSamoglasnika(rijeci[i])>=brSamoglasnika(pivot)) && i<j)i++;
        while(brSamoglasnika(rijeci[j])<brSamoglasnika(pivot))j--;
        if(i<j){
            char *pom = (char*)calloc(sizeof(char), strlen(rijeci[i])+1);
            strcpy(pom, rijeci[i]);
            rijeci[i] = (char*)realloc(rijeci[i], sizeof(char)*(strlen(rijeci[j])+1));
            strcpy(rijeci[i], rijeci[j]);
            rijeci[j] = (char*)realloc(rijeci[j], sizeof(char)*(strlen(pom)+1));
            strcpy(rijeci[j], pom);
            free(pom);
        }
        rijeci[begin] = (char*)realloc(rijeci[begin], sizeof(char)*(strlen(rijeci[j])+1));
        strcpy(rijeci[begin], rijeci[j]);
        rijeci[j] = (char*)realloc(rijeci[j], sizeof(char)*(strlen(pivot)+1));
        strcpy(rijeci[j], pivot);
    }
    return j;
}

void quick_sort(char **rijeci, int begin, int end){
    if(begin<end){
        int pivot = split(rijeci, begin, end);
        quick_sort(rijeci, begin, pivot-1);
        quick_sort(rijeci, pivot+1, end);
    }
}

int main()
{
    printf("Unesi broj rijeci: ");
    int n;
    scanf("%d", &n);
    char **rijeci = (char**)calloc(sizeof(char*), n);
    char *rijec = (char*)calloc(sizeof(char), 21);
    printf("Unesi rijeci:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%s", rijec);
        rijeci[i] = (char*)calloc(sizeof(char), strlen(rijec)+1);
        strcpy(rijeci[i], rijec);
    }
    free(rijec);


    ///selection_sort(rijeci, n);
    ///insertion_sort(rijeci, n);
    ///shell_sort(rijeci, n);
    ///bubble_sort(rijeci, n);
    ///merge_sort(rijeci, 0, n-1);
    quick_sort(rijeci, 0, n-1);
    for(int i=0; i<n; i++)
    {
        printf("%s\n", rijeci[i]);
    }
    for(int i=0; i<n; i++)
    {
        free(rijeci[i]);
    }
    free(rijeci);

    return 0;
}
