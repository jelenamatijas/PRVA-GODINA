#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Neka je dat tip:
typedef struct film {
 char naziv[64];
 char zanr[16];
 char reziser[32];
 char glumci[512];
 int godina;
} FILM;
Potrebno je definisati tip CVOR kojim se reprezentuje čvor stabla binarne pretrage, kod kojeg je
informacioni sadržaj podatak tipa FILM.
Neophodno je implementirati sljedeće funkcije za binarno stablo pretrage:
• dodavanje podataka o novom filmu u binarno stablo pretrage, tako da je kriterijum pri
dodavanju novog filma u stablo naziv filma (ukoliko film sa navedenim nazivom već postoji u
binarnom stablu pretrage vrši se ažuriranje svih atributa postojećeg sa vrijednostima novog
filma),
• pretraživanje binarnog stabla pretrage po nazivu filma (ukoliko čvor sa određenim nazivom
filma ne postoji u binarnom stablu pretrage vratiti vrijednost 0, a u suprotnom vratiti adresu
informacionog sadržaja tj. filma koji odgovara po nazivu),
• brisanje čvora binarnog stabla pretrage po nazivu filma (ukoliko čvor sa određenim nazivom
filma ne postoji u binarnom stablu pretrage vratiti vrijednost 0, a u suprotnom vratiti vrijednost
1 ukoliko je čvor uspješno obrisan),
• formatirani ispis podataka o svim filmovima na standardni izlaz, ali tako da su filmovi sortirani
po nazivu u rastućem redoslijedu,
• brisanje svih čvorova binarnog stabla pretrage.
Korisniku se u glavnom programu prikazuje meni putem kojeg može da testira rad prethodno navedenih
funkcionalnosti.
Napomena: naziv filma može biti case insensitive (pri tome nazivi “Artificial Intelligence” i
“ARTIFICIAL INTELLIGENCE” predstavljaju isti naziv filma).*/

typedef struct film {
 char naziv[64];
 char zanr[16];
 char reziser[32];
 char glumci[512];
 int godina;
} FILM;

typedef struct node {
    struct node *left, *right;
    FILM info;
}NODE;

NODE *new_node(FILM *info){
    NODE *newNode = (NODE*)calloc(1, sizeof(NODE));
    newNode->info = *info;
    return newNode;
}

NODE *add(NODE *root, FILM *info){
    if (root == NULL) return new_node(info);
    if (strcasecmp(root->info.naziv, info->naziv) == 0) root->info = *info;
    else if (strcasecmp(root->info.naziv, info->naziv) < 0) root->right = add(root->right, info);
    else root->left = add(root->left, info);
    return root;
}

FILM *search(NODE *root, const char name[]) {
    if (root == NULL) return NULL;
    if (strcasecmp(root->info.naziv, name) == 0) return &(root->info);
    if (strcasecmp(root->info.naziv, name) > 0) return search(root->left, name);
    else return search(root->right, name);
}

NODE *max(NODE *root){
    while (root->right != NULL) root = root->right;
    return root;
}

NODE *del(NODE *root, const char name[]){
    if (root == NULL) return NULL;
    if (strcasecmp(root->info.naziv, name) > 0) root->left = del(root->left, name);
    else if (strcasecmp(root->info.naziv, name) < 0) root->right = del(root->right, name);
    else {
        if (root->left == NULL) {
            NODE *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        NODE *temp = max(root->left);
        root->info = temp->info;
        root->left = del(root->left, temp->info.naziv);
    }
    return root;
}

int delete_node(NODE **root, const char name[]){
    if (*root == NULL) return 0;
    FILM *f = search(*root, name);
    if (f == NULL) return 0;
    *root = del(*root, name);
    return 1;
}

void inorder(NODE *root){
    if (root != NULL){
        inorder(root->left);
        printf("%s - %s - %s - %s - %d\n", root->info.naziv, root->info.zanr, root->info.reziser, root->info.glumci, root->info.godina);
        inorder(root->right);
    }
}

void delete_bst(NODE *root){
    if (root != NULL){
        delete_bst(root->left);
        delete_bst(root->right);
        free(root);
    }
}

void print_menu() {
    printf("1. DODAJ\n");
    printf("2. PRETRAZI\n");
    printf("3. OBRISI FILM\n");
    printf("4. PRIKAZI\n");
    printf("5. OBRISI STABLO\n");
    printf("0. KRAJ\n");
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    NODE *root = NULL;
    int choice;
    FILM film = {};
    char name[64];
    int deleted = 0;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Ime filma: ");
                fgets(film.naziv, sizeof(film.naziv), stdin);
                remove_newline(film.naziv);
                printf("Zanr filma: ");
                fgets(film.zanr, sizeof(film.zanr), stdin);
                remove_newline(film.zanr);
                printf("Reziser filma: ");
                fgets(film.reziser, sizeof(film.reziser), stdin);
                remove_newline(film.reziser);
                printf("Glumci: ");
                fgets(film.glumci, sizeof(film.glumci), stdin);
                remove_newline(film.glumci);
                printf("Godina proizvodnje: ");
                scanf("%d", &film.godina);
                getchar(); // Consume newline character

                root = add(root, &film);
                break;
            case 2:
                printf("Koji film trazis: ");
                fgets(name, sizeof(name), stdin);
                remove_newline(name);
                FILM *found = search(root, name);
                if (found) {
                    printf("Pronadjeni film: %s - %s - %s - %s - %d\n", found->naziv, found->zanr, found->reziser, found->glumci, found->godina);
                } else {
                    printf("Film nije pronadjen.\n");
                }
                break;
            case 3:
                printf("Koji film zelis brisati: ");
                fgets(name, sizeof(name), stdin);
                remove_newline(name);
                deleted = delete_node(&root, name);
                if (deleted) {
                    printf("Film je obrisan.\n");
                } else {
                    printf("Film nije pronadjen.\n");
                }
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                delete_bst(root);
                root = NULL;
                printf("Svi filmovi su obrisani.\n");
                break;
            case 0:
                delete_bst(root);
                root = NULL;
                printf("KRAJ...\n");
                break;
            default:
                printf("Netacan unos.\n");
        }
    } while (choice != 0);
    delete_bst(root);
    return 0;
}
