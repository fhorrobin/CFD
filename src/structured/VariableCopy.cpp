#include "VariableCopy.h"
#include "Config.h"

void VariableCopy::copyZeroRK(Cell *cells) {
    for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
        cells[i].u[0] = cells[i].u[Config::NUM_RK_STEPS]; 
    }
}