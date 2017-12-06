#include <math.h>
#include "Flux.h"
#include "Config.h"

void FLux::calculateFlux(Cell *cells, int rk_step, int N) {
    double leftValue = 0;
    double rightValue = 0;
    double flux = 0;

    for (int i = 0; i < N; i++) {
        cells[i].total_flux = 0.0;
    }

    for (int interfaceIndex = Config::NUM_GHOST_CELLS; interfaceIndex < Confi::NUM_X_CELLS + Config::NUM_GHOST_CELLS + 1; interfaceIndex++) {
        leftValue = cells[interfaceIndex - 1].uEast;
        rightValue = cells[interfaceIndex + 1].uWest;

        // Lax-Freidrichs Scheme
        flux = 0.5 * Config::ADVECTION_VELOCITY * (leftValue + rightValue) 
                - 0.5 * abs(Config::ADVECTION_VELOCITY) * (rightValue - leftValue);

        cells[interfaceIndex - 1].total_flux -= flux;
        cells[interfaceIndex].total_flux += flux;

    }
}