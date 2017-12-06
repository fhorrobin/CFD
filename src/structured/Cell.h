/**
 * Class to store variables for a cell
 */
#include "Config.h"
class Cell {
    public:
        double u[Config::NUM_RK_STEPS + 1];
        double uWest, uEast;
        double cx;
        double dx;
};