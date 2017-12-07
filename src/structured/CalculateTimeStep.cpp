#include <math.h>
#include <stdlib.h>
#include "CalculateTimeStep.h"

double CalculateTimeStep::get_dt(Cell cells[][Config::NY]) {
    double dt1, dt2, dt = 0;

    dt1 = cells[0][0].dx / abs(Config::ADVECTION_VELOCITY_X);
    dt2 = cells[0][0].dx / abs(Config::ADVECTION_VELOCITY_Y);
    dt = 1.0 / (1.0 / dt1 + 1.0 / dt2);
    return dt * Config::COURANT_NUMBER;
}
