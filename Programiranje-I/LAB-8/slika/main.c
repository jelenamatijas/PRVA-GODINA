#include <stdio.h>
#include <stdlib.h>
/*. Napisati program koji manipuliše slikom u rasterskoj grafici. Slika se predstavlja kao kvadratna matrica
piksela, dimenzije n (n < 10), pri čemu se svaki piksel sastoji od odgovarajuće tri komponente – R (crvena
komponenta), G (zelena komponenta) i B (plava komponenta). Učitati jednu sliku, pa je ispisati u vidu matrice
piksela, pri čemu vrijednost svakog piksela treba ispisati kao heksadecimalni triplet njegovih komponenti (npr.
bijeli piksel je #ffffff, t.j. R = G = B = 255). Slika se učitava tako što se za svaki piksel učitavaju sve tri
komponente (0 ≤ R, G, B ≤ 255).
*/
int main()
{
    int n;
    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    }
    while(n<1 || n>=10);
    int slika[n][n][3];
    printf("Unesi sliku: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int r,g,b;
            do
            {
                printf("piksel(%d,%d) - R = ", i,j);
                scanf("%d", &r);
                printf("piksel(%d,%d) - G = ", i,j);
                scanf("%d", &g);
                printf("piksel(%d,%d) - B = ", i,j);
                scanf("%d", &b);
            }
            while(r<0 || b<0 || g<0 || r>255 || g>255 || b>255);
            slika[i][j][0]=r;
            slika[i][j][1]=g;
            slika[i][j][2]=b;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("#%02x%02x%02x ",slika[i][j][0],slika[i][j][1],slika[i][j][2]);
        }
        printf("\n");
    }
    return 0;
}
