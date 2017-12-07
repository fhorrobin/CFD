#include <iostream>
#include <fstream>
#include <string>
#include "WriteFile.h"
#include "Config.h"
#include "Cell.h"

void WriteFile::write_file (Cell cells[][Config::NY], int NX, int NY, double time, int counter) {
    std::string path = "./output/";
    const int rk_step = 0;

    const int n_zero = 4;
    std::string counter_string = std::to_string(counter);
    counter_string = std::string(n_zero - counter_string.length(), '0') + counter_string;

    std::ofstream file;
    file.open(path + "output_" + counter_string +  ".dat");

    file << "NumXCells: " << Config::NUM_X_CELLS << std::endl;
    file << "NumYCells: " << Config::NUM_Y_CELLS << std::endl;
    file << "NumGhostCells: " << Config::NUM_GHOST_CELLS << std::endl;
    file << "Time: " << time << std::endl;
    file << "CFL: " << Config::COURANT_NUMBER << std::endl;

    // Write the cells
    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            file << cells[i][j].cx << " " << cells[i][j].cy << " " << cells[i][j].u[rk_step] << std::endl;
        }
    }

}