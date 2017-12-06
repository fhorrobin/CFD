#ifndef FLUX_H_
#define FLUX_H_
#include "Cell.h"

class Flux {
    public:
        static void calculateFlux (Cell *cells, int rk_step, int N);
};

#endif
