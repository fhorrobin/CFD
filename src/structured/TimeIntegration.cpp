#include "TimeIntegration.h"
#include "Config.h"

void TimeIntegration::updateCellAverages(Cell *cells, int rk_step, double dt) {
    for (int i = Config::NUM_GHOST_CELLS, i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
        cells[i].u[rk_step + 1] = cells[i].u[rk_step] + dt / cells[i].dx * cells[i].total_flux;
    }
}