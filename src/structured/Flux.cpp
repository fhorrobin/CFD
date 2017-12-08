#include <math.h>
#include <stdlib.h>
#include "Flux.h"
#include "Config.h"

void Flux::calculateFlux(Cell cells[][Config::NY], int rk_step) {
    double leftValue = 0;
    double rightValue = 0;
    double topValue = 0;
    double bottomValue = 0;
    double flux = 0;

    int j;
    int vertInterfaceIndex;
    int horizInterfaceIndex;

    //#pragma omp parallel for private(j) schedule(static)
    for (int i = 0; i < Config::NX; i++) {
        for (j = 0; j < Config::NY; j++) {
            cells[i][j].total_flux = 0.0;
        }
    }

    // Assuming dx, dy constant
    double dx = cells[0][0].dx;
    double dy = cells[0][0].dy;

    // Flux through the vertical edges
    #pragma omp parallel for private(vertInterfaceIndex,leftValue,rightValue,flux) schedule(static)
    for (int j = Config::NUM_GHOST_CELLS; j < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS; j++) {
        for (vertInterfaceIndex = Config::NUM_GHOST_CELLS; vertInterfaceIndex < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; vertInterfaceIndex++) {
            leftValue = cells[vertInterfaceIndex - 1][j].uEast;
            rightValue = cells[vertInterfaceIndex][j].uWest;

            // Lax-Freidrichs Scheme
            flux = 0.5 * Config::ADVECTION_VELOCITY_X * (leftValue + rightValue) 
                    - 0.5 * abs(Config::ADVECTION_VELOCITY_X) * (rightValue - leftValue);

            flux *= dy;

            cells[vertInterfaceIndex - 1][j].total_flux -= flux;
            cells[vertInterfaceIndex][j].total_flux += flux;
        }
    }

    // Flux through the horizontal edges
    #pragma omp parallel for private(horizInterfaceIndex,topValue,bottomValue,flux) schedule(static)
    for (int i = Config::NUM_GHOST_CELLS; i < Config::NUM_X_CELLS + Config::NUM_GHOST_CELLS; i++) {
        for (horizInterfaceIndex = Config::NUM_GHOST_CELLS; horizInterfaceIndex < Config::NUM_Y_CELLS + Config::NUM_GHOST_CELLS + 1; horizInterfaceIndex++) {
            topValue = cells[i][horizInterfaceIndex - 1].uNorth;
            bottomValue = cells[i][horizInterfaceIndex].uSouth;

            // Lax-Freidrichs Scheme
            flux = 0.5 * Config::ADVECTION_VELOCITY_Y * (topValue + bottomValue) 
                    - 0.5 * abs(Config::ADVECTION_VELOCITY_Y) * (bottomValue - topValue);

            flux *= dx;

            cells[i][horizInterfaceIndex - 1].total_flux -= flux;
            cells[i][horizInterfaceIndex].total_flux += flux;
        }
    }
}