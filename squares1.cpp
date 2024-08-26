#include <TXLib.h>
#include <math.h>
#include <assert.h>

//struct Testdata
//{}

const int COEFF_COUNT = 3;
const double E = 0.00000001;

int Tests(int nTest, double a, double b, double c, double x1Expected, double x2Expected, int nRootsExpected);
int SolveSquare(double a, double b, double c, double* x1,double* x2);
int compare(double Num1, double Num2);
void Input (double* a, double* b, double* c);
void Output(double x1, double x2, int nRoots);
int NANCHECK(double Num1, double Num2);

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 =NAN, x2 = NAN;

    Input(&a, &b, &c);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    //Tests(1, 1, 2, 3, NAN, NAN, 0);

    Output (x1, x2, nRoots);

    return 0;
}

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    if (compare (a, 0))
    {
        if (compare (b, 0))
        {
            if (compare (c, 0))
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (compare (c, 0))
            {
                *x1 = 0;
                *x2 = 0;
                return 1;
            }
            else
            {
                *x1 = -c/b;
                return 1;
            }
        }
    }
    else
    {
        double d = b*b - 4*a*c;
        double doubled_a = 2*a;

        if (compare(d, 0))
        {
            *x1 = -b / doubled_a ;
            *x2 = *x1;

            return 1;
        }
        else if (d > 0)
        {
            double sqrt_d = sqrt(d);

            *x1 = (-b + sqrt_d) / doubled_a;
            *x2 = (-b - sqrt_d) / doubled_a;

            return 2;
        }
        else
        {
            *x1 = *x2 = NAN;
            return 0;
        }
    }
}

int Tests(int nTest, double a, double b, double c, double x1Expected, double x2Expected, int nRootsExpected)
{
    double x1 = NAN , x2 = NAN;

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    if (x1Expected == NAN || x2Expected == NAN)
    {
        if (NANCHECK(x1, x1Expected))
        {

        }

        NANCHECK(x2, x2Expected);
    }

    if (nRoots != nRootsExpected || !compare(x1, x1Expected) || !compare(x2, x2Expected))
    {
        printf("Error Test%d; a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, nRoots = %d\n" "Expected: x1= %lf x2 = %lf nRoots = %d\n", nTest, a, b, c, x1, x2, nRoots, x1Expected, x2Expected, nRootsExpected);
    }
    return 0;
}

int compare(double Num1, double Num2)
{
    if (fabs(Num1 - Num2) < E)
        return 1;

    return 0;
}

void Input (double* a, double* b, double* c)
{
    printf ("# Enter a, b, c: \n");

    assert(a);
    assert(b);
    assert(c);

    while (scanf("%lf %lf %lf", a, b, c) != COEFF_COUNT)
    {
        while (getchar() != '\n') {}

        printf ("Incorrect data entered, try again\n");
    }
}

void Output(double x1, double x2, int nRoots)
{
    switch (nRoots)
    {
        case 0: printf ("No Roots\n");
             break;

        case 1: printf ("x = %lf\n", x1);
             break;

        case 2: printf ("x1 = %lf x2 = %lf\n", x1, x2) ;
             break;

        case -1: printf ("Any Number\n");     //SS_INF_ROOTS
              break;

        default: printf ("Error Roots Number\n");
    }

}

int NANCHECK(double Num1, double Num2)
{
    if (Num1 == NAN && Num2 == NAN)
        return 1;

    return 0;
}
