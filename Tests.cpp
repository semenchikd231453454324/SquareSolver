#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include "Tests.h"

#include "Input.h"
#include "NANCheck.h"
#include "compare.h"
#include "Tests.h"
#include "Output.h"
#include "SolveSquare.h"

int Test(Testdata *data)
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

void AUTOTESTS()
{
    Testdata typebeats [] =
    {
        {.nTest = 0, .a = 0, .b = 0, .c = 0, .x1Expected = NAN, .x2Expected = NAN, .nRootsExpected = -1},       //.nTest = , .a = , .b = , .c = , .x1Expected = , .x2Expected = , .nRootsExpected
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