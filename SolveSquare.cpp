#include <TXLib.h>
#include <math.h>
#include <assert.h>

#include "Input.h"
#include "NANCheck.h"
#include "compare.h"
#include "Tests.h"
#include "Output.h"
#include "SolveSquare.h"

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
                return SolveSquare_INF_ROOTS;
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

