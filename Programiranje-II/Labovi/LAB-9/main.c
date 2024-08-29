#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Neka je dat tip:
typedef struct node {
 char str[100]; // informacioni sadrzaj
 struct node *left, *right;
} NODE;
kojim se reprezentuje čvor binarnog stabla.
Napisati funkciju koja ispisuje sadržaj stabla (u jednom redu, bez razdvajanja stringova) u preorder
redoslijedu obilaska, a čiji je prototip:
void preorder(NODE *root);
Napisati funkciju koja ispisuje sadržaj stabla (u jednom redu, bez razdvajanja stringova) u inorder
redoslijedu obilaska, a čiji je prototip:
void inorder(NODE *root);
Napisati funkciju koja ispisuje sadržaj stabla (u jednom redu, bez razdvajanja stringova) u postorder
redoslijedu obilaska, a čiji je prototip:
void postorder(NODE *root);
Napisati funkciju koja briše stablo, a čiji je prototip:
void delete(NODE *root);
Napisati glavnu funkciju u kojoj treba kreirati binarno stablo prikazano na sljedećoj slici (informacioni
sadržaj čvora prikazan je unutar čvora), a zatim ispisati sadržaj kreiranog binarnog stabla u preorder,
inorder i postorder redoslijedu obilaska*/

typedef struct node
{
    char str[100]; // informacioni sadrzaj
    struct node *left, *right;
} NODE;

NODE* newNode(char str[100])
{
    NODE *new_node = (NODE*)calloc(sizeof(NODE), 1);
    strcpy(new_node->str, str);
    return new_node;
}

NODE *addLeft(NODE *node, char str[100])
{
    NODE *new_node = (NODE*)calloc(sizeof(NODE), 1);
    strcpy(new_node->str, str);
    if(node->left)new_node->left = node->left;
    node->left = new_node;
    return new_node;
}

NODE *addRight(NODE *node, char str[100])
{
    NODE *new_node = (NODE*)calloc(1,sizeof(NODE));
    strcpy(new_node->str, str);
    if(node->right)new_node->right = node->right;
    node->right = new_node;
    return new_node;
}

void preorder(NODE *root)
{
    if(root!=0)
    {
        printf("%s", root->str);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root)
{
    if(root!=0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%s", root->str);
    }
}

void inorder(NODE *root)
{
    if(root!=0)
    {
        inorder(root->left);
        printf("%s", root->str);
        inorder(root->right);
    }
}

void delete_bt(NODE *root)
{
    if(root!=0)
    {
        delete_bt(root->left);
        delete_bt(root->right);
        free(root);
    }
}


int main()
{
    NODE *root=newNode("A");
    NODE *c1 = addLeft(root, "B");
    NODE *c2 = addRight(root, "C");
    c2 = addRight(c2, "F");
    addLeft(c2, "I");
    c2 = addLeft(c1, "D");
    addLeft(c2, "G");
    c1 = addRight(c1, "E");
    c1 = addRight(c1, "H");
    addLeft(c1, "J");

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    delete_bt(root);

    return 0;
}
