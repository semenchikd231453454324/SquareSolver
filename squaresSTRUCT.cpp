#include <TXLib.h>
#include <math.h>
#include <assert.h>

#include "Input.h"
#include "NANCheck.h"
#include "compare.h"
#include "Tests.h"
#include "Output.h"
#include "SolveSquare.h"


int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    Input(&a, &b, &c);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

                                                      
    AUTOTESTS();
                                                        //Testdata* data_ptr;
                                                        //
    Output (x1, x2, nRoots);                                                    //&(*data_ptr).a === data_ptr->a;
                                                        //

    return 0;
}






