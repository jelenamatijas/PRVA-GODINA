#include <stdio.h>
#include <stdlib.h>

/**Neka je dat tip:
typedef struct node {
int info;
struct node *left, *right;
} NODE;
kojim se reprezentuje čvor binarnog stabla, čiji je
informacioni sadržaj cijeli broj.
Napisati rekurzivnu funkciju koja provjerаva da li
je zadato binarno stablo (parametar root) stablo
binarnog pretraživanja. Funkcija treba da vrati 1
ako jeste stablo binarnog pretraživanja, a 0 ako
nije stablo binarnog pretraživanja.
Prototip funkcije je:
int is_bst(NODE *root);*/

typedef struct node
{
    int info;
    struct node *lijevi, *desni;
} NODE;

NODE* novi_cvor(int info)
{
    NODE *novi = (NODE *)malloc(sizeof(NODE));
    novi->lijevi = novi->desni = 0;
    novi->info = info;
    return novi;
}
NODE* dodaj_lijevi(NODE *cvor, int info)
{
    NODE *novi = novi_cvor(info);
    if (cvor->lijevi)
    {
        novi->lijevi = cvor->lijevi;
    }
    cvor->lijevi = novi;
    return novi;
}
NODE* dodaj_desni(NODE *cvor, int info)
{
    NODE *novi = novi_cvor(info);
    if (cvor->desni)
    {
        novi->desni = cvor->desni;
    }
    cvor->desni = novi;
    return novi;
}

void brisi_stablo(NODE *korijen)
{
    if (korijen != 0)
    {
        brisi_stablo(korijen->lijevi);
        brisi_stablo(korijen->desni);
        free(korijen);
    }
}

int maxValue(NODE* node)
{
    if (node == NULL) {
        return -1000000000;
    }

    int leftMax = maxValue(node->lijevi);
    int rightMax = maxValue(node->desni);

    int value = 0;
    if (leftMax > rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }

    if (value < node->info) {
        value = node->info;
    }

    return value;
}

int minValue(NODE* node)
{
    if (node == NULL) {
        return 1000000000;
    }

    int leftMax = minValue(node->lijevi);
    int rightMax = minValue(node->desni);

    int value = 0;
    if (leftMax < rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }

    if (value > node->info) {
        value = node->info;
    }

    return value;
}


int isBST(NODE *node)
{
    if (node == NULL)
        return 1;

    /* false if the max of the left is > than us */
    if (node->lijevi != NULL
        && maxValue(node->lijevi) > node->info)
        return 0;

    /* false if the min of the right is <= than us */
    if (node->desni != NULL
        && minValue(node->desni) < node->info)
        return 0;

    /* false if, recursively, the left or right is not a BST
     */
    if (!isBST(node->lijevi) || !isBST(node->desni))
        return 0;

    /* passing all that, it's a BST */
    return 1;
}


int main()
{
    NODE *root = novi_cvor(6);
    NODE *c1 = dodaj_desni(root, 10);
    dodaj_desni(c1, 11);
    dodaj_lijevi(c1, 7);
    c1 = dodaj_lijevi(root, 3);
    dodaj_desni(c1, 4);
    dodaj_lijevi(c1, 11);
    if(isBST(root))printf("Jeste stablo binarne pretrage.\n");
    else printf("Nije stablo binarne pretrage.\n");
    brisi_stablo(root);
    return 0;
}
