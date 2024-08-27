#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include "compare.h"

#include "Input.h"
#include "NANCheck.h"
#include "compare.h"
#include "Tests.h"
#include "Output.h"
#include "SolveSquare.h"

int compare(double Num1, double Num2)
{
    if (fabs(Num1 - Num2) < E)
        return 1;

    return 0;
}