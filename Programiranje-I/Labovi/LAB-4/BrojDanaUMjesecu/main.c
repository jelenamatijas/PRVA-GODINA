#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mjesec, godina;
    printf("Unesi mjesec i godinu (brojem): ");
    scanf("%d%d", &mjesec, &godina);
    switch(mjesec)
    {
    case 2:
        if(godina%4==0 && godina%100!=0 || godina%400 == 0)
        {
            printf("Mjesec FEBRUAR %d. godine ima 29 dana.", godina);
        }
        else
        {
            printf("Mjesec FEBRUAR %d. godine ima 28 dana.", godina);
        }
        break;
    case 1:
        printf("Mjesec JANUAR &d. godine ima 31 dana.", godina);
        break;
    case 3:
        printf("Mjesec MART %d. godine ima 31 dana.", godina);
        break;
    case 4:
        printf("Mjesec APRIL %d. godine ima 30 dana.", godina);
        break;
    case 5:
        printf("Mjesec MAJ %d. godine ima 31 dana.", godina);
        break;
    case 6:
        printf("Mjesec JUN %d. godine ima 30 dana.", godina);
        break;
    case 7:
        printf("Mjesec JUL %d. godine ima 31 dana.", godina);
        break;
    case 8:
        printf("Mjesec AVGUST %d. godine ima 31 dana.", godina);
        break;
    case 9:
        printf("Mjesec SEPTEMBAR %d. godine ima 30 dana.", godina);
        break;
    case 10:
        printf("Mjesec OKTOBAR %d. godine ima 31 dana.", godina);
        break;
    case 11:
        printf("Mjesec NOVEMBAR %d. godine ima 30 dana.", godina);
        break;
    case 12:
        printf("Mjesec DECEMBAR %d. godine ima 31 dana.", godina);
        break;
    default:
        printf("Pogresan unos.");
    }
    return 0;
}
