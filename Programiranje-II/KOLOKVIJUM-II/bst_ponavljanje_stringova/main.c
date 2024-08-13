/**#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cvor{
    char *str; // dinamički string
    int br; // broj ponavljanja
    struct cvor *lijevi, *desni;
}CVOR;

typedef struct bst{
    CVOR *korijen; // korijen BST-a
}BST;

void dodaj(BST *bst,char *str)
{
   if(bst->korijen==NULL)
   {
       bst->korijen->str=str;
       bst->korijen->lijevi=bst->korijen->desni=0;
       bst->korijen->br=0;
   }
   if(strcmp(str,bst->korijen)<0)
       bst->korijen->lijevi=dodaj(bst->korijen->lijevi,str);
   else if(strcmp(str,bst->korijen)>0)
        bst->korijen->desni=dodaj(bst->korijen->desni,str);
   else
    bst->korijen->br++;

}
void ispis(BST *bst)
{
   while(bst->korijen)
   {
       ispis(bst->korijen.lijevi);
       printf("String: %s, broj ponavljanja: %d\n",bst->korijen.str,bst->korijen.br);
       ispis(bst->korijen.desni);
   }
}
int main()
{
    BST *bst={NULL};

    dodaj(bst,"stablo");
    dodaj(bst,"binarne");
    dodaj(bst,"pretrage");
    dodaj(bst,"stablo");

    ispis(bst);

    return 0;
}*/

///////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor{
    char *str; // dinamički string
    int br; // broj ponavljanja
    struct cvor *lijevi, *desni;
}CVOR;

/**typedef struct bst{
    CVOR *korijen; // korijen BST-a
}BST;*/

CVOR *dodaj(CVOR *bst,char *str)
{
   if(bst==NULL)
   {
       bst = (CVOR*)calloc(sizeof(CVOR), 1);
       bst->str=(char*)calloc(sizeof(char), strlen(str)+1);
       strcpy(bst->str, str);
       bst->lijevi=bst->desni=0;
       bst->br=1;
   }
   else if(strcmp(str,bst->str)<0)
       bst->lijevi=dodaj(bst->lijevi,str);
   else if(strcmp(str,bst->str)>0)
        bst->desni=dodaj(bst->desni,str);
   else
        bst->br++;

    return bst;
}
void ispis(CVOR *bst)
{
   if(bst)
   {
       ispis(bst->lijevi);
       printf("String: %s, broj ponavljanja: %d\n",bst->str,bst->br);
       ispis(bst->desni);
       free(bst->str);
       free(bst);
   }
}
int main()
{
    CVOR *bst=0;
    bst=dodaj(bst,"stablo");
    dodaj(bst,"binarne");
    dodaj(bst,"pretrage");
    dodaj(bst,"stablo");

    ispis(bst);

    return 0;
}
