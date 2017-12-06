#ifndef TIMEINTEGRATION_H_
#define TIMEINTEGRATION_H_
#include "Cell.h"

class TimeIntegration {
    public:
        static void updateCellAverages(Cell *cells, int rk_step, double dt);
};

#endif
