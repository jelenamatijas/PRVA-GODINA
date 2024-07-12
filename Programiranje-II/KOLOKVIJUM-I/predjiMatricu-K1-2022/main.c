#include <stdio.h>
#include <stdlib.h>
/**Neka je data matrica dimenzija mxn.
Napisati rekurzivnu funkciju koja računa ukupan broj
putanja kojima se može doći od prve (0, 0) do
posljednje ćelije u matrici (m-1, n-1). Moguće putanje
za naredni korak su desno i dole u odnosu na početnu
ćeliju. Smatrati da iz posljednjeg reda (m-1) ili
posljednje kolone (n-1) postoji samo jedna putanja do
posljednje ćelije. Prototip funkcije je:
int countPaths(int currentRow, int
currentColumn, int m, int n)*/

int countPaths(int currentRow, int currentColumn, int m, int n)
{
    if(currentColumn == n-1)
    {
        if(currentRow != m-1)
        {
            return countPaths(currentRow+1, currentColumn, m, n);
        }
        else
        {
            return 1;
        }
    }
    else if(currentRow == m-1)
    {
        if(currentColumn != n-1)
        {
            return countPaths(currentRow, currentColumn+1, m, n);
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return countPaths(currentRow+1, currentColumn, m, n) + countPaths(currentRow, currentColumn+1, m, n);
    }
}

int countPaths2(int currentRow, int currentColumn, int m, int n) {
  if (currentRow == m - 1 || currentColumn == n - 1) {
    return 1;
  }

  int down = countPaths(currentRow + 1, currentColumn, m, n);
  int right = countPaths(currentRow, currentColumn + 1, m, n);

  return right + down;
}

int main()
{
    printf("Broj koraka: %d\n", countPaths(0,0,5,6));
    printf("Broj koraka: %d", countPaths2(0,0,5,6));
    return 0;
}
