#ifndef VARIABLERECONSTRUCTOR_H_
#define VARIABLERECONSTRUCTOR_H_
#include "Cell.h"

class VariableReconstructor {
    public:
        static void reconstructVariables(Cell cell[][Config::NY], int rk_step);
};

#endif
