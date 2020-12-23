#include <stdio.h>
#include "vector.h"

int main() {
    VECTOR v,u;

    v = MakeVector(3,5);
    u = MakeVector(0,2);

    TulisPOINT(Substract(v,u));
    TulisPOINT(Substract(u,v));
    TulisPOINT(Add(u,v));

    return 0;
}