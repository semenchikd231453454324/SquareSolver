#include <TXLib.h>
#include <math.h>
#include <assert.h>

struct Testdata
{
    int nTest;
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected;
};

const int COEFF_COUNT = 3;
const double E = 0.000001;
const int SolveSquare_INF_ROOTS = -1;

int Test(Testdata *data);
int SolveSquare(double a, double b, double c, double* x1,double* x2);
int compare(double Num1, double Num2);
void Input (double* a, double* b, double* c);
void Output(double x1, double x2, int nRoots);
int NANCheck(double Num1, double Num2);
void AUTOTESTS();
void InputCheck ();

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    Input(&a, &b, &c);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

                                                        //3.Массив структур
    AUTOTESTS();
                                                        //Testdata* data_ptr;
                                                        //
    Output (x1, x2, nRoots);                                                    //&(*data_ptr).a === data_ptr->a;
                                                        //

    return 0;
}

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);

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

int Test(Testdata *data) //int nTest, double a, double b, double c, double x1Expected, double x2Expected, int nRootsExpected
{
    assert(data);

    double x1 = NAN , x2 = NAN;

    int nRoots = SolveSquare(data->a, data->b, data->c, &x1, &x2);

    if (NANCheck(x1, data->x1Expected) && NANCheck(x2, data->x2Expected))
    {
        if (nRoots == data->nRootsExpected)                                  // (*data).a
            return 0;
    }
    else
    {
        if (nRoots != data->nRootsExpected || !compare(x1, data->x1Expected) || !compare(x2, data->x2Expected))
        {
            printf("Error Test%d; a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, nRoots = %d\n" "Expected: x1= %lf x2 = %lf nRoots = %d\n", data->nTest, data->a, data->b, data->c, x1, x2, nRoots, data->x1Expected, data->x2Expected, data->nRootsExpected);
        }
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
    assert(a);
    assert(b);
    assert(c);

    printf ("# Enter a, b, c: \n");

    while (scanf("%lf %lf %lf", a, b, c) != COEFF_COUNT)
    {
        InputCheck ();

        printf ("Incorrect data entered, try again\n");
    }
}

void Output(double x1, double x2, int nRoots)
{
    switch (nRoots)
    {
        case 0: printf ("No Roots\n");
             break;

        case 1: printf ("x = %lg\n", x1);
             break;

        case 2: printf ("x1 = %lg x2 = %lg\n", x1, x2) ;
             break;

        case SolveSquare_INF_ROOTS: printf ("Any Number\n");
              break;

        default: printf ("Error Roots Number\n");
    }

}

int NANCheck(double Num1, double Num2)
{
    if (isnan(Num1) && isnan(Num2))
        return 1;

    return 0;
}

void AUTOTESTS()
{
    Testdata typebeats [] =
    {
        {.nTest = 0, .a = 0, .b = 0, .c = 0, .x1Expected = NAN, .x2Expected = NAN, .nRootsExpected = SolveSquare_INF_ROOTS},       //.nTest = , .a = , .b = , .c = , .x1Expected = , .x2Expected = , .nRootsExpected
        {.nTest = 1, .a = 1, .b = 2, .c = 3, .x1Expected = NAN, .x2Expected = NAN, .nRootsExpected = 0},
        {.nTest = 2, .a = 1, .b = -2, .c = 1, .x1Expected = 1, .x2Expected = 1, .nRootsExpected = 1},
        {.nTest = 3, .a = 1, .b = 0, .c = 0, .x1Expected = 0, .x2Expected = 0, .nRootsExpected = 1},
        {.nTest = 4, .a = 2, .b = -2.5, .c = -5.5, .x1Expected = 2.397181, .x2Expected = -1.147181, .nRootsExpected = 2},
        {.nTest = 5, .a = 0, .b = 1, .c = 0, .x1Expected = 0, .x2Expected = 0, .nRootsExpected = 1},
        {.nTest = 6, .a = 0, .b = 0, .c = 1, .x1Expected = NAN, .x2Expected = NAN, .nRootsExpected = 0}
    };

    int size = sizeof(typebeats) / sizeof(typebeats [0]);

    for(int i = 0; i < size; i++)
    {
        Test(&(typebeats[i]));
    }
}

void InputCheck ()
{
    while (getchar() != '\n') {}
}

