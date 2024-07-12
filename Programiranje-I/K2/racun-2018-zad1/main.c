#include <stdio.h>
#include <stdlib.h>
/*Neka su (u programskom jeziku C) definisani tipovi:
typedef struct roba {
int id; // jedinstveni identifikator robe
char naziv[20];
double kolicina; // ukupna kol. u prodavnici
double cijena;
} ROBA;
kojim se reprezentuje roba u nekoj prodavnici,
typedef struct racun_stavka {
int id; // identifikator robe
double kolicina; // prodata kolicina
} RACUN_STAVKA;
kojim se reprezentuje stavka robe na računu,
typedef struct racun {
int br; // trenutni broj stavki
RACUN_STAVKA *stavke; // dinamicki niz
} RACUN;
kojim se reprezentuje račun.
Napisati funkciju koja učitava i dodaje novu (jednu)
stavku na račun. Funkcija prima parametre: r - račun
na koji treba dodati novu stavku, roba - niz podataka
o trenutnoj robi u prodavnici, n - broj elementata niza
roba. Prilikom dodavanja nove stavke na račun,
korisnik unosi identifikator robe i količinu (količina>0),
a funkcija zatim provjerava da li u prodavnici postoji
roba sa datim identifikatorom, kao i da li postoji
dovoljna količina robe. Ako u prodavnici postoji roba u
dovoljnoj količini, tada na račun treba dodati novu
stavku i pri tome umanjiti količinu date robe u
prodavnici. U suprotnom, ignorisati pokušaj dodavanja
učitane stavke na račun. Funkcija vraća informaciju o
tome da li je nova stavka dodana na račun (0 - nije
dodana, 1 - jeste dodana). Prototip funkcije je:
int dodaj(RACUN *r, ROBA *roba, int n);
Napisati funkciju koja sortira stavke na računu
opadajuće po ukupnoj cijeni stavke (prodata količina *
cijena). Prototip funkcije je:
void sort(RACUN *r, ROBA *roba, int n);
Napisati funkciju koja izračunava i vraća ukupnu cijenu
računa (ukupna cijena svih stavki na računu). Prototip
funkcije je:
double ukupno(RACUN *r, ROBA *roba, int n);*/

typedef struct roba
{
    int id; // jedinstveni identifikator robe
    char naziv[20];
    double kolicina; // ukupna kol. u prodavnici
    double cijena;
} ROBA;

typedef struct racun_stavka
{
    int id; // identifikator robe
    double kolicina; // prodata kolicina
} RACUN_STAVKA;

typedef struct racun
{
    int br; // trenutni broj stavki
    RACUN_STAVKA *stavke; // dinamicki niz
} RACUN;

int dodaj(RACUN *r, ROBA *roba, int n);
void sort(RACUN *r, ROBA *roba, int n);
double ukupno(RACUN *r, ROBA *roba, int n);

int main()
{
    ROBA r[3] =
    {
        {1, "Jabuke", 50.5, 1.95},
        {2, "Kruske", 49.2, 2.10},
        {3, "Mlijeko", 126, 2.39}
    };
    int brStavki;
    printf("Koliko stavki unosite na racun: ");
    scanf("%d", &brStavki);
    RACUN rac = {0};
    for(int i=0; i<brStavki; i++)
    {
        printf("%s\n\n", (dodaj(&rac, &r, 3)? "STAVKA DODANA.":"NE POSTOJI POTREBNA ROBA."));
    }
    sort(&rac, &r, 3);
    for(int i=0; i<rac.br; i++)
    {
        printf("%lf, %lf\n ", r[rac.stavke[i].id-1].cijena, rac.stavke[i].kolicina);
    }
    free(rac.stavke);
    rac.stavke=NULL;
    return 0;
}

int dodaj(RACUN *r, ROBA *roba, int n)
{
    int id;
    double kol;
    printf("UNESI STAVKU:\n");
    printf("Unesi id robe: ");
    scanf("%d", &id);
    printf("Unesi kolicinu: ");
    scanf("%lf", &kol);
    for(int i=0; i<n; i++)
    {
        if(roba[i].id==id && roba[i].kolicina>0 && roba[i].kolicina>=kol && kol>0)
        {
            if(r->br==0)
            {
                r->stavke = (RACUN_STAVKA*)malloc(sizeof(RACUN_STAVKA));
                r->br++;
            }
            else
            {
                r->br++;
                RACUN_STAVKA *rac_st = (RACUN_STAVKA*)malloc(sizeof(RACUN_STAVKA)*r->br);
                for(int j=0; j<r->br-1; j++)
                {
                    rac_st[j]=r->stavke[j];
                }
                free(r->stavke);
                r->stavke=rac_st;
            }
            r->stavke[r->br-1].id = id;
            r->stavke[r->br-1].kolicina = kol;
            roba->kolicina-=kol;
            return 1;
        }
    }
    return 0;
}

void sort(RACUN *r, ROBA *roba, int n)
{
    for(int i=0; i<r->br-1; i++)
    {
        for(int j=i+1; j<r->br; j++)
        {
            double c1,c2;
            int idi, idj;
            for(int k=0; k<n; k++)
            {
                if(roba[i].id==k)
                {
                    idi = roba[i].id;
                }
                if(roba[j].id==k)
                {
                    idj = roba[i].id;
                }
            }
            c1 = r->stavke[i].kolicina*roba[idi].cijena;
            c2 = r->stavke[j].kolicina*roba[idj].cijena;
            if(c1<c2){
                RACUN_STAVKA pom = r->stavke[i];
                r->stavke[i] = r->stavke[j];
                r->stavke[j]=pom;
            }
        }
    }
}
