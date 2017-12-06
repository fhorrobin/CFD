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

int main() {
    const int N = Config::NUM_X_CELLS + 2 * Config::NUM_GHOST_CELLS;
    const double dx = (Config::MAX_X - Config::MIN_X) / Config::NUM_X_CELLS;
    
    int counter = 0;
    double time = 0.0;
    bool last_dt = false;

    double dt = 0;

    Cell cells[N];

    /**** Initial conditions ****/
    for (int i = 0; i < N; i++) {
        cells[i].dx = dx;
        cells[i].cx = Config::MIN_X  + dx * (i + 0.5 - Config::NUM_GHOST_CELLS);
    }

    Initialize::initialize_solution(cells, N);


    /**** Start solving ****/
    WriteFile::write_file(cells, N, 0.0, counter);
    counter += 1;

    for (int it = 0; it < Config::MAX_TIME_ITER; it++) {
        dt = CalculateTimeStep::get_dt(cells, N);

        // Check if we are at the last step
        if (time + dt > Config::STOPPING_TIME) {
            dt = Config::STOPPING_TIME - time;
            last_dt = true;
        }

        for (int rk_step = 0; rk_step < Config::NUM_RK_STEPS; rk_step++) {
            GhostCellUpdater::updateGhostCells(cells, rk_step);
            VariableReconstructor::reconstructVariables(cells, rk_step);
            Flux::calculateFlux(cells, rk_step, N);
        }

        time += dt;
        if (last_dt) {
            break;
        }
    }
}
