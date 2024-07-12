#include <stdio.h>
#include <stdlib.h>
/**Napisati program u kojem treba učitati podatke za n tačaka i formirati odgovarajući dinamički niz, a zatim učitani niz tačaka
ispisati u rastućem redoslijedu pri čemu se niz tačaka sortira po x koordinati (ukoliko dvije tačke imaju istu x koordinatu, u obzir uzeti y
koordinatu).*/

typedef struct tacka
{
    double x, y;
} TACKA;

int tacka_cmp(TACKA const *t1, TACKA const *t2)
{
    if(t1->x < t2->x)
        return 1;
    else if(t1->x > t2->x)
        return -1;
    else if(t1->x == t2->x)
    {
        if(t1->y < t2->y)
            return 1;
        else if(t1->y > t2->y)
            return -1;
        else
            return 0;
    }
}

void merge_sort(TACKA tacke[], int begin, int end)
{
    int sredina = (begin+end)/2, i,j,k,len=end-begin+1;
    TACKA *pom = (TACKA*)calloc(sizeof(TACKA), len);
    if(begin<end)
    {
        merge_sort(tacke, begin, sredina);
        merge_sort(tacke, sredina+1, end);

        i=begin, j=sredina+1, k=0;
        while(i<=sredina && j<=end)
        {
            pom[k++] = (tacka_cmp(&tacke[i], &tacke[j])==-1)?tacke[i++]:tacke[j++];
        }
        while(i<=sredina)
            pom[k++] = tacke[i++];
        while(j<=end)
            pom[k++] = tacke[j++];
        for(i=0; i<len; i++)
            tacke[begin+i] = pom[i];
        free(pom);
    }
}

void selection_sort(TACKA tacke[], int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        for(min=i,j=i+1;j<n;j++){
            if(tacka_cmp(&tacke[min],&tacke[j])==-1)min=j;
        }
        if(min!=i){
            TACKA pom=tacke[min];
            tacke[min]=tacke[i];
            tacke[i]=pom;
        }
    }
}

int main()
{
    int n;
    printf("Unesi n: ");
    scanf("%d", &n);
    TACKA tacke[n];
    for(int i=0; i<n; i++)
    {
        printf("Tacka %d: ",i+1);
        scanf("%lf%lf", &tacke[i].x, &tacke[i].y);
    }
    ///merge_sort(tacke, 0, n-1);
    ///selection_sort(tacke, n);
    for(int i=0; i<n; i++)
    {
        printf("Tacka %d: %lf %lf\n",i+1, tacke[i].x, tacke[i].y);
    }
    return 0;
}
