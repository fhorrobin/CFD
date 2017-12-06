#include "VariableReconstructor.h"
#include "Config.h"

void VariableReconstructor::ReconstructVariables (Cell *cells, int rk_step) {
    for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
        cells[i].uWest = cells[i].u[rk_step];
        cells[i].uEast = cells[i].u[rk_step];
    }
}