#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include "Output.h"

#include "Input.h"
#include "NANCheck.h"
#include "compare.h"
#include "Tests.h"
#include "Output.h"
#include "SolveSquare.h"

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

        case -1: printf ("Any Number\n");
              break;

        default: printf ("Error Roots Number\n");
    }

}


