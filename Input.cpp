#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include "Input.h"

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


void InputCheck ()
{
    while (getchar() != '\n') {}
}
