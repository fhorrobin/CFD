#include <iostream>
#include "TimeIntegration.h"
#include "Config.h"

void TimeIntegration::updateCellAverages(Cell *cells, int rk_step, double dt) {
    switch (Config::NUM_RK_STEPS) {
        case 1: // 1 Step RK Method
            for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
                cells[i].u[rk_step + 1] = cells[i].u[rk_step] + dt / cells[i].dx * cells[i].total_flux;
            }
            break;

        case 2: // 2 Step RK Method
            for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
                switch (rk_step) {
                    case 0: // Step 0
                        cells[i].u[rk_step + 1] = cells[i].u[rk_step]
                        + dt / cells[i].dx * cells[i].total_flux;
                    break;
                    
                    case 1: // Step 1
                        cells[i].u[rk_step + 1]
                            = 0.5 * (cells[i].u[rk_step -1]
                            + cells[i].u[rk_step]
                            + dt / cells[i].dx * cells[i].total_flux);
                    break;
                }
            }
            break;
            
        default:
            std::cout << "Specified integrator order is not defined." << std::endl;
            throw std::logic_error("Specified integrator order is not defined.");
    }
}