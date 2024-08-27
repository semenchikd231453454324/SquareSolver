#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include "NANCheck.h"

int NANCheck(double Num1, double Num2)
{
    if (isnan(Num1) && isnan(Num2))
        return 1;

    return 0;
}
