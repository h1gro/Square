#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define NO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define INFINITY_ROOTS 3

int SolveSquare ( double a, double b, double c, double* x1, double* x2);
void clrbuf();

int SolveSquare ( double a, double b, double c, double* x1, double* x2)
{
        double D = 0;
        D = b * b - 4 * a * c;
        if (a == 0)
        {
            if (b == 0)
            {
                return NO_ROOTS;
                if ( c == 0 )
                {
                    return INFINITY_ROOTS;
                }
                else
                {
                    return NO_ROOTS;
                }
            }
            else
            {
                *x1 = -c / b;
                return ONE_ROOT;
            }
        }
        else
        {
            if (D >= 0)
            {
                *x1 = (-b + sqrt(D)) / (2 * a);
                *x2 = (-b - sqrt(D)) / (2 * a);
                if (*x1 == *x2)
                {
                    return ONE_ROOT;
                }
                else
                {
                    return TWO_ROOTS;
                }

            }
            else
            {
                return NO_ROOTS;
            }
        }
}
int main()
{
    int check;
    double a = 0, b = 0, c = 0;

    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("wrong input");
        clrbuf();
    }

    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare (a, b, c, &x1, &x2);

    switch(nRoots)
    {
    case NO_ROOTS: printf("no roots\n");
            break;
    case ONE_ROOT: printf("%lg\n", x1);
            break;
    case TWO_ROOTS: printf("%lg %lg\n", x1, x2);
            break;
    case INFINITY_ROOTS: printf("any number");
            break;
    }
}

void clrbuf()
{

    printf("вошёл в функцию");
    int ch = getchar();
    while (ch != EOF && ch != '\n' )
    {
        printf("я выкинул символ, (%c), %d\n", ch, ch);
        ch = getchar();
    }
    printf("вышел из функции");
}
