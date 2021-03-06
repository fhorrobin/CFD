#include "VariableCopy.h"
#include "Config.h"

void VariableCopy::copyZeroRK(Cell cells[][Config::NY]) {
    int j;

    #pragma omp parallel for private(j) schedule(static)
    for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
        for (j = Config::NUM_GHOST_CELLS; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS; j++) {
            cells[i][j].u[0] = cells[i][j].u[Config::NUM_RK_STEPS]; 
        }
    }
}