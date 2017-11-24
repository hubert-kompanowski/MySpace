//Hubert Kompanowski - Obliczanie Pol i Obwodow figur.

#include <stdio.h>

void kwadrat();
void prostokat();
void trojkat ();
void kolo();

int main(void)
{
    int numer_figury;
    printf("***Jakie pole chcesz liczyc***\n");
    printf("1.Kwadrat\n");
    printf("2.Prostokat\n");
    printf("3.Trojkat\n");
    printf("4.Kolo\n");
    scanf("%d", &numer_figury);

    switch (numer_figury)
    {
        case 1:
            kwadrat();
            break;
        case 2:
            prostokat();
            break;
        case 3:
            trojkat();
            break;
        case 4:
            kolo();
            break;
        default:
            printf("Nie ma takiego numeru");
            break;
    }
}

void kwadrat()
{
    double bok_kwadratu, pole_kwadratu, obwod_kwadratu;
    printf("\nPodaj bok kwadratu: ");
    scanf("%lf", &bok_kwadratu);
    pole_kwadratu = bok_kwadratu * bok_kwadratu;
    obwod_kwadratu = 4 * bok_kwadratu;
    printf("\nPole kwadratu to: %g\n", pole_kwadratu);
    printf("Obwod kwadratu to: %g\n", obwod_kwadratu);
}

void prostokat()
{
    double bok_a, bok_b, pole_prostokata, obwod_prostokata;
    printf("\nPodaj boki prostokata: \n");
    scanf("%lf \n %lf", &bok_a, &bok_b);
    pole_prostokata = bok_a * bok_b;
    obwod_prostokata = 2*bok_a + 2*bok_b;
    printf("\nPole prostokata to: %g\n", pole_prostokata);
    printf("Obwod prostokata to: %g\n", obwod_prostokata);
}

void trojkat()
{
    double bok_a, pole_trojkata, obwod_trojkata;
    printf("\nPodaj bok trojkata rownobocznego: ");
    scanf("%lf",&bok_a);
    pole_trojkata = 0.25 * bok_a * bok_a * 1.73205;
    obwod_trojkata = 3 * bok_a;
    printf("\nPole tojkata to: %g\n", pole_trojkata);
    printf("Obwod tojkata to: %g\n", obwod_trojkata);
}

void kolo()
{
    double promien, pole_kola, obwod_kola;
    printf("\nPodaj promien kola: ");
    scanf("%lf", &promien);
    pole_kola = 3.14159 * promien * promien;
    obwod_kola = 2 * 3.14159 * promien;
    printf("\nPole kola to %g\n", pole_kola);
    printf("Obwod kola to %g\n", obwod_kola);
}
