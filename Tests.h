#ifndef TESTS_H
#define TESTS_H

const int SolveSquare_INF_ROOTS = -1;

struct Testdata
{
    int nTest;
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected;
};

int Test(Testdata *data);
void AUTOTESTS();

#endif