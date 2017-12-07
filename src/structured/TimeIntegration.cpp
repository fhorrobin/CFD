#include <iostream>
#include "TimeIntegration.h"
#include "Config.h"

void TimeIntegration::updateCellAverages(Cell cells[][Config::NY], int rk_step, double dt) {
    // Assume dx, dy are constant
    double area = cells[0][0].dx * cells[0][0].dy;
    
    switch (Config::NUM_RK_STEPS) {
        case 1: // 1 Step RK Method
            for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
                for (int j = Config::NUM_GHOST_CELLS; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS; j++) {
                    cells[i][j].u[rk_step + 1] = cells[i][j].u[rk_step] + dt / area * cells[i][j].total_flux;
                }
            }
            break;

        case 2: // 2 Step RK Method
            for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
                for (int j = Config::NUM_GHOST_CELLS; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS; j++) {
                    switch (rk_step) {
                        case 0: // Step 0
                            cells[i][j].u[rk_step + 1] = cells[i][j].u[rk_step]
                            + dt / area * cells[i][j].total_flux;
                        break;
                        
                        case 1: // Step 1
                            cells[i][j].u[rk_step + 1]
                                = 0.5 * (cells[i][j].u[rk_step - 1]
                                + cells[i][j].u[rk_step]
                                + dt / area * cells[i][j].total_flux);
                        break;
                    }
                }
            }
        break;

        case 3: // 3 Step RK Method
            for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
                for (int j = Config::NUM_GHOST_CELLS; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS; j++) {
                    switch (rk_step) {
                        case 0: // Step 0
                            cells[i][j].u[rk_step + 1] = cells[i][j].u[rk_step]
                            + dt / area * cells[i][j].total_flux;
                        break;
                        
                        case 1: // Step 1
                            cells[i][j].u[rk_step + 1]
                                = 3.0/4.0 * cells[i][j].u[rk_step - 1]
                                + 1.0/4.0 * cells[i][j].u[rk_step]
                                + 1.0/4.0 * dt / area * cells[i][j].total_flux;
                        break;

                        case 2: // Step 1
                            cells[i][j].u[rk_step + 1]
                                = 1.0/3.0 * cells[i][j].u[rk_step - 2]
                                + 2.0/3.0 * cells[i][j].u[rk_step]
                                + 2.0/3.0 * dt / area * cells[i][j].total_flux;
                        break;
                    }
                }
            }
        break;
            
        default:
            std::cout << "Specified integrator order is not defined." << std::endl;
            throw std::logic_error("Specified integrator order is not defined.");
    }
}