#include "GhostCellUpdater.h"
#include "Config.h"

void GhostCellUpdater::updateGhostCells(Cell cells[][Config::NY], int rk_step) {
    // Left and right side of the domain
    for (int j = 0; j < Config::NY; j++) {
        for (int ghost_cell = 0; ghost_cell < Config::NUM_GHOST_CELLS; ghost_cell++) {
            cells[ghost_cell][j].u[rk_step] = cells[Config::NUM_X_CELLS + ghost_cell][j].u[rk_step];
            
            cells[Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + ghost_cell][j].u[rk_step] = 
                cells[Config::NUM_GHOST_CELLS + ghost_cell][j].u[rk_step];
        }
    }

    // Bottom and top of the domain
    for (int i = 0; i < Config::NX; i++) {
        for (int ghost_cell = 0; ghost_cell < Config::NUM_GHOST_CELLS; ghost_cell++) {
            cells[i][ghost_cell].u[rk_step] = cells[i][Config::NUM_Y_CELLS + ghost_cell].u[rk_step];
            
            cells[i][Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS + ghost_cell].u[rk_step] = 
                cells[i][Config::NUM_GHOST_CELLS + ghost_cell].u[rk_step];
        }
    }
}