#ifndef CALCULATETIMESTEP_H_
#define CALCULATETIMESTEP_H_
#include "Cell.h"
#include "Config.h"

class CalculateTimeStep {
    public:
        static double get_dt(Cell *cells, int N);
};

#endif
