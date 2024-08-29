#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Napisati program u kojem treba:
definisati tip ZAPOSLENI kojim se reprezentuje zaposleni u nekoj firmi (podaci koji se vode o zaposlenom su: matični broj, prezime, ime i plata),
definisati tip CVOR kojim se reprezentuje čvor dvostruko povezane liste,
definisati funkciju koja dodaje podatke o novom zaposlenom u listu tako da je poredak elemenata u listi uvijek u rastućem redoslijedu po matičnom broju,
definisati funkciju koja omogućava pretraživanje liste po matičnom broju,
definisati funkciju koja formatirano ispisuje podatke o svim zaposlenima,
definisati funkciju koja omogućava brisanje podataka o zaposlenom po matičnom broju,
definisati funkciju koja briše listu,
definisati funkciju koja omogućava učitavanje podataka o zaposlenom,
u glavnom programu prikazivati meni prema kojem korisnik može da vrši:
dodavanje podataka o novom zaposlenom,
ažuriranje podataka,
brisanje podataka,
prikaz podataka o svim zaposlenima,
pretraživanje podataka po matičnom broju.
*/

typedef struct zaposleni
{
    char mBroj[14], *ime, *prezime;
    float plata;
} ZAPOSLENI;

typedef struct cvor
{
    ZAPOSLENI info;
    struct cvor *lijevi, *desni;
} CVOR;

void ispis(CVOR *glava)
{
    printf("IME -------- PREZIME ---- MATICNI BROJ | PLATA\n");
    while(glava)
    {
        printf("%12s %12s %12s | %.2f\n", glava->info.ime, glava->info.prezime, glava->info.mBroj, glava->info.plata);
        glava = glava->desni;
    }
}

CVOR *trazi(CVOR *pglava, CVOR *prep, char *mBr)
{
    if(pglava == NULL)return 0;
    while(strcmp(pglava->info.mBroj, mBr)<0 && strcmp(prep->info.mBroj, mBr)>0)
    {
        pglava = pglava->desni;
        prep = prep->lijevi;
    }
    return strcmp(pglava->info.mBroj, mBr)==0?pglava:(strcmp(prep->info.mBroj, mBr)==0?prep:0);
}

void dodaj(CVOR **pglava, CVOR **prep, ZAPOSLENI *info)
{
    if(trazi(*pglava, *prep, info->mBroj)!=NULL)return;
    CVOR *novi = (CVOR *)calloc(1, sizeof(CVOR));
    novi->info.ime = (char *)calloc(strlen(info->ime) + 1, sizeof(char));
    strcpy(novi->info.ime, info->ime);
    novi->info.prezime = (char *)calloc(strlen(info->prezime) + 1, sizeof(char));
    strcpy(novi->info.prezime, info->prezime);
    strcpy(novi->info.mBroj, info->mBroj);
    novi->info.plata = info->plata;

    if(*pglava == 0)*pglava=*prep = novi;
    else if(strcmp((*pglava)->info.mBroj, info->mBroj)<0)
    {
        novi->desni = *pglava;
        (*pglava)->lijevi = novi;
        *pglava = novi;
    }
    else if(strcmp((*prep)->info.mBroj, info->mBroj)>0)
    {
        novi->lijevi = *prep;
        (*prep)->desni = novi;
        *prep = novi;
    }
    else
    {
        CVOR *p = *pglava;
        CVOR *q = (*prep)->lijevi;
        for(; strcmp(p->desni->info.mBroj,info->mBroj)<0 && strcmp(q->info.mBroj,info->mBroj)>0; p=p->desni, q=q->lijevi);

        if(strcmp(q->info.mBroj,info->mBroj)<0)p=q;
        novi->desni = p->desni;
        novi->lijevi = p;
        p->desni->lijevi = novi;
        p->desni = novi;
    }
}

void unesi_zaposlenog(ZAPOSLENI *z) {
    char ime[50], prezime[50];
    printf("Unesi ime, prezime, maticni broj i platu zaposlenog: \n");
    scanf("%s %s %s %f", ime, prezime, z->mBroj, &z->plata);
    z->ime = (char *)calloc(strlen(ime) + 1, sizeof(char));
    strcpy(z->ime, ime);
    z->prezime = (char *)calloc(strlen(prezime) + 1, sizeof(char));
    strcpy(z->prezime, prezime);
}

int brisi(CVOR **pglava, CVOR **prep, char *mBr)
{
    CVOR *obr = trazi(*pglava, *prep, mBr);
    if(obr==0)return 0;
    else if(*pglava == *prep == obr)*prep = *pglava = 0;
    else if(*pglava == obr)*pglava = (*pglava)->desni;
    else if(*prep == obr)*prep = (*prep)->lijevi;
    else
    {
        obr->lijevi->desni = obr->desni;
        obr->desni->lijevi = obr->lijevi;
    }
    free(obr);
    return 1;
}

void brisi_listu(CVOR **pglava, CVOR **prep)
{
    while(*pglava)
    {
        CVOR *p = (*pglava)->desni;
        free((*pglava)->info.ime);
        free((*pglava)->info.prezime);
        free((*pglava)->info.mBroj);
        free(*pglava);
        *pglava = p;
    }
    *pglava = *prep = 0;
}

int main()
{
    CVOR *glava = 0, *rep = 0;
    char c, jmb[14];
    ZAPOSLENI z;
    do
    {
        printf("======================================================================\n");
        printf("Dodavanje/azur. [D], brisanje [B], prikaz [P], pretr. [T], kraj [0]? ");
        scanf("\n%c", &c);
        if (c == 'D')
        {
            printf("  Unesite podatke:\n");
            unesi_zaposlenog(&z);
            CVOR *p = trazi(glava, rep, z.mBroj);
            if (p) p->info = z;
            else dodaj(&glava, &rep, &z);
        }
        else if (c == 'B')
        {
            printf("  Maticni broj: ");
            scanf("%s", jmb);
            if (brisi(&glava, &rep, jmb))
                printf("  Obrisani su podaci o zaposlenom sa maticnim brojem %s.\n", jmb);
            else printf("  Nema podataka o zaposlenom sa maticnim brojem %s.\n", jmb);
        }
        else if (c == 'P') ispis(glava);
        else if (c == 'T')
        {
            printf("  Maticni broj: ");
            scanf("%s", jmb);
            CVOR *p = trazi(glava, rep, jmb);
            if (p) printf("  %s, %s ima platu %.2f.\n", p->info.prezime, p->info.ime, p->info.plata);
            else printf("  Nema podataka o zaposlenom sa maticnim brojem %s.\n", jmb);
        }
        else if (c != '0') printf("  Nepoznata opcija - '%c'.\n", c);
    }
    while (c != '0');
    brisi_listu(&glava, &rep);
    printf("KRAJ!\n");
    return 0;
}

