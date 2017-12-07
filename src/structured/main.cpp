/**
 * A simple Finite Element CFD code.
 */
#include <iostream>
#include <math.h>
#include "Config.h"
#include "Cell.h"
#include "Initialize.h"
#include "WriteFile.h"
#include "CalculateTimeStep.h"
#include "GhostCellUpdater.h"
#include "VariableReconstructor.h"
#include "Flux.h"
#include "TimeIntegration.h"
#include "VariableCopy.h"

int main() {
    const double dx = (Config::MAX_X - Config::MIN_X) / Config::NUM_X_CELLS;
    const double dy = (Config::MAX_Y - Config::MIN_Y) / Config::NUM_Y_CELLS;
    
    int counter = 0;
    double time = 0.0;
    bool last_dt = false;

    double dt = 0;

    Cell cells[Config::NX][Config::NY];


    /**** Initial conditions ****/
    for (int i = 0; i < Config::NX; i++) {
        for (int j = 0; j < Config::NY; j++) {
            cells[i][j].dx = dx;
            cells[i][j].dy = dy;
            cells[i][j].cx = Config::MIN_X  + dx * (i + 0.5 - Config::NUM_GHOST_CELLS);
            cells[i][j].cx = Config::MIN_Y  + dy * (j + 0.5 - Config::NUM_GHOST_CELLS);
        }
    }

    Initialize::initialize_solution(cells, Config::NX, Config::NY);

    /**** Start solving ****/
    WriteFile::write_file(cells, Config::NX, Config::NY, 0.0, counter);
    counter += 1;

    // for (int it = 0; it < Config::MAX_TIME_ITER; it++) {
    //     dt = CalculateTimeStep::get_dt(cells, N);

    //     // Check if we are at the last step
    //     if (time + dt > Config::STOPPING_TIME) {
    //         dt = Config::STOPPING_TIME - time;
    //         last_dt = true;
    //     }

    //     for (int rk_step = 0; rk_step < Config::NUM_RK_STEPS; rk_step++) {
    //         GhostCellUpdater::updateGhostCells(cells, rk_step);
    //         VariableReconstructor::reconstructVariables(cells, rk_step);
    //         Flux::calculateFlux(cells, rk_step, N);
    //         TimeIntegration::updateCellAverages(cells, rk_step, dt);
    //     }

    //     VariableCopy::copyZeroRK(cells);

    //     time += dt;
    //     if (last_dt) {
    //         break;
    //     }

    //     // Write output every 5 dt
    //     if ((it + 1) % 5 == 0) {
    //         WriteFile::write_file(cells, N, time, counter);
    //         counter += 1;
    //     }
    // }

    // WriteFile::write_file(cells, N, time, counter);
    // counter += 1;
}
