#include <stdio.h>
#include <stdlib.h>
/**Napisati program u kojem treba iz datoteke, čiji je naziv prvi argument komandne linije, pročitati podatke o
nepoznatom broju studenata, i formirati odgovarajući dinamički niz, a zatim učitani niz podataka o studentima upisati,
sortirano opadajuće prema broju bodova, u datoteku čiji je naziv drugi argument komandne linije. Podaci koji se vode o studentu su:
indeks, ime, prezime i broj bodova (na ispitu).
*/

typedef struct student
{
    char ime[21];
    char prezime[21];
    char indeks[10];
    double bodovi;
} STUDENT;

int student_cmp(STUDENT *s1, STUDENT *s2)
{
    if(s1->bodovi>s2->bodovi) return 1;
    if(s1->bodovi<s2->bodovi)return -1;
    return 0;
}

void merge_sort(STUDENT *studenti, int begin, int end)
{
    if(begin<end)
    {
        int sredina = (begin+end)/2, i, j, k, len = (end-begin)+1;

        STUDENT *pom = (STUDENT*)calloc(sizeof(STUDENT), len);

        merge_sort(studenti, begin, sredina);
        merge_sort(studenti, sredina+1, end);

        i=begin, j=sredina+1, k=0;
        while(i<=sredina && j<=end)
        {
            pom[k++]=(student_cmp(&studenti[i], &studenti[j])==1)?studenti[i++]:studenti[j++];
        }
        while(i<=sredina)
            pom[k++] = studenti[i++];
        while(j<=end)
            pom[k++] = studenti[j++];
        for(i=0; i<len; i++)
        {
            studenti[begin+i] = pom[i];
        }
        free(pom);
    }
}

void insertion_sort(STUDENT studenti[], int n)
{
    for(int i=1; i<n; i++)
    {
        STUDENT s = studenti[i];
        int j;
        for(j=i; j>0 && (student_cmp(&s, &studenti[j-1])==1); j--)
        {
            studenti[j]=studenti[j-1];
        }
        studenti[j] = s;
    }
}

void bubble_sort(STUDENT s[], int n)
{
    int i, j;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(student_cmp(&s[j],&s[j+1])==-1)
            {
                STUDENT pom = s[j];
                s[j]=s[j+1];
                s[j+1] = pom;
            }
        }
    }
}


void shell_sort(STUDENT s[], int n)
{
    int i, j, h;
    for(h=n; h>0; h/=2)
    {
        for(i=h; i<n; i++)
        {
            STUDENT pom = s[i];
            for(j=i; j>=h && (student_cmp(&s[j], &s[j-1])==1); j-=h)
            {
                s[j]=s[j-h];
            }
            s[j]=pom;
        }
    }
}

int split(STUDENT studenti[], int begin, int end)
{
    int i=begin, j=end;
    STUDENT pivot = studenti[begin];
    while(i<j)
    {
        while(((student_cmp(&studenti[i], &pivot)==1) || (student_cmp(&studenti[i], &pivot)==0))&& i<j)i++;
        while(student_cmp(&studenti[j], &pivot)==-1)j--;
        if(i<j)
        {
            STUDENT pom = studenti[i];
            studenti[i]=studenti[j];
            studenti[j]=pom;
        }
    }
    studenti[begin]=studenti[j];
    studenti[j]=pivot;
    return j;
}

void quick_sort(STUDENT s[], int begin, int end)
{
    if(begin<end)
    {
        int pivot = split(s, begin, end);
        quick_sort(s, begin, pivot);
        quick_sort(s, pivot+1, end);
    }
}

int main(int argc, char*argv[])
{
    /**FILE *f = fopen("STUDENTI.dat", "wb");
    for(int i=0;i<4;i++){
        STUDENT s;
        scanf("%s %s %s %lf", &s.indeks,&s.ime, &s.prezime, &s.bodovi);
        fprintf(f, "%s %s %s %lf", s.indeks, s.ime, s.prezime, s.bodovi);
    }*/
    if(argc<3)
    {
        printf("Greska!\n");
        return -1;
    }

    FILE *file1, *file2;
    file1=fopen(argv[1], "rb");
    file2=fopen(argv[2], "wb");

    if(!file1 || !file2)
    {
        printf("Greska!\n");
        return -2;
    }

    fseek(file1, 0, SEEK_END);
    int brStudenata = ftell(file1)/sizeof(STUDENT);
    rewind(file1);

    STUDENT *studenti=(STUDENT*)calloc(sizeof(STUDENT), brStudenata);
    int i=0;
    while(i<brStudenata && fread(&studenti[i], sizeof(STUDENT), 1, file1))
    {
        i++;
    }

    ///merge_sort(studenti, 0, brStudenata-1);
    ///insertion_sort(studenti, brStudenata);
    ///bubble_sort(studenti, brStudenata);
    ///shell_sort(studenti, brStudenata);
    quick_sort(studenti, 0, brStudenata-1);
    for(int i=0; i<brStudenata; i++)
    {
        fwrite(&studenti[i], sizeof(STUDENT), 1, file2);
    }

    free(studenti);
    fclose(file1);
    fclose(file2);

    return 0;
}
