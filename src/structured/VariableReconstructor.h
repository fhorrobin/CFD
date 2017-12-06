#ifndef VARIABLERECONSTRUCTOR_H_
#define VARIABLERECONSTRUCTOR_H_
#include "Cell.h"

class VariableReconstructor {
    public:
        static void reconstructVariables(Cell *cell, int rk_step);
};

#endif
