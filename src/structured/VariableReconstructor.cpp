#include <iostream>
#include <algorithm> 
#include "VariableReconstructor.h"
#include "Config.h"

void VariableReconstructor::reconstructVariables(Cell cells[][Config::NY], int rk_step) {
    const double eps = 1e-6;
    double du_dx = 0;
    double r = 0;
    double phi = 0;
    
    switch (Config::RECONST_TYPE) {
        case FIRST_ORDER:
            for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
                for (int j = Config::NUM_GHOST_CELLS - 1; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS + 1; j++) {
                    cells[i][j].uWest = cells[i][j].u[rk_step];
                    cells[i][j].uEast = cells[i][j].u[rk_step];
                    cells[i][j].uNorth = cells[i][j].u[rk_step];
                    cells[i][j].uSouth = cells[i][j].u[rk_step];
                }
            }
        break;

        // case BEAM_WARMING:
        //     for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
        //         du_dx = (cells[i].u[rk_step] - cells[i-1].u[rk_step]) / cells[i].dx;
                
        //         cells[i].uWest = cells[i].u[rk_step] - du_dx * cells[i].dx / 2.0;
        //         cells[i].uEast = cells[i].u[rk_step] + du_dx * cells[i].dx / 2.0;
        //     }
        // break;

        // case LAX_WENDROFF:
        //     for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
        //         du_dx = (cells[i+1].u[rk_step] - cells[i].u[rk_step]) / cells[i].dx;
                
        //         cells[i].uWest = cells[i].u[rk_step] - du_dx * cells[i].dx / 2.0;
        //         cells[i].uEast = cells[i].u[rk_step] + du_dx * cells[i].dx / 2.0;
        //     }
        // break;

        // case FROMM:
        //     for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
        //         du_dx = (cells[i+1].u[rk_step] - cells[i-1].u[rk_step]) / (2.0 * cells[i].dx);
                
        //         cells[i].uWest = cells[i].u[rk_step] - du_dx * cells[i].dx / 2.0;
        //         cells[i].uEast = cells[i].u[rk_step] + du_dx * cells[i].dx / 2.0;
        //     }
        // break;

        // case LIMITED_LW:
        //     for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
        //         // Limiter Parameter
        //         r = (cells[i].u[rk_step] - cells[i-1].u[rk_step]) / (cells[i+1].u[rk_step] - cells[i].u[rk_step] + eps);
        //         r = std::max(0.0, r);

        //         // Limiter Value
        //         phi = (r*r + r) / (r*r + 1.0);

        //         du_dx = (cells[i+1].u[rk_step] - cells[i].u[rk_step]) / cells[i].dx;                
        //         cells[i].uWest = cells[i].u[rk_step] - phi * du_dx * cells[i].dx / 2.0;
        //         cells[i].uEast = cells[i].u[rk_step] + phi * du_dx * cells[i].dx / 2.0;
        //     }
        // break;

         default:
            std::cout << "Specified reconstruction type is not defined." << std::endl;
            throw std::logic_error("Specified reconstruction type is not defined.");
    }
}