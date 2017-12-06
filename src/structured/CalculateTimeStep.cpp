#include <math.h>
#include "CaulculateTimeStep.h"

double CaulculateTimeStep::get_dt(Cell *cells, int N) {
    // Assuming that dx is a constant 
    return cells[0].dx / abs(Config::ADVECTION_VELOCITY) * Config::COURANT_NUMBER;
}
