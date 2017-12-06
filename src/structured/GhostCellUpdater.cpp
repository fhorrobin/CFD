#include "GhostCellUpdater.h"
#include "Config.h"

void GhostCellUpdater::updateGhostCells(Cell *cells, int rk_step) {
    for (int ghost_cell = 0; ghost_cell < Config::NUM_GHOST_CELLS; ghost_cell++) {
        cells[ghost_cell].u[rk_step] = cells[Config::NUM_X_CELLS + ghost_cell].u[rk_step];
        
        cells[Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + ghost_cell].u[rk_step] = 
            cells[Config::NUM_GHOST_CELLS + ghost_cell].u[rk_step];
    }
}