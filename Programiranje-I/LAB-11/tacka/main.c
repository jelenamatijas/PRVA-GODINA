#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Definisati tip TACKA kojim se reprezentuje tačka u x0y koordinatnom sistemu (svaka tačka ima odgovarajuću
slovnu oznaku, te dvije realne koordinate). Definisati tip TROUGAO kojim se reprezentuje trougao u x0y
koordinatnom sistemu (svaki trougao čine tri tačke koje predstavljaju vrhove trougla). Napisati program koji
sa standardnog ulaza učitava tri tačke, a zatim, ako je moguće, formira trougao te ispisuje njegov obim.
Za učitavanje tačke treba definisati i koristiti funkciju čiji je prototip:
void citaj(TACKA *);
Za provjeru da li se može formirati trougao treba definisati i koristiti funkciju čiji je prototip:
int provjera(TACKA *);
Za formiranje trougla treba definisati i koristiti funkciju čiji je prototip:
TROUGAO trougao(TACKA *);
Za računanje obima trougla definisati i koristiti funkciju čiji je prototip:
double obim(TROUGAO);*/

typedef struct tacka{
    char ime[2];
    double x,y;
}TACKA;

typedef struct trougaost{
    TACKA t1,t2,t3;
}TROUGAO;

void citaj(TACKA *);
int provjera(TACKA *);
TROUGAO trougao(TACKA *);
double obim(TROUGAO);

int main()
{
    TACKA t1,t2,t3;
    citaj(&t1);
    citaj(&t2);
    citaj(&t3);
     TACKA nizTacaka[] = {t1, t2, t3};
    if (provjera(nizTacaka)){
        TROUGAO TR = trougao(nizTacaka);
        double o = obim(TR);
        printf("Obim trougla je %.2lf.", o);
    }
    else{
        printf("Nije moguce kreirati trougao.");
    }

    return 0;
}
void citaj(TACKA *t){
    printf("Unesi slovnu oznaku za tacku: ");
    scanf("%s", &(t->ime));
    printf("Unesi koordinate tacke %s: ", t->ime);
    scanf("%lf%lf", &(t->x),&(t->y));
}
int provjera(TACKA tacke[3]){
    double d1 = sqrt(pow(tacke[0].x-tacke[1].x,2)+pow(tacke[0].y-tacke[1].y,2));
    double d2 = sqrt(pow(tacke[0].x-tacke[2].x,2)+pow(tacke[0].y-tacke[2].y,2));
    double d3 = sqrt(pow(tacke[2].x-tacke[1].x,2)+pow(tacke[2].y-tacke[1].y,2));
    if(d1+d2<=d3 || d1+d3<=d2 || d2+d3<=d1)
        return 0;
    return 1;
}
TROUGAO trougao(TACKA tacke[3]){
    TROUGAO t = {tacke[0],tacke[1], tacke[2]};
    return t;
}

double obim(TROUGAO tr){
    double d1 = sqrt(pow(tr.t1.x-tr.t2.x,2)+pow(tr.t1.y-tr.t2.y,2));
    double d2 = sqrt(pow(tr.t1.x-tr.t3.x,2)+pow(tr.t1.y-tr.t3.y,2));
    double d3 = sqrt(pow(tr.t2.x-tr.t3.x,2)+pow(tr.t2.y-tr.t3.y,2));
    return d1+d2+d3;
}

