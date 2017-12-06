#include "VariableCopy.h"
#include "Config.h"

void VariableCopy::copyZeroRK(Cell *cells, int N) {
    for (int i =0; i < N; i++) {
        cells[i].u[0] = cells[i].u[Config::NUM_RK_STEPS]; 
    }
}