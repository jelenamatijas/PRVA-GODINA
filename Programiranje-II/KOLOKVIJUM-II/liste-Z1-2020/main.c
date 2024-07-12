#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Neka je dat tip:
typedef struct node {
char *val;
struct node *next;
} NODE;
kojim se reprezentuje čvor jednostruko povezane liste
čiji je informacioni sadržaj string.
Neka je dat tip:
typedef struct double_node {
char *val;
struct double_node *left, *right;
} DOUBLE_NODE;
kojim se reprezentuje čvor dvostruko povezane liste čiji
je informacioni sadržaj string.
Napisati funkciju koja briše iz jednostruko povezane
liste (parametar node) sve čvorove koji ispunjavaju
određeni uslov. Funkcija kao rezultat vraća adresu
glave novokreirane dvostruko povezane liste u čije
čvorove je upisan informacioni sadržaj obrisanih
čvorova. Čvorovi za brisanje ispunjavaju uslov ukoliko
pokazivač na funkciju (parametar criteria) koji je
proslijeđen kao argument funkcije vraća vrijednost 1.
Prototip funkcije je:
DOUBLE_NODE* delete(NODE **node, int
(*criteria)(NODE *n))*/

typedef struct node
{
    char *val;
    struct node *next;
} NODE;

typedef struct double_node
{
    char *val;
    struct double_node *left, *right;
} DOUBLE_NODE;

int criteria(NODE *n)
{
    return strlen(n->val)<6;
}

DOUBLE_NODE* deleteNodes(NODE **node, int(*criteria)(NODE *n))
{
    NODE *pom = *node, *prev=0;
    DOUBLE_NODE *newList=0, *newTail=0;
    while(pom)
    {
        if(criteria(pom)==1)
        {
            DOUBLE_NODE *newNode = (DOUBLE_NODE*)calloc(1, sizeof(DOUBLE_NODE));
            newNode->val = (char*)calloc(strlen(pom->val)+1, sizeof(char));
            strcpy(newNode->val, pom->val);

            if(newList==NULL)newList = newTail=newNode;
            else
            {
                newTail->right = newNode;
                newNode->left = newTail;
                newTail = newNode;
            }


            if (prev == NULL) {
                *node = pom->next;
                free(pom->val);
                free(pom);
                pom = *node;
            } else {
                prev->next = pom->next;
                free(pom->val);
                free(pom);
                pom = prev->next;
            }
        } else {
            prev = pom;
            pom = pom->next;
        }
    }

    return newList;
}

//==============================================================

// Funkcija za dodavanje čvora na kraj jednostruko povezane liste
void append_node(NODE **head, const char *val)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->val = (char*)calloc(strlen(val) + 1, sizeof(char));
    if (newNode->val == NULL)
    {
        printf("Memory allocation for value failed.\n");
        free(newNode);
        return;
    }
    strcpy(newNode->val, val);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        NODE *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Funkcija za ispisivanje jednostruko povezane liste
void print_list(NODE *head)
{
    while (head != NULL)
    {
        printf("-> %s ", head->val);
        head = head->next;
    }
    printf("\n");
}

void print_Dlist(DOUBLE_NODE *head)
{
    while (head != NULL)
    {
        printf("-> %s ", head->val);
        head = head->right;
    }
    printf("\n");
}

// Funkcija za oslobađanje memorije alocirane za listu
void free_list(NODE *head)
{
    NODE *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->val);
        free(temp);
    }
}

void brisi_listu(DOUBLE_NODE **pglava)
{
    while (*pglava)
    {
        DOUBLE_NODE *p = (*pglava)->right;
        free(*pglava);
        *pglava = p;
    }
}


int main()
{
    NODE *head = NULL;
    char buffer[100];
    int choice;
    DOUBLE_NODE *glava=0;

    do
    {
        printf("\n1. Dodaj cvor\n");
        printf("2. Ispisi listu\n");
        printf("3. Kreiraj dvostruko povezanu listu:\n");
        printf("4. Izlaz\n");
        printf("Unesite vas izbor: ");
        scanf("%d", &choice);
        getchar(); // Ukloni newline karakter iz ulaza

        switch (choice)
        {
        case 1:
            printf("Unesite vrijednost za novi cvor: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0'; // Ukloni newline karakter
            append_node(&head, buffer);
            break;
        case 2:
            print_list(head);
            break;
        case 3:
            glava=deleteNodes(&head, criteria);
            print_Dlist(glava);
            break;
        case 4:
            printf("Izlaz...\n");
            break;
        default:
            printf("Neispravan izbor. Pokusajte ponovo.\n");
        }
    }
    while (choice != 4);

    // Oslobodi memoriju
    free_list(head);
    brisi_listu(&glava);
    return 0;
}

