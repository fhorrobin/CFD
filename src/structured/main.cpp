/**
 * A simple Finite Element CFD code.
 */
#include <iostream>
#include <math.h>
#include "Config.h"
#include "Cell.h"
#include "Initialize.h"
#include "WriteFile.h"

int main() {
    const int N = Config::NUM_X_CELLS + 2 * Config::NUM_GHOST_CELLS;
    const double dx = (Config::MAX_X - Config::MIN_X) / Config::NUM_X_CELLS;
    int counter = 0;
    Cell cells[N];

    for (int i = 0; i < N; i++) {
        // Initializing the constant values for the class
        cells[i].dx = dx;
        cells[i].cx = Config::MIN_X  + dx * (i + 0.5 - Config::NUM_GHOST_CELLS);
    }

    Initialize::initialize_solution(cells, N);
    WriteFile::write_file(cells, N, 0.0, counter);

    counter += 1;
}
