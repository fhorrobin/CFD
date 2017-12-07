/**
 * Class to store variables for a cell
 */

#ifndef CELL_H_
#define CELL_H_
#include "Config.h"

class Cell {
    public:
        double u[Config::NUM_RK_STEPS + 1];
        double uWest, uEast, uNorth, uSouth;
        double cx;
        double cy;
        double dx;
        double dy;
        double total_flux;
};

#endif
