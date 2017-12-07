#ifndef FLUX_H_
#define FLUX_H_
#include "Cell.h"

class Flux {
    public:
        static void calculateFlux (Cell cells[][Config::NY], int rk_step);
};

#endif
