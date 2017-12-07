#include <iostream>
#include <algorithm> 
#include "VariableReconstructor.h"
#include "Config.h"

void VariableReconstructor::reconstructVariables(Cell cells[][Config::NY], int rk_step) {
    const double eps = 1e-12;
    double du_dx, du_dy = 0;
    double r_x, r_y = 0;
    double phi_x, phi_y = 0;
    
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

        case BEAM_WARMING:
            for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
                for (int j = Config::NUM_GHOST_CELLS - 1; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS + 1; j++) {
                    du_dx = (cells[i][j].u[rk_step] - cells[i-1][j].u[rk_step]) / cells[i][j].dx;
                    du_dy = (cells[i][j].u[rk_step] - cells[i][j-1].u[rk_step]) / cells[i][j].dy;

                    cells[i][j].uWest = cells[i][j].u[rk_step] - du_dx * cells[i][j].dx / 2.0;
                    cells[i][j].uEast = cells[i][j].u[rk_step] + du_dx * cells[i][j].dx / 2.0;

                    cells[i][j].uSouth = cells[i][j].u[rk_step] - du_dy * cells[i][j].dy / 2.0;
                    cells[i][j].uNorth = cells[i][j].u[rk_step] + du_dy * cells[i][j].dy / 2.0;
                }
            }
        break;

        case LAX_WENDROFF:
            for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
                for (int j = Config::NUM_GHOST_CELLS - 1; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS + 1; j++) {
                    du_dx = (cells[i + 1][j].u[rk_step] - cells[i][j].u[rk_step]) / cells[i][j].dx;
                    du_dy = (cells[i][j + 1].u[rk_step] - cells[i][j].u[rk_step]) / cells[i][j].dy;

                    cells[i][j].uWest = cells[i][j].u[rk_step] - du_dx * cells[i][j].dx / 2.0;
                    cells[i][j].uEast = cells[i][j].u[rk_step] + du_dx * cells[i][j].dx / 2.0;

                    cells[i][j].uSouth = cells[i][j].u[rk_step] - du_dy * cells[i][j].dy / 2.0;
                    cells[i][j].uNorth = cells[i][j].u[rk_step] + du_dy * cells[i][j].dy / 2.0;
                }
            }
        break;

        case FROMM:
            for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
                for (int j = Config::NUM_GHOST_CELLS - 1; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS + 1; j++) {
                    du_dx = (cells[i + 1][j].u[rk_step] - cells[i - 1][j].u[rk_step]) / (2.0 * cells[i][j].dx);
                    du_dy = (cells[i][j + 1].u[rk_step] - cells[i][j - 1].u[rk_step]) / (2.0 * cells[i][j].dy);

                    cells[i][j].uWest = cells[i][j].u[rk_step] - du_dx * cells[i][j].dx / 2.0;
                    cells[i][j].uEast = cells[i][j].u[rk_step] + du_dx * cells[i][j].dx / 2.0;

                    cells[i][j].uSouth = cells[i][j].u[rk_step] - du_dy * cells[i][j].dy / 2.0;
                    cells[i][j].uNorth = cells[i][j].u[rk_step] + du_dy * cells[i][j].dy / 2.0;
                }
            }
        break;

        case LIMITED_LW:
            for (int i = Config::NUM_GHOST_CELLS - 1; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; i++) {
                for (int j = Config::NUM_GHOST_CELLS - 1; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS + 1; j++) {
                    // X Limiter Parameter
                    r_x = (cells[i][j].u[rk_step] - cells[i-1][j].u[rk_step]) / (cells[i+1][j].u[rk_step] - cells[i][j].u[rk_step] + eps);
                    r_x = std::max(0.0, r_x);

                    // Limiter Value
                    phi_x = (r_x*r_x + r_x) / (r_x*r_x + 1.0);

                    // Y Limiter Parameter
                    r_y = (cells[i][j].u[rk_step] - cells[i][j-1].u[rk_step]) / (cells[i][j+1].u[rk_step] - cells[i][j].u[rk_step] + eps);
                    r_y = std::max(0.0, r_y);

                    // Limiter Value
                    phi_y = (r_y*r_y + r_y) / (r_y*r_y + 1.0);

                    du_dx = (cells[i+1][j].u[rk_step] - cells[i][j].u[rk_step]) / cells[i][j].dx;
                    du_dy = (cells[i][j + 1].u[rk_step] - cells[i][j].u[rk_step]) / cells[i][j].dy;

                    cells[i][j].uWest = cells[i][j].u[rk_step] - phi_x * du_dx * cells[i][j].dx / 2.0;
                    cells[i][j].uEast = cells[i][j].u[rk_step] + phi_x * du_dx * cells[i][j].dx / 2.0;

                    cells[i][j].uSouth = cells[i][j].u[rk_step] - phi_y * du_dy * cells[i][j].dy / 2.0;
                    cells[i][j].uNorth = cells[i][j].u[rk_step] + phi_y * du_dy * cells[i][j].dy / 2.0;
                }
            }
        break;

         default:
            std::cout << "Specified reconstruction type is not defined." << std::endl;
            throw std::logic_error("Specified reconstruction type is not defined.");
    }
}