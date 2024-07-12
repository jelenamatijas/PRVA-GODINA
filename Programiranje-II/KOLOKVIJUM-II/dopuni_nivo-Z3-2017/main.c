#include <stdio.h>
#include <stdlib.h>

/**Neka je definisan tip:
typedef struct cvor{
int info, nivo;
struct cvor *lijevi, *desni;
} CVOR;
Napisati funkciju koja ima sljededi prototip:
void dopuni_nivo (CVOR *korijen, int nivo);
Funkcija treba da dopuni nivo binarnog stabla, pri čemu je prvi argument funkcije korijen stabla a drugi argument nivo koji je potrebno
dopuniti. Potrebno je dodati maksimalan broj čvorova u dati nivo, tako da svi čvorovi iz prethodnog nivoa imaju stepen 2. Informacioni sadržaj
svakog novog čvora treba da bude jednak informacionom sadržaju njegovog roditelja.*/

typedef struct cvor{
int info, nivo;
struct cvor *lijevi, *desni;
} CVOR;

CVOR* novi_cvor(int info, int nivo) {
  CVOR *novi = (CVOR *)malloc(sizeof(CVOR));
  novi->lijevi = novi->desni = 0;
  novi->info = info;
  novi->nivo = nivo;
  return novi;
}
CVOR* dodaj_lijevi(CVOR *cvor, int info, int nivo) {
  CVOR *novi = novi_cvor(info, nivo);
  if (cvor->lijevi) { novi->lijevi = cvor->lijevi; }
  cvor->lijevi = novi;
  return novi;
}
CVOR* dodaj_desni(CVOR *cvor, int info, int nivo) {
  CVOR *novi = novi_cvor(info, nivo);
  if (cvor->desni) { novi->desni = cvor->desni; }
  cvor->desni = novi;
  return novi;
}

void brisi_stablo(CVOR *korijen) {
  if (korijen != 0)
  { brisi_stablo(korijen->lijevi); brisi_stablo(korijen->desni); free(korijen); }
}

void inorder(CVOR *korijen) {
  if (korijen != 0) {
    inorder(korijen->lijevi);
    printf(" %d", korijen->info);
    inorder(korijen->desni);
  }
}

void dopuni_nivo (CVOR *korijen, int nivo){
    if(korijen->nivo < nivo){
        ///printf("%d %d\n", korijen->info, korijen->nivo);
        if(!korijen->lijevi){
            korijen->lijevi = (CVOR*)calloc(1, sizeof(CVOR));
            korijen->lijevi->info = korijen->info;
            korijen->lijevi->nivo = korijen->nivo+1;
        }
        if(!korijen->desni){
            korijen->desni = (CVOR*)calloc(1, sizeof(CVOR));
            korijen->desni->info = korijen->info;
            korijen->desni->nivo = korijen->nivo+1;
        }

        dopuni_nivo(korijen->lijevi, nivo);
        dopuni_nivo(korijen->desni, nivo);
    }

}

int main()
{
    CVOR *root = novi_cvor(1,1);
    CVOR *c = dodaj_lijevi(root, 2, 2);
    dodaj_lijevi(dodaj_desni(dodaj_lijevi(c, 5, 3), 6, 4), 10, 5);
    CVOR *c1=dodaj_desni(root, 3, 2);
    CVOR *c2=dodaj_lijevi(c1, 4, 3);
    dodaj_lijevi(c2, 7, 4);
    dodaj_desni(dodaj_desni(c2, 8, 4), 9, 5);


    inorder(root);printf("\n");

    dopuni_nivo(root, 3);
    inorder(root);printf("\n");

    dopuni_nivo(root, 5);
    inorder(root);

    brisi_stablo(root);
    return 0;
}
