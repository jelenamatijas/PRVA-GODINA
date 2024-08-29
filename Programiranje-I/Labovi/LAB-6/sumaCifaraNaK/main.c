#include <stdio.h>
#include <stdlib.h>
/*Napisati program (bez korištenja funkcija iz math.h) koji učitava prirodan broj b, a zatim ispisuje vrijednost
sljedeće sume: Na primjer, vrijednost tražene sume
za broj 2534 je 154 (2^4+ 5^3+ 3^2+ 4^1= 16 + 125 + 9 + 4 = 154).*/
int main()
{
    /*  int b, sum=0;
      do
      {
          printf("Unesi prirodan broj:");
          scanf("%d", &b);
      }
      while(b<1);

      for(int i=1; b>0; i++, b/=10)
      {
          int p=b%10;
          for(int j=1; j<i; j++)
          {
              p*=b%10;
          }
          sum+=p;
      }
      printf("Trazena suma iznosi: %d.", sum);
      return 0;

    */
/*
    int b, bi, s=0, i=0, k=0; //bi je cifra na poziciji i broja b koji ima k cifara
    do
    {
        printf ("Unesi prirodan broj b: ");
        scanf ("%d", &b);
    }
    while (b<1);

    int temp=b;

    while (temp>0)
    {
        bi=temp%10; // cifra na i-toj poziciji u prvoj iteraciji i=0
        int stepen=1; // trazi se i-ti stepen broja 2
        for (k=1; k<=i; k++)
        {
            stepen*=2;
        }
        s+=stepen*bi;
        temp/=10;
        i++;

    }

    printf("Trazena suma broja %d je: %d\n", b, s);*/

    int b, bi, s=0, i, k=0; //bi je cifra na poziciji i broja b koji ima k cifara
    do
    {
        printf ("Unesi prirodan broj b: ");
        scanf ("%d", &b);
    } while (b<1);

    int temp=b;

    while (temp>0)
    {
        bi=temp%10;
        int stepen=bi; // ovo neka bude stepen, nekako je logicnije na prvu kad se vidi
        for (i=0; i<=k-1; i++)
        {
            stepen*=bi;
        }
        s+=stepen;
        temp/=10;
        k++;

    }

    printf("Trazena suma broja %d je: %d\n", b, s);


    return 0;
}
